#pragma once
#include "CalcNode.h"

namespace calc
{

    class UnaryCalcNode : public CalcNode
    {
    public:
		UnaryCalcNode(std::unique_ptr<CalcNode> && node, Operation operation);
        ~UnaryCalcNode();
        double Evaluate() const override;

	private:
		std::unique_ptr<CalcNode> m_node;
        Operation m_operation;
    };

}