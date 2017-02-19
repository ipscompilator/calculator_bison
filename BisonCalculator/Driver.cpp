#include "stdafx.h"
#include "Driver.h"
#include "Scanner.h"
#include <sstream>

calc::Driver::Driver()
{
}

calc::Driver::~Driver()
{
}

double calc::Driver::getResultValue() const
{
    return m_calcNode->Evaluate();
}

calc::Scanner & calc::Driver::getScanner() const
{
    return *m_scanner;
}

bool calc::Driver::parseStream(std::istream & inStream)
{
    m_scanner = std::make_unique<Scanner>(inStream);
    calc::Parser parser(*this);
    return (parser.parse() == 0);
}

bool calc::Driver::parseString(const std::string & inString)
{
    std::istringstream iss(inString);
    return parseStream(iss);
}

void calc::Driver::error(const std::string & msg, const location & location)
{
	std::cerr << "{" << location << "} Error: " << msg << std::endl;
}

void calc::Driver::printResult()
{
    std::cout << "Node result: " << m_calcNode->Evaluate() << std::endl;
}

calc::CalcNode & calc::Driver::getCalcNode() const
{
    return *m_calcNode;
}

void calc::Driver::setCalcNode(std::unique_ptr<CalcNode> && calcNode)
{
    m_calcNode = move(calcNode);
    printResult();
}