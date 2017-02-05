#include "stdafx.h"
#include "Driver.h"
#include "Scanner.h"
#include <sstream>

yy::Driver::Driver()
    :resultValue(0)
{
}

yy::Driver::~Driver()
{
}

bool yy::Driver::parseStream(std::istream &inStream)
{
    scanner = &Scanner(inStream);
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
    std::cout << "Error: " << msg << std::endl;
}