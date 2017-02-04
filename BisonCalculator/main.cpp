#include "parser.hpp"
#include "Scanner.h"
#include <iostream>


int main()
{
    yy::Scanner scanner;
    yy::Parser parser(scanner);
    parser.parse();

    return 0;
}