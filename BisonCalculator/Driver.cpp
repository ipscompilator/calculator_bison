#include "stdafx.h"
#include "Driver.h"
#include "Scanner.h"
#include <sstream>

calc::Driver::Driver()
    :m_resultValue(0)
{
}

calc::Driver::~Driver()
{
}

double calc::Driver::getResultValue() const
{
    return m_resultValue;
}

void calc::Driver::setResultValue(double resultValue)
{
    m_resultValue = resultValue;
    std::cout << "Result: " << resultValue << std::endl;
}

calc::Scanner &calc::Driver::getScanner() const
{
    return *m_scanner;
}

bool calc::Driver::parseStream(std::istream &inStream)
{
    m_scanner = std::make_unique<Scanner>(inStream);
    calc::Parser parser(*this);
    return (parser.parse() == 0);
}

bool calc::Driver::parseString(const std::string &inString)
{
    std::istringstream iss(inString);
    return parseStream(iss);
}

void calc::Driver::error(const std::string &msg)
{
    std::cerr << "Error: " << msg << std::endl;
}