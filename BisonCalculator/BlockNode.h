#pragma once
#include "IBlockNode.h"

namespace calc
{
	class BlockNode : public IBlockNode
	{
	public:
		virtual void AddStatement(std::unique_ptr<IStatementNode> && statement) override;
		void ExecuteBlock(CalcContext & context)const;

	private:
		std::vector<std::unique_ptr<IStatementNode>> m_statements;
	};
}
