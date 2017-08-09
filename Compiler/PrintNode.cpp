#include "stdafx.h"
#include "PrintNode.h"

using namespace calc;
using namespace std;

PrintNode::PrintNode(std::unique_ptr<IExpressionNode> && node)
	: m_node(move(node))
{
}

void PrintNode::Execute(DriverContext & context) const
{
	context.PrintResult(m_node->Evaluate(context));
}

void PrintNode::Accept(INodeVisitor & visitor, unsigned level)
{
	visitor.Visit(*this, level);
}

IExpressionNode & PrintNode::GetNode()
{
	return *m_node;
}
