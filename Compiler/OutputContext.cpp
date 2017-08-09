#include "stdafx.h"
#include "OutputContext.h"

using namespace calc;
using namespace std;

OutputContext::OutputContext()
{
}

void OutputContext::ReportIssue(const string & msg)
{
	cerr << "Error: " << msg << endl;
}

void OutputContext::ReportIssue(const string & msg, const location & loc)
{
	cerr << "{" << loc << "} Error: " << msg << endl;
}

void OutputContext::PrintResult(double val)
{
	cout << "Node result: " << val << endl;
}