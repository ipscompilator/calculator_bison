#include "stdafx.h"
#include <iostream>
#include "Driver.h"
#include "CalcNode.h"
#include "TermCalcNode.h"

#include <memory>

using namespace std;
using namespace calc;

int main()
{
    Driver driver;
    
    string expr = "(-5.5+6)*-1";
    cout << expr << endl;
    driver.parseString(expr);
    
    cout << endl << "Enter expression: ";
    driver.parseStream(std::cin);
    
    return 0;
}