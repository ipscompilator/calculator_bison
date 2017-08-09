#include "stdafx.h"
#include "IfStmtNode.h"

using namespace calc;
using namespace std;

IfStmtNode::IfStmtNode(unique_ptr<IExpressionNode> && conditionNode, unique_ptr<IBlockNode> && thenBodyNode, unique_ptr<IBlockNode> && elseBodyNode)
	: m_conditionNode(move(conditionNode))
	, m_thenBodyNode(move(thenBodyNode))
	, m_elseBodyNode(move(elseBodyNode))
{
}

void IfStmtNode::Execute(DriverContext & context) const
{
}

void IfStmtNode::Accept(INodeVisitor & visitor, unsigned level)
{
	visitor.Visit(*this, level);
}

IExpressionNode & IfStmtNode::GetConditionNode()
{
	return *m_conditionNode;
}

IBlockNode & IfStmtNode::GetThenBodyNode()
{
	return *m_thenBodyNode;
}

IBlockNode & IfStmtNode::GetElseBodyNode()
{
	return *m_elseBodyNode;
}
