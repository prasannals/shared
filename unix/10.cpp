#include<stdio.h>
#include<iostream>
#include<signal.h>
#include<unistd.h>
#define INTERVAL 2
using namespace std;


void handler(int signum){
  cout << "Cought a signal with number : " << signum << endl;
  alarm(INTERVAL);
}

int main(int argc, char const *argv[]) {
  struct sigaction act;

  sigemptyset(&act.sa_mask);

  act.sa_handler = handler;
  act.sa_flags = SA_RESTART;

  sigaction(SIGALRM, &act, 0);

  alarm(INTERVAL);

  while(1){}

  return 0;
}
