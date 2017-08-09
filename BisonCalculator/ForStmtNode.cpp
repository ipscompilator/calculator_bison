#include "stdafx.h"
#include "ForStmtNode.h"

using namespace calc;
using namespace std;

ForStmtNode::ForStmtNode(unique_ptr<IExpressionNode> && conditionNode, unique_ptr<IBlockNode> && bodyNode)
	: m_conditionNode(move(conditionNode))
	, m_bodyNode(move(bodyNode))
{
}

void ForStmtNode::Execute(CalcContext & context) const
{
}

void ForStmtNode::Accept(INodeVisitor & visitor, unsigned level)
{
	visitor.Visit(*this, level);
}

IExpressionNode & ForStmtNode::GetConditionNode()
{
	return *m_conditionNode;
}

IBlockNode & ForStmtNode::GetBodyNode()
{
	return *m_bodyNode;
}
