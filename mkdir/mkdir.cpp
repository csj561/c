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
	mode_t mode=07;
	mkdir("1",0666);
	umask(mode);
	mkdir("2",0666);