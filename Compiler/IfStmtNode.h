#pragma once
#include "IStatementNode.h"
#include "IExpressionNode.h"
#include "IBlockNode.h"

namespace calc
{
	class IfStmtNode : public IStatementNode
	{
	public:
		IfStmtNode(std::unique_ptr<IExpressionNode> && conditionNode, std::unique_ptr<IBlockNode> && thenBodyNode, std::unique_ptr<IBlockNode> && elseBodyNode);
		void Execute(DriverContext & context)const override;
		void Accept(INodeVisitor & visitor, unsigned level) override;

		IExpressionNode & GetConditionNode();
		IBlockNode & GetThenBodyNode();
		IBlockNode & GetElseBodyNode();
		
	private:
		std::unique_ptr<IExpressionNode> m_conditionNode;
		std::unique_ptr<IBlockNode> m_thenBodyNode;
		std::unique_ptr<IBlockNode> m_elseBodyNode;
	};
}


