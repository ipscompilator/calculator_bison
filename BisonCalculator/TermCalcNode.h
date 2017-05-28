#pragma once
#include "ICalcNode.h"

namespace calc
{
	class TermCalcNode : public ICalcNode
	{
	public:
		TermCalcNode(double value);
		double Evaluate(CalcContext & context) const override;
		void Accept(INodeVisitor & visitor) override;
		double GetValue() const;

	private:
		double m_value;
	};
}
