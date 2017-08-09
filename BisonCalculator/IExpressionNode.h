#pragma once
#include "PointerHelpers.h"
#include "INode.h"
#include "CalcContext.h"

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
		virtual double Evaluate(CalcContext & context) const = 0;
	};
}