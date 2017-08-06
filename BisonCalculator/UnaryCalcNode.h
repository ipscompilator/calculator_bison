#pragma once
#include "ICalcNode.h"

namespace calc
{
	class UnaryCalcNode : public ICalcNode
	{
	public:
		UnaryCalcNode(std::unique_ptr<ICalcNode> && node, Operation operation);
		double Evaluate(CalcContext & context) const override;
		void Accept(INodeVisitor & visitor, unsigned level) override;

		ICalcNode & GetNode();
		Operation GetOperation() const;

	private:
		std::unique_ptr<ICalcNode> m_node;
		Operation m_operation;
	};
}