#include<iostream>
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
using namespace std;

int system(const char *cmd){
  pid_t pid;

  if((pid = fork()) == -1){
    perror("Fork failure");
    return -1;
  }

  if(pid == 0){
    execl("/bin/sh", "sh","-c", cmd, NULL);
    _exit(127);
  }
  else if(pid > 0){
    int status;

    if(waitpid(pid, &status, 0) == -1){
      perror("Wait failed");
      return -1;
    }
    return status;
  }
}

int main(int argc, char const *argv[]) {
  cout << "Enter a command to execute : " ;
  string str;

  cin >> str;

  system(str.c_str());
  return 0;
}
