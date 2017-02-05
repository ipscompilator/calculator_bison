#include "stdafx.h"
#include <iostream>
#include "Driver.h"


using namespace std;

int main()
{
    yy::Driver driver;
    
    string expr = "(-5.5+6)*-1";
    cout << expr <<endl;
    if (driver.parseString(expr))
    {
        cout << "Result: " << driver.resultValue << endl;
    }
    
    cout << endl << "Enter expression: ";
    if (driver.parseStream(std::cin))
    {
        cout << "Result: " << driver.resultValue << endl;
    }
    return 0;
}