#pragma once
#include "ICalcNode.h"

namespace calc
{
	class VariableRefNode : public ICalcNode
	{
	public:
		VariableRefNode(unsigned stringId);
		double Evaluate(CalcContext & context)const override;
	private:
		unsigned m_stringId;
	};
}
