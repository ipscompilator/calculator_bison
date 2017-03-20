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

	class ICalcNode : public INode
	{
	public:
		ICalcNode() {};
		virtual double Evaluate(CalcContext & context) const = 0;
	};
}