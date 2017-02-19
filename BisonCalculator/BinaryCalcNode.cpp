#include "stdafx.h"
#include "BinaryCalcNode.h"

using namespace calc;

BinaryCalcNode::BinaryCalcNode(std::unique_ptr<CalcNode> && left, std::unique_ptr<CalcNode> && right, Operation operation)
:m_left(move(left)), m_right(move(right)), m_operation(operation)
{
}

BinaryCalcNode::~BinaryCalcNode()
{
}

double BinaryCalcNode::Evaluate() const
{
    double left = m_left->Evaluate();
    double right = m_right->Evaluate();

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


