#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
extern "C"
{
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <utime.h>
} using namespace std;
int main (int argc, char **argv) 
{
	if(0>utime(argv[1],NULL))
		cout<<"utime err"<<endl;	return 0;}
