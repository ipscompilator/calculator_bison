#pragma once
#include "CalcNode.h"

namespace calc
{
	class VariableRefNode : public CalcNode
	{
	public:
		VariableRefNode(unsigned stringId);
		double Evaluate(CalcContext & context)const override;
	private:
		unsigned m_stringId;
	};
}
