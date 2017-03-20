#pragma once
#include "ICalcNode.h"

namespace calc
{

	class BinaryCalcNode : public ICalcNode
	{
	public:
		BinaryCalcNode(std::unique_ptr<ICalcNode> && left, std::unique_ptr<ICalcNode> && right, Operation operation);
		double Evaluate(CalcContext & context) const override;

	private:
		std::unique_ptr<ICalcNode> m_left;
		std::unique_ptr<ICalcNode> m_right;
		Operation m_operation;
	};
}
