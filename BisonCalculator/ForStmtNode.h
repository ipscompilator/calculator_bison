#pragma once
#include "IStatementNode.h"
#include "ICalcNode.h"
#include "IBlockNode.h"

namespace calc
{
	class ForStmtNode : public IStatementNode
	{
	public:
		ForStmtNode(std::unique_ptr<ICalcNode> && conditionNode, std::unique_ptr<IBlockNode> && bodyNode);
		void Execute(CalcContext & context)const override;
		void Accept(INodeVisitor & visitor, unsigned level) override;

		ICalcNode & GetConditionNode();
		IBlockNode & GetBodyNode();

	private:
		std::unique_ptr<ICalcNode> m_conditionNode;
		std::unique_ptr<IBlockNode> m_bodyNode;
	};
}

