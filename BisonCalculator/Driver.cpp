#include "Driver.h"
#include "Scanner.h"
#include <sstream>

yy::Driver::Driver()
{
}

yy::Driver::~Driver()
{
}

bool yy::Driver::parseStream(std::istream &inStream)
{
    Scanner scanner(inStream);
    yy::Parser parser(scanner);
    return (parser.parse() == 0);
}

bool yy::Driver::parseString(const std::string &inString)
{
    std::istringstream iss(inString);
    return parseStream(iss);
}