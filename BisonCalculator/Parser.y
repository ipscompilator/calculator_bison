/* prologue */

%defines

/* Skeleton implementation for Bison LALR(1) parsers in C++ */
%skeleton "lalr1.cc"
%define parser_class_name {Parser}
%locations

%define api.namespace {calc}
%define api.token.prefix {TOK_}

%define parse.trace true
%define parse.assert true

%parse-param { class Driver& driver }

/* verbose error messages */
%error-verbose

%{
	#include "stdafx.h"
	#include "ParserHeaders.h"

	#undef yylex
	#define yylex driver.Advance
	#define YYDEBUG 1
%}

%union {
	class ICalcNode * calcNode;
	class IStatementNode * statementNode;
	class IBlockNode * blockNode;
	std::vector<std::unique_ptr<IStatementNode>> * statementNodeList;
	double doubleVal;
	unsigned stringId;
}

%destructor { delete $$; } expr mul_expr unary_expr symbol statement statement_line_list assign_stmt print_stmt for_stmt if_stmt block

%token<doubleVal> DOUBLE
%token<stringId> IDENTIFIER
%left PRINT FOR IF ELSE
%left PLUS MINUS
%left MULTIPLY DIVIDE
%left LEFT_P RIGHT_P
%right ASSIGN
%token END	 0	"end of file"
%token EOL	"end of line"

%type<calcNode> expr mul_expr unary_expr symbol 
%type<statementNode> statement assign_stmt print_stmt for_stmt if_stmt
%type<statementNodeList> statement_line_list
%type<blockNode> block

%start program

%%

/* rules section */

program: %empty
	| program statement_line_list END { driver.PrintProgram(*$2); }
	;

block: '{' EOL statement_line_list '}'	{ 
		Emplace<BlockNode>($$); 
		for (int i = 0; i < $3->size(); i++)
		{
			$$->AddStatement(std::move($3->at(i)));
		} 
	}
	;

statement_line_list: statement EOL			{ $$ = new std::vector<std::unique_ptr<IStatementNode>>; $$->push_back(std::move(Extract($1))); }
	| error EOL								{ $$ = new std::vector<std::unique_ptr<IStatementNode>>; }
	| EOL									{ $$ = new std::vector<std::unique_ptr<IStatementNode>>; }
	| statement_line_list statement EOL		{ $1->push_back(std::move(Extract($2))); std::swap($$, $1); }
	| statement_line_list error EOL			{}
	| statement_line_list EOL				{}
	;

statement: print_stmt	{ std::swap($$, $1); }
	| assign_stmt		{ std::swap($$, $1); }
	| for_stmt			{ std::swap($$, $1); }
	| if_stmt			{ std::swap($$, $1); }
	;

assign_stmt: IDENTIFIER ASSIGN expr	{ Emplace<AssignNode>($$, $1, Extract($3)); }
	;

print_stmt: PRINT expr	{ Emplace<PrintNode>($$, Extract($2)); }
	;

for_stmt: FOR expr block	{ Emplace<ForStmtNode>($$, Extract($2), Extract($3)); }
	;

if_stmt[result]: IF expr[condition] block[ifBlock] ELSE block[thenBlock]	{ 
		Emplace<IfStmtNode>($result, Extract($condition), Extract($ifBlock), Extract($thenBlock)); 
		}
	;

expr: mul_expr				{ std::swap($$, $1); }
	| expr PLUS mul_expr	{ Emplace<BinaryCalcNode>($$, Extract($1), Extract($3), Operation::ADD); }
	| expr MINUS mul_expr	{ Emplace<BinaryCalcNode>($$, Extract($1), Extract($3), Operation::SUB); }
	;

mul_expr: unary_expr				{ std::swap($$, $1); }
	| mul_expr MULTIPLY unary_expr	{ Emplace<BinaryCalcNode>($$, Extract($1), Extract($3), Operation::MUL); }
	| mul_expr DIVIDE unary_expr	{ Emplace<BinaryCalcNode>($$, Extract($1), Extract($3), Operation::DIV); }
	;

unary_expr: symbol		{ std::swap($$, $1); }
	| PLUS symbol		{ Emplace<UnaryCalcNode>($$, Extract($2), Operation::ADD); }
	| MINUS symbol		{ Emplace<UnaryCalcNode>($$, Extract($2), Operation::SUB); }
	;
  
symbol: DOUBLE					{ $$ = new TermCalcNode($1); }
	| IDENTIFIER				{ $$ = new VariableRefNode($1); }
	| LEFT_P expr RIGHT_P		{ std::swap($$, $2); }
	;

%%

void calc::Parser::error (const calc::Parser::location_type& loc, const std::string& msg) 
{
	driver.Error(msg, loc);
}
