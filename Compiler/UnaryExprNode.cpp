#include "stdafx.h"
#include "UnaryExprNode.h"

using namespace calc;

UnaryExprNode::UnaryExprNode(std::unique_ptr<IExpressionNode> && node, Operation operation)
	: m_node(std::move(node))
	, m_operation(operation)
{
}

double UnaryExprNode::Evaluate(DriverContext & context) const
{
	double value = m_node->Evaluate(context);
	switch (m_operation)
	{
	case Operation::ADD:
		return value;
	case Operation::SUB:
		return -value;
	}
}

void UnaryExprNode::Accept(INodeVisitor & visitor, unsigned level)
{
	visitor.Visit(*this, level);
}

IExpressionNode & UnaryExprNode::GetNode()
{
	return *m_node;
}

Operation UnaryExprNode::GetOperation() const
{
	return m_operation;
}
