#pragma once
#include "CalcNode.h"

namespace calc
{

    class UnaryCalcNode : public CalcNode
    {
    public:
        UnaryCalcNode(CalcNode* node, Operation operation);
        ~UnaryCalcNode();
        double Evaluate() const override;

    private:
        CalcNode* m_node;
        Operation m_operation;
    };

}