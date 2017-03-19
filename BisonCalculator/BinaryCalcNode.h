#pragma once
#include "CalcNode.h"

namespace calc
{

	class BinaryCalcNode : public CalcNode
	{
	public:
		BinaryCalcNode(std::unique_ptr<CalcNode> && left, std::unique_ptr<CalcNode> && right, Operation operation);
		double Evaluate(CalcContext & context) const override;

	private:
		std::unique_ptr<CalcNode> m_left;
		std::unique_ptr<CalcNode> m_right;
		Operation m_operation;
	};
}
