#include "stdafx.h"
#include "Context.h"

using namespace calc;
using namespace std;

Context::Context()
{
}

void Context::ReportIssue(const std::string & msg, const location & loc)
{
	cerr << "{" << loc << "} Error: " << msg << endl;
}

void Context::PrintResult(double val)
{
	cout << "Node result: " << val << endl;
}