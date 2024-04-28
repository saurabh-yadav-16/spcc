%{
#include "y.tab.h"
%}

%%
[a-zA-Z][a-zA-Z0-9]*   { yylval.str = strdup(yytext); return IDENTIFIER; }
.                       { return *yytext; }
%%

int yywrap() {
    return 1;
}
