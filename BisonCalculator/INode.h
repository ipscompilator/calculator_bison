#pragma once
#include "INodeVisitor.h"

namespace calc
{
	class INode
	{
	public:
		virtual ~INode() = default;
		virtual void Accept(INodeVisitor & visitor, unsigned level) = 0;
	};
}

