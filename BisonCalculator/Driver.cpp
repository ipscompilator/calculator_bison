#include "stdafx.h"
#include "Driver.h"
#include "Scanner.h"
#include <sstream>

using namespace calc;

Driver::Driver(std::shared_ptr<IContext> context)
	: m_context(context)
{
}

Driver::~Driver()
{
}

double Driver::getResultValue() const
{
	if (m_calcNode)
	{
		return m_calcNode->Evaluate();
	}
	else
	{
		return 0;
	}
}

Scanner & Driver::getScanner() const
{
	return *m_scanner;
}

bool Driver::parseStream(std::istream & inStream)
{
	m_scanner = std::make_unique<Scanner>(inStream);
	Parser parser(*this);
	return (parser.parse() == 0);
}

bool Driver::parseString(const std::string & inString)
{
	std::istringstream iss(inString);
	return parseStream(iss);
}

void Driver::error(const std::string & msg, const location & location)
{
	m_context->ReportIssue(msg, location);
}

void Driver::printResult()
{
	if (m_calcNode)
	{
		m_context->PrintResult(m_calcNode->Evaluate());
	}
}

CalcNode & Driver::getCalcNode() const
{
	return *m_calcNode;
}

void Driver::setCalcNode(std::unique_ptr<CalcNode> && calcNode)
{
	m_calcNode = move(calcNode);
	printResult();
}