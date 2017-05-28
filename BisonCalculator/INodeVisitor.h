#pragma once

namespace calc 
{
	class BinaryCalcNode;
	class UnaryCalcNode;
	class TermCalcNode;
	class VariableRefNode;
	class AssignNode;
	class PrintNode;
	class BlockNode;

	class INodeVisitor
	{
	public:
		virtual ~INodeVisitor() = default;
		virtual void Visit(BinaryCalcNode & node) = 0;
		virtual void Visit(UnaryCalcNode & node) = 0;
		virtual void Visit(TermCalcNode & node) = 0;
		virtual void Visit(VariableRefNode & node) = 0;
		virtual void Visit(AssignNode & node) = 0;
		virtual void Visit(PrintNode & node) = 0;
		virtual void Visit(BlockNode & node) = 0;
	};
}

