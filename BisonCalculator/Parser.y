/* prologue */

%defines

/* Skeleton implementation for Bison LALR(1) parsers in C++ */
%skeleton "lalr1.cc"
%define parser_class_name {Parser}
%locations

%define api.namespace {calc}
%define api.token.prefix {TOK_}

%parse-param { class Driver& driver }

/* verbose error messages */
%error-verbose

%{
	#include "stdafx.h"
	#include "ParserHeaders.h"

	#undef yylex
	#define yylex driver.GetScanner().Lex
%}

%union {
	class CalcNode * calcNode;
	class StatementNode * statementNode;
	double doubleVal;
	unsigned stringId;
}

%destructor { delete $$; } expr mul_expr unary_expr symbol

%token<doubleVal> DOUBLE
%token<stringId> IDENTIFIER
%left PRINT
%left PLUS MINUS
%left MULTIPLY DIVIDE
%left LEFT_P RIGHT_P
%right ASSIGN
%token END	 0	"end of file"
%token EOL	"end of line"

%type<calcNode> expr mul_expr unary_expr symbol 
%type<statementNode> statement statement_list

%start program

%%

/* rules section */

program: /* empty */
	| program EOL
	| program statement_list END
	| program statement_list EOL END
	;

statement_list: statement
	| statement_list EOL statement
	;

statement: IDENTIFIER ASSIGN expr	{ auto node = std::make_unique<AssignNode>($1, Extract($3)); driver.AddStatement(std::move(node)); }
	| PRINT expr					{ auto node = std::make_unique<PrintNode>(Extract($2)); driver.AddStatement(std::move(node)); }
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
