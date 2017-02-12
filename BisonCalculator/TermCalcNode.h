#pragma once
#include "CalcNode.h"

namespace calc
{

    class TermCalcNode : public CalcNode
    {
    public:
        TermCalcNode(double value);
        double Evaluate() const override;

    private:
        double m_value;
    };

}
