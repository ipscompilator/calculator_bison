#include "stdafx.h"
#include "UnaryCalcNode.h"

using namespace calc;

UnaryCalcNode::UnaryCalcNode(std::unique_ptr<CalcNode> && node, Operation operation)
	: m_node(std::move(node))
	, m_operation(operation)
{
}

double UnaryCalcNode::Evaluate(CalcContext & context) const
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