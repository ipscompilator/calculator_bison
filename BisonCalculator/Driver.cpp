#include "stdafx.h"
#include "Driver.h"
#include "Scanner.h"
#include "ICalcNode.h"
#include "IStatementNode.h"
#include "StringPool.h"
#include "CalcContext.h"
#include "PrintVisitor.h"

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

void Driver::PrintProgram()
{
	cout << endl << "--------- Check AST -----------" << endl;
	if (m_program.GetStatementsCount() == 0)
	{
		cout << "No statements" << endl;
	}
	else
	{
		PrintVisitor visitor(cout, m_stringPool);
		visitor.Visit(m_program);
		cout << "-----------------------------------" << endl;
	}
}

Parser::token_type Driver::Advance(Parser::semantic_type * val, Parser::location_type * loc)
{
	return m_scanner->Lex(val, loc);
}

void Driver::AddStatement(StatementPtr && statementNode)
{
	if (statementNode)
	{
		statementNode->Execute(*m_calcContext);
		m_program.AddStatement(move(statementNode));
	}
}
