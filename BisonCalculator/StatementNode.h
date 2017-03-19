#pragma once
#include "INode.h"
#include "CalcContext.h"

namespace calc
{
	class StatementNode : public INode
	{
	public:
		StatementNode() {};
		virtual void Execute(CalcContext & context)const = 0;
	};
}
