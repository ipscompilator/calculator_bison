#pragma once
#include "IStatementNode.h"
#include "ICalcNode.h"

namespace calc
{
	class AssignNode : public IStatementNode
	{
	public:
		AssignNode(unsigned nameId, std::unique_ptr<ICalcNode> && node);
		void Execute(CalcContext & context)const override;
		void Accept(INodeVisitor & visitor) override;

		unsigned GetNameId() const;
		ICalcNode & GetNode();

	private:
		unsigned m_nameId;
		std::unique_ptr<ICalcNode> m_node;
	};
}
