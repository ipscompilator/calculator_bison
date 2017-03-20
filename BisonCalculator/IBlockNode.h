#pragma once
#include "INode.h"
#include "IStatementNode.h"
#include "CalcContext.h"

namespace calc
{
	class IBlockNode : public INode
	{
	public:
		IBlockNode() {};
		virtual void AddStatement(std::unique_ptr<IStatementNode> && statement) = 0;
	};
}
