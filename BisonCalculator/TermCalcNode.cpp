#include "stdafx.h"
#include "TermCalcNode.h"

using namespace calc;

TermCalcNode::TermCalcNode(double value)
	: m_value(value)
{
}

double TermCalcNode::Evaluate(CalcContext & context) const
{
	context;
	return m_value;
}

void TermCalcNode::Accept(INodeVisitor & visitor)
{
	visitor.Visit(*this);
}

double TermCalcNode::GetValue() const
{
	return m_value;
}

