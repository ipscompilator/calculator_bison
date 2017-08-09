#include "stdafx.h"
#include "AssignNode.h"

using namespace calc;
using namespace std;

AssignNode::AssignNode(unsigned nameId, std::unique_ptr<IExpressionNode> && node)
	: m_nameId(nameId)
	, m_node(move(node))
{
}

void AssignNode::Execute(DriverContext & context) const
{
	context.AssignVariable(m_nameId, m_node->Evaluate(context));
}

void AssignNode::Accept(INodeVisitor & visitor, unsigned level)
{
	visitor.Visit(*this, level);
}

unsigned AssignNode::GetNameId() const
{
	return m_nameId;
}

IExpressionNode & AssignNode::GetNode()
{
	return *m_node;
}
