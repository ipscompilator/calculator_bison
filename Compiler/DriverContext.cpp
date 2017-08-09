#include "stdafx.h"
#include "DriverContext.h"

using namespace calc;
using namespace std;

DriverContext::DriverContext(CStringPool & stringPool, std::shared_ptr<IOutputContext> outputContext)
	: m_stringPool(stringPool)
	, m_outputContext(outputContext)
{
}

DriverContext::~DriverContext()
{
}

void DriverContext::AssignVariable(unsigned stringId, double value)
{
	m_variables[stringId] = value;
}

double DriverContext::GetVariableValue(unsigned stringId) const
{
	try
	{
		return m_variables.at(stringId);
	}
	catch (exception const&)
	{
		string error = "undefined variable " + m_stringPool.GetString(stringId);
		m_outputContext->ReportIssue(error);
		return 0;
	}
}

void DriverContext::PrintResult(double value) const
{
	m_outputContext->PrintResult(value);
}