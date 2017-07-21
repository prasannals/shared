%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>
#define MAX 100

char productions[MAX][MAX],temp[MAX + MAX];
int count = 0;

%}

%token ALPHABET
%left '|'
%left '.'

%nonassoc '*''+'


%%
S : re'\n' {
  printf("Parse Tree is - \n\n");

  printf("=>");
}

re : ALPHABET{
  temp[0] = yylval; temp[1] = '\0';
  strcpy(productions[count++], temp);
}

| '(' re ')' {strcpy(productions[count++], "(re)"); }
| re '+' re {strcpy(productions[count++], "re+re"); }
| re '*' re {strcpy(productions[count++], "re*re"); }
| re '.' re {strcpy(productions[count++], "re.re"); }
| re '|' re {strcpy(productions[count++], "re|re"); }
;
%%

int main(){
  yyparse();
return 0;
}

yylex(){
  char inp = getchar();
  yylval = inp;

  if(isalpha(inp))
    return ALPHABET;

  return (int)inp;
}

yyerror(){
  printf("Invalid RE\n");
  exit(-1);
}


int getREindex(char *str){

  for(int i = strlen(str) - 1; i > 0; i--){
    if(str[i] == 'e' && str[i - 1] == 'r')
      return i -1;
  }

}
