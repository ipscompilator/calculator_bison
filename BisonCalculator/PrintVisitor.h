#pragma once
#include "INodeVisitor.h"
#include "ICalcNode.h"

namespace calc
{
	class PrintVisitor : public INodeVisitor
	{
	public:
		PrintVisitor(std::ostream & out, CStringPool & stringPool);
		void Visit(BinaryCalcNode & node, unsigned level) override;
		void Visit(UnaryCalcNode & node, unsigned level) override;
		void Visit(TermCalcNode & node, unsigned level) override;
		void Visit(VariableRefNode & node, unsigned level) override;
		void Visit(AssignNode & node, unsigned level) override;
		void Visit(PrintNode & node, unsigned level) override;
		void Visit(IfStmtNode & node, unsigned level) override;
		void Visit(ForStmtNode & node, unsigned level) override;
		void Visit(BlockNode & node, unsigned level) override;
	private:
		void PrintOperation(Operation operation);
		void PrintIndent(unsigned level);
		const unsigned m_indentSize = 2;
		std::ostream & m_out;
		CStringPool & m_stringPool;
	};

}