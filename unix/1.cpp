#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L

#include<stdio.h>
#include<unistd.h>
#include<iostream>

using namespace std;


int main(){

  int val;
  if((val = sysconf(_SC_CLK_TCK)) == -1){
    perror("Clock tick");
  }else{
    cout << "Clock ticks : " << val<< endl;
  }

  if((val = sysconf(_SC_CHILD_MAX)) == -1){
    perror("Child max");
  }else{
    cout << "Child Max : " << val<< endl;
  }

  if((val = sysconf(_SC_OPEN_MAX)) == -1){
    perror("Open Max");
  }else{
    cout << "Open Max : " << val<< endl;
  }

  if((val = pathconf("/", _PC_PATH_MAX)) == -1){
    perror("Path length");
  }else{
    cout << "Path length : " << val<< endl;
  }

  if((val = pathconf("/", _PC_NAME_MAX)) == -1){
    perror("Name Max");
  }else{
    cout << "Name Max : " << val + 1  << endl;
  }

  return 0;
}
