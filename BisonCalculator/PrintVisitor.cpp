#include "stdafx.h"
#include "PrintVisitor.h"
#include "ParserHeaders.h"

using namespace calc;
using namespace std;

PrintVisitor::PrintVisitor(std::ostream & out, CStringPool & stringPool)
	: m_out(out)
	, m_stringPool(stringPool)
{
}

void PrintVisitor::Visit(BinaryCalcNode & node)
{
	cout << "(";
	node.GetLeftNode().Accept(*this);
	PrintOperation(node.GetOperation());
	node.GetRightNode().Accept(*this);
	cout << ")";
}

void PrintVisitor::Visit(UnaryCalcNode & node)
{	
	PrintOperation(node.GetOperation());
	node.GetNode().Accept(*this);
}

void PrintVisitor::Visit(TermCalcNode & node)
{
	m_out << node.GetValue();
}

void PrintVisitor::Visit(VariableRefNode & node)
{
	m_out << m_stringPool.GetString(node.GetStringId());
}

void PrintVisitor::Visit(AssignNode & node)
{
	m_out << m_stringPool.GetString(node.GetNameId()) << " = ";
	node.GetNode().Accept(*this);
}

void PrintVisitor::Visit(PrintNode & node)
{
	m_out << "Print(";
	node.GetNode().Accept(*this);
	m_out << ")";
}

void PrintVisitor::Visit(IfStmtNode & node)
{
	m_out << "If ";
	node.GetConditionNode().Accept(*this);
	m_out << "\nThen {\n";
	node.GetThenBodyNode().Accept(*this);
	m_out << "} Else {\n";
	node.GetElseBodyNode().Accept(*this);
	m_out << "}";
}

void PrintVisitor::Visit(ForStmtNode & node)
{
	m_out << "For ";
	node.GetConditionNode().Accept(*this);
	m_out << " {\n";
	node.GetBodyNode().Accept(*this);
	m_out << "}";
}

void PrintVisitor::Visit(BlockNode & node)
{
	for (int i = 0; i < node.GetStatementsCount(); i++)
	{
		node.GetStatement(i).Accept(*this);
		m_out << endl;
	}
}

void calc::PrintVisitor::PrintOperation(Operation operation)
{
	switch (operation)
	{
	case Operation::ADD:
		m_out << "+";
		break;
	case Operation::SUB:
		m_out << "-";
		break;
	case Operation::MUL:
		m_out << "*";
		break;
	case Operation::DIV:
		m_out << "/";
		break;
	}
}
