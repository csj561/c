#include <string>
#include <iostream>
#include <cstdio>
extern "C"
{
  
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
} using namespace std;
int system(const char * cmdstring)
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

int
main (int argc, char **argv) 
{
  int fd = 0;
  struct stat buf;
  fd = creat ("1", 0777);
  close (fd);
  fd = creat ("2", 0000);
  close (fd);
  stat ("1", &buf);
  chmod ("1", buf.st_mode | S_ISUID);
  chmod ("2", S_ISGID);
  return 0;
}
