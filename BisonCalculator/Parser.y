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
    #include "Driver.h"
    #include "CalcNode.h"
    #include "UnaryCalcNode.h"
    #include "BinaryCalcNode.h"
    #include "TermCalcNode.h"

    #undef yylex
    #define yylex driver.getScanner().lex
%}

%union {
    class CalcNode * calcNode;
    double  doubleVal;
}

%destructor { delete $$; } sum_expr mul_expr unary_expr symbol

%token<doubleVal>  DOUBLE
%left PLUS MINUS
%left MULTIPLY DIVIDE
%left LEFT_P RIGHT_P
%token END     0   "end of file"
%token EOL     "end of line"

%type<calcNode> sum_expr mul_expr unary_expr symbol 

%start program

%%

/* rules section */

program: /* empty */
    | program EOL
    | program sum_expr EOL      { driver.setCalcNode(Extract($2)); }
    | program sum_expr END      { driver.setCalcNode(Extract($2)); }
    ;

sum_expr: mul_expr              { std::swap($$, $1); }
    | sum_expr PLUS mul_expr    { Emplace<BinaryCalcNode>($$, Extract($1), Extract($3), Operation::ADD); }
    | sum_expr MINUS mul_expr   { Emplace<BinaryCalcNode>($$, Extract($1), Extract($3), Operation::SUB); }
    ;

mul_expr: unary_expr                { std::swap($$, $1); }
    | mul_expr MULTIPLY unary_expr  { Emplace<BinaryCalcNode>($$, Extract($1), Extract($3), Operation::MUL); }
    | mul_expr DIVIDE unary_expr    { Emplace<BinaryCalcNode>($$, Extract($1), Extract($3), Operation::DIV); }
    ;

unary_expr: symbol  { std::swap($$, $1); }
    | PLUS symbol   { Emplace<UnaryCalcNode>($$, Extract($2), Operation::ADD); }
    | MINUS symbol  { Emplace<UnaryCalcNode>($$, Extract($2), Operation::SUB); }
    ;
  
symbol: DOUBLE                  { $$ = new TermCalcNode($1); }
    | LEFT_P sum_expr RIGHT_P   { std::swap($$, $2); }
    ;

%%

void calc::Parser::error (const calc::Parser::location_type& loc, const std::string& msg) 
{
    driver.error(msg, loc);
}
