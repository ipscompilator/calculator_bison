#include "stdafx.h"
#include "UnaryCalcNode.h"

using namespace calc;

UnaryCalcNode::UnaryCalcNode(CalcNode* node, Operation operation)
:m_node(node), m_operation(operation)
{
}

UnaryCalcNode::~UnaryCalcNode()
{
    delete m_node;
}

double UnaryCalcNode::Evaluate() const
{
    double value = m_node->Evaluate();
    switch (m_operation)
    {
    case Operation::ADD:
        return value;
    case Operation::SUB:
        return - value;
    }
}