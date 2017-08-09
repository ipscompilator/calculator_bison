#pragma once
#include "IExpressionNode.h"

namespace calc
{
	class LiteralNode : public IExpressionNode
	{
	public:
		LiteralNode(double value);
		double Evaluate(DriverContext & context) const override;
		void Accept(INodeVisitor & visitor, unsigned level) override;
		double GetValue() const;

	private:
		double m_value;
	};
}
