%{
#include <stdio.h>
extern int yylex();
extern char *yytext;
extern FILE *yyin;
%}

%token IDENTIFIER

%%
input: IDENTIFIER { printf("%s is an identifier.\n", $1); }
     | error { printf("Invalid input.\n"); }
     ;
%%

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }
    yyin = fp;
    yyparse();
    fclose(fp);
    return 0;
}
