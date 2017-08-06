#pragma once
#include "ICalcNode.h"

namespace calc
{
	class VariableRefNode : public ICalcNode
	{
	public:
		VariableRefNode(unsigned stringId);
		double Evaluate(CalcContext & context)const override;
		void Accept(INodeVisitor & visitor, unsigned level) override;

		unsigned GetStringId() const;

	private:
		unsigned m_stringId;
	};
}
