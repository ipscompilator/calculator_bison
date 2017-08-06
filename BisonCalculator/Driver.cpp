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

void Driver::PrintProgram(std::vector<std::unique_ptr<IStatementNode>>& statements)
{
	for (int i = 0; i < statements.size(); i++)
	{
		m_program.AddStatement(std::move(statements.at(i)));
	}

	cout << endl << "--------- Check AST -----------" << endl;
	if (m_program.GetStatementsCount() == 0)
	{
		cout << "No statements" << endl;
	}
	else
	{
		PrintVisitor visitor(cout, m_stringPool);
		visitor.Visit(m_program, 0);
		cout << "-------------------------------" << endl;
	}
}

Parser::token_type Driver::Advance(Parser::semantic_type * val, Parser::location_type * loc)
{
	return m_scanner->Lex(val, loc);
}
