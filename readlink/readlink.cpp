#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
extern "C"
{
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
} using namespace std;
int main (int argc, char **argv) 
{
	const int K=1024;
	char buf[K];
	memset(buf,0,K);
	readlink(argv[1],buf,K);
	puts(buf);	return 0;}
