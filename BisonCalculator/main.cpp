#include "parser.hpp"
#include <iostream>

double calcResult = 0.0;

int main()
{
    //yyparse();
    yy::Parser parser;
    parser.parse();

    std::cout << "Final result: " << calcResult << std::endl;
    return 0;
}