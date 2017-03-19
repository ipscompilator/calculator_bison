#include "stdafx.h"
#include "PrintNode.h"

using namespace calc;
using namespace std;

PrintNode::PrintNode(std::unique_ptr<CalcNode> && node)
	: m_node(move(node))
{
}

void PrintNode::Execute(CalcContext & context) const
{
	context.PrintResult(m_node->Evaluate(context));
}
