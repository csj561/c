#include <string>
#include <iostream>
#include <cstdio>
extern "C"
{
  
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
} 

{ 
	pid_t pid; 
	int status; 
	if(cmdstring == NULL)
	{ 
		return (1); 
	} 
	if((pid = fork())<0)
	{ 
		status = -1; 
	} 
	else if(pid = 0)
	{
		execl("/bin/sh", "sh", "-c", cmdstring, (char *)0); -exit(127); 
	} 
	else
	{ 
		while(waitpid(pid, &status, 0) < 0)
		{
			if(errno != EINTER){ status = -1; break; 
			} 
		}
	} 
	return status; 
} 


main (int argc, char **argv) 
{
  
  
  
  
  
  
  
  
  
  
