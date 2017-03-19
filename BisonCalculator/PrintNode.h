#pragma once
#include "StatementNode.h"
#include "CalcNode.h"

namespace calc
{
	class PrintNode : public StatementNode
	{
	public:
		PrintNode(std::unique_ptr<CalcNode> && node);
		void Execute(CalcContext & context)const override;
	private:
		std::unique_ptr<CalcNode> m_node;
	};
}
