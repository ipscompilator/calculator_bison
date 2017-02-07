#include "stdafx.h"
#include "Driver.h"
#include "Scanner.h"
#include <sstream>

yy::Driver::Driver()
    :m_resultValue(0)
{
}

yy::Driver::~Driver()
{
}

double yy::Driver::getResultValue() const
{
    return m_resultValue;
}

void yy::Driver::setResultValue(double resultValue)
{
    m_resultValue = resultValue;
    std::cout << "Result: " << resultValue << std::endl;
}

yy::Scanner &yy::Driver::getScanner() const
{
    return *m_scanner;
}

bool yy::Driver::parseStream(std::istream &inStream)
{
    m_scanner = std::make_unique<Scanner>(inStream);
    yy::Parser parser(*this);
    return (parser.parse() == 0);
}

bool yy::Driver::parseString(const std::string &inString)
{
    std::istringstream iss(inString);
    return parseStream(iss);
}

void yy::Driver::error(const std::string &msg)
{
    std::cerr << "Error: " << msg << std::endl;
}