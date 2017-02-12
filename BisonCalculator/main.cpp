#include "stdafx.h"
#include <iostream>
#include "Driver.h"


using namespace std;

int main()
{
    calc::Driver driver;
    
    string expr = "(-5.5+6)*-1";
    cout << expr << endl;
    driver.parseString(expr);
    
    cout << endl << "Enter expression: ";
    driver.parseStream(std::cin);

    return 0;
}