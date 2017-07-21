#include<iostream>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

using namespace std;


int main(int argc, char const *argv[]) {
  int fd;

  if((fd = open(argv[1], O_RDWR)) == -1){
    perror("Open error");
    return -1;
  }

  struct flock fvar;

  fvar.l_type = F_WRLCK;
  fvar.l_whence = SEEK_END;
  fvar.l_start = -100;
  fvar.l_len = 100;
  fvar.l_pid = getpid();

  if(fcntl(fd, F_SETLK, &fvar) == -1){
    perror("Coudln't set lock");
    return -1;
  }

  if(fcntl(fd, F_GETLK, &fvar) == -1){
    perror("Couldn't obtain lock");
  }

  fvar.l_type = F_UNLCK;
  fvar.l_whence = SEEK_END;
  fvar.l_start = -50;
  fvar.l_len = 50;
  fvar.l_pid = getpid();

  if(fcntl(fd, F_SETLK, &fvar) == -1){
    perror("Couldn't unlock");
    return -1;
  }

  lseek(fd, -50, SEEK_END);

  char buf[100];

  if(read(fd, buf, 50) <= 0){
    perror("Couldn't read");
    return -1;
  }

  cout << "The contents of the buffer : " << buf << endl;

  return 0;
}
