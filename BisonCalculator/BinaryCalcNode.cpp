#include "stdafx.h"
#include "BinaryCalcNode.h"

using namespace calc;

BinaryCalcNode::BinaryCalcNode(CalcNode* left, CalcNode* right, Operation operation)
:m_left(left), m_right(right), m_operation(operation)
{
}

BinaryCalcNode::~BinaryCalcNode()
{
    delete m_left;
    delete m_right;
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


