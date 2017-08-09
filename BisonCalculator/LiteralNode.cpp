#include "stdafx.h"
#include "LiteralNode.h"

using namespace calc;

LiteralNode::LiteralNode(double value)
	: m_value(value)
{
}

double LiteralNode::Evaluate(CalcContext & context) const
{
	context;
	return m_value;
}

void LiteralNode::Accept(INodeVisitor & visitor, unsigned level)
{
	visitor.Visit(*this, level);
}

double LiteralNode::GetValue() const
{
	return m_value;
}

