#include "stdafx.h"
#include "CalcContext.h"

using namespace calc;
using namespace std;

CalcContext::CalcContext(CStringPool & stringPool, std::shared_ptr<IOutputContext> outputContext)
	: m_stringPool(stringPool)
	, m_outputContext(outputContext)
{
}

CalcContext::~CalcContext()
{
}

void CalcContext::AssignVariable(unsigned stringId, double value)
{
	m_variables[stringId] = value;
}

double CalcContext::GetVariableValue(unsigned stringId) const
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

void CalcContext::PrintResult(double value) const
{
	m_outputContext->PrintResult(value);
}