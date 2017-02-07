/* prologue */

%defines

/* Skeleton implementation for Bison LALR(1) parsers in C++ */
%skeleton "lalr1.cc"
%define parser_class_name {Parser}

%define api.value.type variant
%define api.token.constructor
%define api.token.prefix {TOK_}

%parse-param { class Driver& driver }

/* verbose error messages */
%error-verbose

%{
    #include "stdafx.h"
    #include "Driver.h"

    #undef yylex
    #define yylex driver.scanner->lex
%}

%token<double>  DOUBLE
%token          LEFT_P
%token          RIGHT_P
%token          PLUS
%token          MINUS
%token          MULTIPLY
%token          DIVIDE
%token          END     0   "end of file"
%token          EOL     "end of line"

%type<double>   sum_expr
%type<double>   mul_expr
%type<double>   unary_expr
%type<double>   symbol

%start program

%%

/* rules section */

program: /* empty */
    | program sum_expr EOL      { driver.setResultValue($2); }
    | program sum_expr END      { driver.setResultValue($2); }
    ;

sum_expr: mul_expr              { $$ = $1; }
    | sum_expr PLUS mul_expr    { $$ = $1 + $3; }
    | sum_expr MINUS mul_expr   { $$ = $1 - $3; }
    ;

mul_expr: unary_expr                { $$ = $1; }
    | mul_expr MULTIPLY unary_expr  { $$ = $1 * $3; }
    | mul_expr DIVIDE unary_expr    { $$ = $1 / $3; }
    ;

unary_expr: symbol  { $$ = $1; }
    | PLUS symbol   { $$ = $2; }
    | MINUS symbol  { $$ = -$2; }
    ;

symbol: DOUBLE                  { $$ = $1; }
    | LEFT_P sum_expr RIGHT_P   { $$ = $2; }
    ;

%%

void yy::Parser::error(const std::string& msg)
{
    driver.error(msg);
}