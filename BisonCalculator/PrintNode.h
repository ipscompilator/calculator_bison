#pragma once
#include "IStatementNode.h"
#include "IExpressionNode.h"

namespace calc
{
	class PrintNode : public IStatementNode
	{
	public:
		PrintNode(std::unique_ptr<IExpressionNode> && node);
		void Execute(CalcContext & context)const override;
		void Accept(INodeVisitor & visitor, unsigned level) override;

		IExpressionNode & GetNode();

	private:
		std::unique_ptr<IExpressionNode> m_node;
	};
}
