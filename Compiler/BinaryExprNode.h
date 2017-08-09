#pragma once
#include "IExpressionNode.h"

namespace calc
{
	class BinaryExprNode : public IExpressionNode
	{
	public:
		BinaryExprNode(std::unique_ptr<IExpressionNode> && left, std::unique_ptr<IExpressionNode> && right, Operation operation);
		double Evaluate(DriverContext & context) const override;
		void Accept(INodeVisitor & visitor, unsigned level) override;

		IExpressionNode & GetLeftNode();
		IExpressionNode & GetRightNode();
		Operation GetOperation() const;

	private:
		std::unique_ptr<IExpressionNode> m_left;
		std::unique_ptr<IExpressionNode> m_right;
		Operation m_operation;
	};
}
