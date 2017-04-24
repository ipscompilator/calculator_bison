#include "stdafx.h"
#include "BlockNode.h"

using namespace calc;
using namespace std;

void BlockNode::AddStatement(unique_ptr<IStatementNode> && statement)
{
	m_statements.push_back(move(statement));
}

void BlockNode::ExecuteBlock(CalcContext & context) const
{
	for (auto & statement : m_statements)
	{
		statement->Execute(context);
	}
}
