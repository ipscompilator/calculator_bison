#pragma once
#include "IExpressionNode.h"

namespace calc
{
	class UnaryExprNode : public IExpressionNode
	{
	public:
		UnaryExprNode(std::unique_ptr<IExpressionNode> && node, Operation operation);
		double Evaluate(DriverContext & context) const override;
		void Accept(INodeVisitor & visitor, unsigned level) override;

		IExpressionNode & GetNode();
		Operation GetOperation() const;

	private:
		std::unique_ptr<IExpressionNode> m_node;
		Operation m_operation;
	};
}