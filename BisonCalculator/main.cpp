#include "stdafx.h"
#include "OutputContext.h"
#include "Driver.h"

using namespace std;
using namespace calc;

int main()
{
	Driver driver(make_shared<OutputContext>());
#if 1
	string expr = "print (-5.5+6)*-1\n";
	cout << expr << endl;
	driver.ParseString(expr);
#endif
	
	cout << endl << "Enter expression: ";
	driver.ParseStream(cin);
	return 0;
}