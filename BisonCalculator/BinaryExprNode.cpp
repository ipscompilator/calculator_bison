#include "stdafx.h"
#include "BinaryExprNode.h"

using namespace calc;

BinaryExprNode::BinaryExprNode(std::unique_ptr<IExpressionNode> && left, std::unique_ptr<IExpressionNode> && right, Operation operation)
	: m_left(move(left))
	, m_right(move(right))
	, m_operation(operation)
{
}

double BinaryExprNode::Evaluate(CalcContext & context) const
{
	double left = m_left->Evaluate(context);
	double right = m_right->Evaluate(context);

	switch (m_operation)
	{
	case Operation::ADD:
		return left + right;
	case Operation::SUB:
		return left - right;
	case Operation::MUL:
		return left * right;
	case Operation::DIV:
		return left / right;
	}
}

void BinaryExprNode::Accept(INodeVisitor & visitor, unsigned level)
{
	visitor.Visit(*this, level);
}

IExpressionNode & BinaryExprNode::GetLeftNode()
{
	return *m_left;
}

IExpressionNode & BinaryExprNode::GetRightNode()
{
	return *m_right;
}

Operation BinaryExprNode::GetOperation() const
{
	return m_operation;
}


