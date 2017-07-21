#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L

#include<stdio.h>
#include<unistd.h>
#include<iostream>

using namespace std;

int main(){

#ifdef _POSIX_JOB_CONTROL
  cout << "_POSIX_JOB_CONTROL enabled" << endl;
#else
  cout << "_POSIX_JOB_CONTROL Disabled" << endl;
#endif

#ifdef _POSIX_SAVED_IDS
  cout << "_POSIX_SAVED_IDS enabled" << endl;
#else
  cout << "_POSIX_SAVED_IDS Disabled" << endl;
#endif

#ifdef _POSIX_CHOWN_RESTRICTED
  cout << "_POSIX_CHOWN_RESTRICTED enabled" << endl;
#else
  cout << "_POSIX_CHOWN_RESTRICTED Disabled" << endl;
#endif

#ifdef _POSIX_NO_TRUNC
  cout << "_POSIX_NO_TRUNC enabled" << endl;
#else
  cout << "_POSIX_NO_TRUNC Disabled" << endl;
#endif

#ifdef _POSIX_VDISABLE
  cout << "_POSIX_VDISABLE enabled" << endl;
#else
  cout << "_POSIX_VDISABLE Disabled" << endl;
#endif


  return 0;
}
