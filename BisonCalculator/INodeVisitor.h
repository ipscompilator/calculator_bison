#pragma once

namespace calc 
{
	class BinaryExprNode;
	class UnaryExprNode;
	class LiteralNode;
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
		virtual void Visit(BinaryExprNode & node, unsigned level) = 0;
		virtual void Visit(UnaryExprNode & node, unsigned level) = 0;
		virtual void Visit(LiteralNode & node, unsigned level) = 0;
		virtual void Visit(VariableRefNode & node, unsigned level) = 0;
		virtual void Visit(AssignNode & node, unsigned level) = 0;
		virtual void Visit(PrintNode & node, unsigned level) = 0;
		virtual void Visit(IfStmtNode & node, unsigned level) = 0;
		virtual void Visit(ForStmtNode & node, unsigned level) = 0;
		virtual void Visit(BlockNode & node, unsigned level) = 0;
	};
}

