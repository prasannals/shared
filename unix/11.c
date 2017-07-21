#include<stdio.h>
#include<string.h>


char buf[3][100], inp[100];
int num = 0;

void printMess(){
  int L1 = 101, L2 = 102, L3 = 103;

  printf("if %s goto %d\n", buf[0], L1);
  printf("goto %d\n", L2);

  printf("%d: %s\n", L1, buf[1]);

  if(num == 2){
    printf("%d: STOP\n", L2);
  }else if(num == 3){
    printf("goto %d\n", L3);
    printf("%d: %s\n", L2, buf[2]);
    printf("%d: STOP\n", L3);
  }
}

int main(){
  printf("Usage : \n");

  printf("if(a>b) then(a=b);\n");
  printf("if(a>b) then(a=b) else(b=a);\n");

  printf("Enter one of the above statements\n\n");
  gets(inp);
  for(int i = 0; inp[i] != ';'; i++){
    if(inp[i] == '('){
      int k =0;
      int j;
      for(j = i ; inp[j] != ')'; j++){
        buf[num][k] = inp[j];
        k++;
      }
      buf[num][k] = inp[j];
      buf[num][k + 1] = '\0';
      num++;
      i = j;
    }
  }

  printMess();
  return 0;
}
