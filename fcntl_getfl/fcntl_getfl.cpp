#include <string>
#include <iostream>
#include <cstdio>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

int main(int argc,char **argv)
{
	int fd=0;
	int flags=0;
	if(argc!=2)
	{cout<<"Two argument"<<endl;return -1;}
	if((fd=open(argv[1],O_WRONLY))<0)
	{perror("open");return -1;}
	if((flags= fcntl(fd,F_GETFL,0))<0)
	{perror("fcntl");return -1;}
	if((flags&O_ACCMODE)==O_RDONLY)
		cout<<"O_RDONLY"<<endl;
	else if ((flags&O_ACCMODE)==O_WRONLY)
		cout<<"O_WRONLY"<<endl;
	else if ((flags&O_ACCMODE)==O_RDWR)
		cout<<"O_RDWR"<<endl;
	else
		cout<<"unknown"<<endl;
	close(fd);
	return 0;
}