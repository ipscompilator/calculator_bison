#pragma once
#include "INodeVisitor.h"
#include "ICalcNode.h"

namespace calc
{
	class PrintVisitor : public INodeVisitor
	{
	public:
		PrintVisitor(std::ostream & out, CStringPool & stringPool);
		void Visit(BinaryCalcNode & node) override;
		void Visit(UnaryCalcNode & node) override;
		void Visit(TermCalcNode & node) override;
		void Visit(VariableRefNode & node) override;
		void Visit(AssignNode & node) override;
		void Visit(PrintNode & node) override;
		void Visit(BlockNode & node) override;
	private:
		void PrintOperation(Operation operation);
		std::ostream & m_out;
		CStringPool & m_stringPool;
	};

}