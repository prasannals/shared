#include<iostream>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
using namespace std;


int main(int argc, char const *argv[]) {

  if(mkfifo(argv[1], S_IFIFO | S_IRWXU | S_IRWXG | S_IRWXO) == -1){
    perror("Couldn't create fifo");
    return -1;
  }

  int fd;

  if((fd = open(argv[1], O_RDWR | O_NONBLOCK)) == -1){
    perror("Couldn't open fifo");
    return -1;
  }

  int n;

  if((n = write(fd, argv[2], strlen(argv[2]))) <= 0){
    perror("Couldn't write to fifo");
    return -1;
  }

  char buf[256];

  if(read(fd, buf, n) != n ){
    perror("Couldn't read from fifo");
    return -1;
  }

  cout << "The contents of the fifo are : " << buf << endl;

  return 0;
}
