#include "stdafx.h"
#include "BinaryCalcNode.h"

using namespace calc;

BinaryCalcNode::BinaryCalcNode(std::unique_ptr<ICalcNode> && left, std::unique_ptr<ICalcNode> && right, Operation operation)
	: m_left(move(left))
	, m_right(move(right))
	, m_operation(operation)
{
}

double BinaryCalcNode::Evaluate(CalcContext & context) const
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

void BinaryCalcNode::Accept(INodeVisitor & visitor)
{
	visitor.Visit(*this);
}

ICalcNode & BinaryCalcNode::GetLeftNode()
{
	return *m_left;
}

ICalcNode & BinaryCalcNode::GetRightNode()
{
	return *m_right;
}

Operation BinaryCalcNode::GetOperation() const
{
	return m_operation;
}


