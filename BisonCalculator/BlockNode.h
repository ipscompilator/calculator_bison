#pragma once
#include "IBlockNode.h"

namespace calc
{
	class BlockNode : public IBlockNode
	{
	public:
		virtual void AddStatement(std::unique_ptr<IStatementNode> && statement) override;
		void ExecuteBlock(CalcContext & context)const;
		void Accept(INodeVisitor & visitor) override;

		size_t GetStatementsCount() const;
		IStatementNode & GetStatement(size_t index);

	private:
		std::vector<std::unique_ptr<IStatementNode>> m_statements;
	};
}
