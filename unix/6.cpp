#include<iostream>
#include<string.h>
#include<stdio.h>
#include<unistd.h>
using namespace std;


void charAtATime(const char *str){
  for(int i = 0; i < strlen(str); i++){
    cout << str[i];
  }

}


int main(int argc, char const *argv[]) {
  pid_t pid;

  if((pid = fork()) == -1){
    perror("Fork failed");
    return -1;
  }

  if(pid == 0){
    charAtATime("Message from child\n");
  }else if(pid > 0){
    charAtATime("Message from parent\n");
  }

  return 0;
}
