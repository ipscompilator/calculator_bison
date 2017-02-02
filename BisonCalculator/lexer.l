%option noyywrap

%top{
	#pragma warning(disable:4996)
}

%{
	#include <cstdlib>
	#include "parser.hpp"
	
	// this function will be generating by bison
	extern int yyparse();
%}

digits		[0-9]+|[0-9]+\.[0-9]+
binopr		[-+*/]
parenthesis [()]

%%
{digits}	{ 
				yylval.dbl = atof(yytext); 
				return LITERAL_DBL;
			}

{binopr}		{ return yytext[0]; }
{parenthesis}	{ return yytext[0]; }
\n				{ return '\n'; }
.

%%