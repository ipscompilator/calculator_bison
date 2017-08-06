#pragma once

namespace calc 
{
	class BinaryCalcNode;
	class UnaryCalcNode;
	class TermCalcNode;
	class VariableRefNode;
	class AssignNode;
	class PrintNode;
	class IfStmtNode;
	class ForStmtNode;
	class BlockNode;

	class INodeVisitor
	{
	public:
		virtual ~INodeVisitor() = default;
		virtual void Visit(BinaryCalcNode & node, unsigned level) = 0;
		virtual void Visit(UnaryCalcNode & node, unsigned level) = 0;
		virtual void Visit(TermCalcNode & node, unsigned level) = 0;
		virtual void Visit(VariableRefNode & node, unsigned level) = 0;
		virtual void Visit(AssignNode & node, unsigned level) = 0;
		virtual void Visit(PrintNode & node, unsigned level) = 0;
		virtual void Visit(IfStmtNode & node, unsigned level) = 0;
		virtual void Visit(ForStmtNode & node, unsigned level) = 0;
		virtual void Visit(BlockNode & node, unsigned level) = 0;
	};
}

