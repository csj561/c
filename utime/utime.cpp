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
} 

{
	if(0>utime(argv[1],NULL))
		cout<<"utime err"<<endl;