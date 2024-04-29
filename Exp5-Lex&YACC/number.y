%{
#include <stdio.h>
extern int yylex();
extern double yylval;
extern FILE *yyin;
%}

%token INTEGER FLOAT

%%
input: INTEGER { printf("%d is an integer.\n", $1); }
     | FLOAT { printf("%f is a floating-point number.\n", $1); }
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
