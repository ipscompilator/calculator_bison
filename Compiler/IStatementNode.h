#pragma once
#include "INode.h"
#include "DriverContext.h"

namespace calc
{
	class IStatementNode : public INode
	{
	public:
		virtual void Execute(DriverContext & context)const = 0;
	};
}
