#pragma once
#include "StatementNode.h"
#include "CalcNode.h"

namespace calc
{
	class AssignNode : public StatementNode
	{
	public:
		AssignNode(unsigned nameId, std::unique_ptr<CalcNode> && node);
		void Execute(CalcContext & context)const override;
	private:
		unsigned m_nameId;
		std::unique_ptr<CalcNode> m_node;
	};
}
