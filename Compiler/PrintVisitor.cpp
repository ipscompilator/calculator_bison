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

void PrintVisitor::Visit(BinaryExprNode & node, unsigned level)
{
	cout << "(";
	node.GetLeftNode().Accept(*this, level);
	PrintOperation(node.GetOperation());
	node.GetRightNode().Accept(*this, level);
	cout << ")";
}

void PrintVisitor::Visit(UnaryExprNode & node, unsigned level)
{	
	PrintOperation(node.GetOperation());
	node.GetNode().Accept(*this, level);
}

void PrintVisitor::Visit(LiteralNode & node, unsigned level)
{
	m_out << node.GetValue();
}

void PrintVisitor::Visit(VariableRefNode & node, unsigned level)
{
	m_out << m_stringPool.GetString(node.GetStringId());
}

void PrintVisitor::Visit(AssignNode & node, unsigned level)
{
	m_out << m_stringPool.GetString(node.GetNameId()) << " = ";
	node.GetNode().Accept(*this, level);
}

void PrintVisitor::Visit(PrintNode & node, unsigned level)
{
	m_out << "print(";
	node.GetNode().Accept(*this, level);
	m_out << ")";
}

void PrintVisitor::Visit(IfStmtNode & node, unsigned level)
{
	m_out << "if ";
	node.GetConditionNode().Accept(*this, level);
	m_out << " { \n";
	node.GetThenBodyNode().Accept(*this, level + m_indentSize);
	PrintIndent(level);
	m_out << "} else {\n";
	node.GetElseBodyNode().Accept(*this, level + m_indentSize);
	PrintIndent(level);
	m_out << "}";
}

void PrintVisitor::Visit(ForStmtNode & node, unsigned level)
{
	m_out << "for ";
	node.GetConditionNode().Accept(*this, level);
	m_out << " {\n";
	node.GetBodyNode().Accept(*this, level + m_indentSize);
	PrintIndent(level);
	m_out << "}";
}

void PrintVisitor::Visit(BlockNode & node, unsigned level)
{
	for (int i = 0; i < node.GetStatementsCount(); i++)
	{
		PrintIndent(level);
		node.GetStatement(i).Accept(*this, level);
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

void PrintVisitor::PrintIndent(unsigned level)
{
	for (int i = 0; i < level; i++) {
		m_out << " ";
	}
}
