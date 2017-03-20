#pragma once
#include "ICalcNode.h"

namespace calc
{

	class TermCalcNode : public ICalcNode
	{
	public:
		TermCalcNode(double value);
		double Evaluate(CalcContext & context) const override;

	private:
		double m_value;
	};

}
