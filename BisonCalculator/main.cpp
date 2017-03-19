#include "stdafx.h"
#include "OutputContext.h"
#include "Driver.h"
#include "CalcNode.h"
#include "TermCalcNode.h"

using namespace std;
using namespace calc;

int main()
{
	Driver driver(make_shared<OutputContext>());

	//string expr = "(-5.5+6)*-1";
	string expr = "alice";
	cout << expr << endl;
	driver.ParseString(expr);
#if 0
	cout << endl << "Enter expression: ";
	driver.ParseStream(std::cin);
#endif
	return 0;
}