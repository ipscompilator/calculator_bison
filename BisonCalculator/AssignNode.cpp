#include "stdafx.h"
#include "AssignNode.h"

using namespace calc;
using namespace std;

AssignNode::AssignNode(unsigned nameId, std::unique_ptr<ICalcNode> && node)
	: m_nameId(nameId)
	, m_node(move(node))
{
}

void AssignNode::Execute(CalcContext & context) const
{
	context.AssignVariable(m_nameId, m_node->Evaluate(context));
}
