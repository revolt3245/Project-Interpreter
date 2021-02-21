%{
#include "parser.hpp"

#define YY_NEVER_INTERACTIVE 1
%}

letter	[A-Za-z]
digit	[0-9]
id		{letter}({letter}|{digit})
%%
"("		return yytext[0];
"*"		return yytext[0];
")"		return yytext[0];
"+"		return yytext[0];
{id}	return ID;

[ \n\t\b]	;
%%