#pragma once
#include "INode.h"
#include "CalcContext.h"

namespace calc
{
	class IStatementNode : public INode
	{
	public:
		virtual void Execute(CalcContext & context)const = 0;
	};
}
