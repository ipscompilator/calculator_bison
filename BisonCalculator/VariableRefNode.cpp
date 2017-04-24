#include "stdafx.h"
#include "VariableRefNode.h"

using namespace calc;

VariableRefNode::VariableRefNode(unsigned stringId)
	: m_stringId(stringId)
{
}

double VariableRefNode::Evaluate(CalcContext & context) const
{
	return context.GetVariableValue(m_stringId);
}


