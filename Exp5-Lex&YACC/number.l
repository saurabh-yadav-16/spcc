%{
#include "y.tab.h"
%}

%%
[0-9]+          { yylval.num = atoi(yytext); return INTEGER; }
[0-9]+"."[0-9]+ { yylval.fnum = atof(yytext); return FLOAT; }
.               { return *yytext; }
%%

int yywrap() {
    return 1;
}
