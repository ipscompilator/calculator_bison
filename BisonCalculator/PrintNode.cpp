#include "stdafx.h"
#include "PrintNode.h"

using namespace calc;
using namespace std;

PrintNode::PrintNode(std::unique_ptr<ICalcNode> && node)
	: m_node(move(node))
{
}

void PrintNode::Execute(CalcContext & context) const
{
	context.PrintResult(m_node->Evaluate(context));
}

void PrintNode::Accept(INodeVisitor & visitor, unsigned level)
{
	visitor.Visit(*this, level);
}

ICalcNode & PrintNode::GetNode()
{
	return *m_node;
}
