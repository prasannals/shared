#include<iostream>
#include<stdio.h>
#include<unistd.h>
using namespace std;

int main(int argc, char const *argv[]) {
  if(link(argv[1], argv[2]) == -1){
    perror("Link failed");
    return -1;
  }

  cout << "Link successful" << endl;
  return 0;
}
