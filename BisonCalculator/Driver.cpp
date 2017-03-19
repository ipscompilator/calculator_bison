#include "stdafx.h"
#include "Driver.h"
#include "Scanner.h"
#include "CalcNode.h"
#include "StatementNode.h"
#include "StringPool.h"
#include "CalcContext.h"

using namespace calc;

Driver::Driver(std::shared_ptr<IOutputContext> context)
	: m_outputContext(context)
{
	m_calcContext = std::make_shared<CalcContext>(m_stringPool, context);
}

Driver::~Driver()
{
}

double Driver::GetResultValue() const
{
	if (m_calcNode)
	{
		return m_calcNode->Evaluate(*m_calcContext);
	}
	else
	{
		return 0;
	}
}

calc::Scanner & Driver::GetScanner() const
{
	return *m_scanner;
}

bool Driver::ParseStream(std::istream & inStream)
{
	m_scanner = std::make_unique<Scanner>(inStream, m_stringPool);
	Parser parser(*this);
	return (parser.parse() == 0);
}

bool Driver::ParseString(const std::string & inString)
{
	std::istringstream iss(inString);
	return ParseStream(iss);
}

void Driver::Error(const std::string & msg, const location & location)
{
	m_outputContext->ReportIssue(msg, location);
}

void Driver::PrintResult()
{
	if (m_calcNode)
	{
		m_outputContext->PrintResult(m_calcNode->Evaluate(*m_calcContext));
	}
}

CalcNode & Driver::GetCalcNode() const
{
	return *m_calcNode;
}

void Driver::SetCalcNode(std::unique_ptr<CalcNode> && calcNode)
{
	m_calcNode = move(calcNode);
	PrintResult();
}

void calc::Driver::AddStatement(StatementPtr && statementNode)
{
	if (statementNode)
	{
		statementNode->Execute(*m_calcContext);
		m_statements.push_back(move(statementNode));
	}
}
