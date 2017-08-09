#pragma once
#include "PointerHelpers.h"
#include "INode.h"
#include "DriverContext.h"

namespace calc 
{
	enum class Operation
	{
		ADD, // +
		SUB, // -
		MUL, // *
		DIV // /
	};

	class IExpressionNode : public INode
	{
	public:
		IExpressionNode() {};
		virtual double Evaluate(DriverContext & context) const = 0;
	};
}