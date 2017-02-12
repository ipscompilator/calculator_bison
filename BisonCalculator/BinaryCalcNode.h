#pragma once
#include "CalcNode.h"

namespace calc
{

    class BinaryCalcNode : public CalcNode
    {
    public:
        BinaryCalcNode(CalcNode* left, CalcNode* right, Operation operation);
        ~BinaryCalcNode();
        double Evaluate() const override;

    private:
        CalcNode* m_left;
        CalcNode* m_right;
        Operation m_operation;
    };

}
