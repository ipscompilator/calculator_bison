#include "Driver.h"
#include <iostream>
#pragma warning(push)

int main()
{
    yy::Driver driver;
    
    /*std::string expr = "(-5.5+6)*-1";
    std::cout << expr << std::endl;
    driver.parseString(expr);
    */
    driver.parseStream(std::cin);
    return 0;
}