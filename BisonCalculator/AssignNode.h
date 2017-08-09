#pragma once
#include "IStatementNode.h"
#include "IExpressionNode.h"

namespace calc
{
	class AssignNode : public IStatementNode
	{
	public:
		AssignNode(unsigned nameId, std::unique_ptr<IExpressionNode> && node);
		void Execute(CalcContext & context)const override;
		void Accept(INodeVisitor & visitor, unsigned level) override;

		unsigned GetNameId() const;
		IExpressionNode & GetNode();

	private:
		unsigned m_nameId;
		std::unique_ptr<IExpressionNode> m_node;
	};
}
