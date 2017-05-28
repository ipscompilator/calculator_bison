#pragma once
#include "IStatementNode.h"
#include "ICalcNode.h"

namespace calc
{
	class PrintNode : public IStatementNode
	{
	public:
		PrintNode(std::unique_ptr<ICalcNode> && node);
		void Execute(CalcContext & context)const override;
		void Accept(INodeVisitor & visitor) override;

		ICalcNode & GetNode();

	private:
		std::unique_ptr<ICalcNode> m_node;
	};
}
