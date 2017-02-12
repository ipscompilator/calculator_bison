/* prologue */

%defines

/* Skeleton implementation for Bison LALR(1) parsers in C++ */
%skeleton "lalr1.cc"
%define parser_class_name {Parser}

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
    | program expr EOL      { driver.setCalcNode($2); driver.printResult(); }
    | program expr END      { driver.setCalcNode($2); driver.printResult(); }
    ;

expr: DOUBLE              { $$ = new TermCalcNode($1); std::cout << "double "; }
    | expr PLUS expr      { $$ = new BinaryCalcNode($1, $3, Operation::ADD); std::cout << "plus "; }
    | expr MINUS expr     { $$ = new BinaryCalcNode($1, $3, Operation::SUB); }
    | expr MULTIPLY expr  { $$ = new BinaryCalcNode($1, $3, Operation::MUL); std::cout << "mult "; }
    | expr DIVIDE expr    { $$ = new BinaryCalcNode($1, $3, Operation::DIV); }
    | PLUS expr           { $$ = new UnaryCalcNode($2, Operation::ADD); }
    | MINUS expr          { $$ = new UnaryCalcNode($2, Operation::SUB); std::cout << "unary ";}
    | LEFT_P expr RIGHT_P { $$ = $2; }
    ;

%%

void calc::Parser::error(const std::string& msg)
{
    driver.error(msg);
}