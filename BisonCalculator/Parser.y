/* prologue */

%defines

/* Skeleton implementation for Bison LALR(1) parsers in C++ */
%skeleton "lalr1.cc"
%define parser_class_name {Parser}
%locations

%define api.namespace {calc}
%define api.value.type variant
%define api.token.constructor
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

%token<double>  DOUBLE
%left PLUS MINUS
%left MULTIPLY DIVIDE
%left LEFT_P RIGHT_P
%token END     0   "end of file"
%token EOL     "end of line"

%type<class CalcNode *>   expr

%start program

%%

/* rules section */

program: /* empty */
    | program EOL
    | program expr EOL      { driver.setCalcNode(Extract($2)); }
    | program expr END      { driver.setCalcNode(Extract($2)); }
    ;

expr: DOUBLE              { $$ = new TermCalcNode($1); }
    | expr PLUS expr      { Emplace<BinaryCalcNode>($$, Extract($1), Extract($3), Operation::ADD); }
    | expr MINUS expr     { Emplace<BinaryCalcNode>($$, Extract($1), Extract($3), Operation::SUB); }
    | expr MULTIPLY expr  { Emplace<BinaryCalcNode>($$, Extract($1), Extract($3), Operation::MUL); }
    | expr DIVIDE expr    { Emplace<BinaryCalcNode>($$, Extract($1), Extract($3), Operation::DIV); }
    | PLUS expr           { Emplace<UnaryCalcNode>($$, Extract($2), Operation::ADD); }
    | MINUS expr          { Emplace<UnaryCalcNode>($$, Extract($2), Operation::SUB); }
    //| MINUS expr          { $$ = new UnaryCalcNode(std::unique_ptr<CalcNode>($2), Operation::SUB); }
    | LEFT_P expr RIGHT_P { $$ = $2; }
    ;

%%

void calc::Parser::error(const location & l, const std::string& msg)
{
    driver.error(msg, l);
}