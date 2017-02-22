#include "stdafx.h"
#include "Context.h"
#include "Driver.h"
#include "CalcNode.h"
#include "TermCalcNode.h"

using namespace std;
using namespace calc;

int main()
{
    Driver driver(make_shared<Context>());
    
    string expr = "(-5.5+6)*-1";
    cout << expr << endl;
    driver.parseString(expr);
    
    cout << endl << "Enter expression: ";
    driver.parseStream(std::cin);
    
    return 0;
}