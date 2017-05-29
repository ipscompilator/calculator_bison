#pragma once
#include "IStatementNode.h"
#include "ICalcNode.h"
#include "IBlockNode.h"

namespace calc
{
	class IfStmtNode : public IStatementNode
	{
	public:
		IfStmtNode(std::unique_ptr<ICalcNode> && conditionNode, std::unique_ptr<IBlockNode> && thenBodyNode, std::unique_ptr<IBlockNode> && elseBodyNode);
		void Execute(CalcContext & context)const override;
		void Accept(INodeVisitor & visitor) override;

		ICalcNode & GetConditionNode();
		IBlockNode & GetThenBodyNode();
		IBlockNode & GetElseBodyNode();
		
	private:
		std::unique_ptr<ICalcNode> m_conditionNode;
		std::unique_ptr<IBlockNode> m_thenBodyNode;
		std::unique_ptr<IBlockNode> m_elseBodyNode;
	};
}


