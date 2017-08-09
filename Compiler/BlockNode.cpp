#include "stdafx.h"
#include "BlockNode.h"

using namespace calc;
using namespace std;

void BlockNode::AddStatement(unique_ptr<IStatementNode> && statement)
{
	m_statements.push_back(move(statement));
}

void BlockNode::ExecuteBlock(DriverContext & context) const
{
	for (auto & statement : m_statements)
	{
		statement->Execute(context);
	}
}

void BlockNode::Accept(INodeVisitor & visitor, unsigned level)
{
	visitor.Visit(*this, level);
}

size_t BlockNode::GetStatementsCount() const
{
	return m_statements.size();
}

IStatementNode & BlockNode::GetStatement(size_t index)
{
	return *m_statements.at(index);
}
