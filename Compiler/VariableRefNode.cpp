#include "stdafx.h"
#include "VariableRefNode.h"

using namespace calc;

VariableRefNode::VariableRefNode(unsigned stringId)
	: m_stringId(stringId)
{
}

double VariableRefNode::Evaluate(DriverContext & context) const
{
	return context.GetVariableValue(m_stringId);
}

void VariableRefNode::Accept(INodeVisitor & visitor, unsigned level)
{
	visitor.Visit(*this, level);
}

unsigned VariableRefNode::GetStringId() const
{
	return m_stringId;
}


