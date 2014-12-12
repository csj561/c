
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <utime.h>
#include <stdlib.h>

void f1(void )
{
	printf("%s\n",__func__);
}
void f2(void )
{
	printf("%s\n",__func__);
}void main (int argc, char **argv) 
{
	atexit(&f1);
	atexit(&f2);
	//exit(0);	//return 0;}
