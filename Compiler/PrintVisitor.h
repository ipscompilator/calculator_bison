#pragma once
#include "INodeVisitor.h"
#include "IExpressionNode.h"

namespace calc
{
	class PrintVisitor : public INodeVisitor
	{
	public:
		PrintVisitor(std::ostream & out, CStringPool & stringPool);
		void Visit(BinaryExprNode & node, unsigned level) override;
		void Visit(UnaryExprNode & node, unsigned level) override;
		void Visit(LiteralNode & node, unsigned level) override;
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