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

    #undef yylex
    #define yylex driver.getScanner().lex
%}

%token<double>  DOUBLE
%left PLUS MINUS
%left MULTIPLY DIVIDE
%left LEFT_P RIGHT_P
%token END     0   "end of file"
%token EOL     "end of line"

%type<double>   expr

%start program

%%

/* rules section */

program: /* empty */
    | program EOL
    | program expr EOL      { driver.setResultValue($2); }
    | program expr END      { driver.setResultValue($2); }
    ;

expr: DOUBLE              { $$ = $1; }
    | expr PLUS expr      { $$ = $1 + $3; }
    | expr MINUS expr     { $$ = $1 - $3; }
    | expr MULTIPLY expr  { $$ = $1 * $3; }
    | expr DIVIDE expr    { $$ = $1 / $3; }
    | PLUS expr           { $$ = $2; }
    | MINUS expr          { $$ = -$2; }
    | LEFT_P expr RIGHT_P { $$ = $2; }
    ;

%%

void calc::Parser::error(const std::string& msg)
{
    driver.error(msg);
}