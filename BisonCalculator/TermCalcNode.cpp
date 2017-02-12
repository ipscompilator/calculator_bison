#include "stdafx.h"
#include "TermCalcNode.h"

using namespace calc;

TermCalcNode::TermCalcNode(double value)
:m_value(value)
{
}

double TermCalcNode::Evaluate() const
{
    return m_value;
}

