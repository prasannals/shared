#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

using namespace std;


int main(int argc, char const *argv[]) {
  pid_t pid;

  if((pid = fork()) == -1){
    perror("Fork failed");
    return -1;
  }

  if(pid == 0){
    exit(0);
  }

  if(pid > 0){
    sleep(2);
    system("ps u");
  }

  return 0;
}
