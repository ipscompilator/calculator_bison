#include "stdafx.h"
#include "Driver.h"
#include "Scanner.h"
#include "ICalcNode.h"
#include "IStatementNode.h"
#include "StringPool.h"
#include "CalcContext.h"

using namespace calc;
using namespace std;

Driver::Driver(OutputContextPtr context)
	: m_outputContext(context)
{
	m_calcContext = make_shared<CalcContext>(m_stringPool, context);
}

Driver::~Driver()
{
}

Scanner & Driver::GetScanner() const
{
	return *m_scanner;
}

bool Driver::ParseStream(istream & inStream)
{
	m_scanner = make_unique<Scanner>(inStream, m_stringPool);
	Parser parser(*this);
	return (parser.parse() == 0);
}

bool Driver::ParseString(const string & inString)
{
	istringstream iss(inString);
	return ParseStream(iss);
}

void Driver::Error(const string & msg, const location & location)
{
	m_outputContext->ReportIssue(msg, location);
}

void Driver::AddStatement(StatementPtr && statementNode)
{
	if (statementNode)
	{
		statementNode->Execute(*m_calcContext);
		m_statements.push_back(move(statementNode));
	}
}
