#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#if 1
#define perr(x,...) do{fprintf(stderr,"ERROR : %s %d:"x"\n",__FILE__,__LINE__,##__VA_ARGS__);}while(0)
#define pwar(x,...) do{fprintf(stderr,"WARNING : %s %d:"x"\n",__FILE__,__LINE__,##__VA_ARGS__);}while(0)
#else
#define perr(x,...) do{}while(0)
#define pwar(x,...) do{}while(0)
#endif
int *get_fds(pid_t pid)
{
	const char *fd_path_mode="/proc/%d/fd";
	char buf[32];
	DIR *dp;
	struct dirent dirent_buf,*dirent_p=NULL;
	int *ret=NULL;
	int cnt=0,i=0;
	sprintf(buf,fd_path_mode,pid);
	if((dp=opendir(buf))==NULL)
	{
		perr("Open %s error\n%s",buf,strerror(errno));
		return NULL;
	}
	while(1)
	{
		if(readdir_r(dp,&dirent_buf,&dirent_p)<0)
		{perr("%s",strerror(errno));closedir(dp);return NULL;}
		if(!dirent_p)
			break;
		if(strcmp(dirent_p->d_name,".")&&strcmp(dirent_p->d_name,".."))
			cnt++;
	}
	if((ret=malloc((cnt+1)*sizeof(int)))==NULL)
	{
		perr("%s",strerror(errno));closedir(dp);return NULL;
	}
	while(i<=cnt)
		ret[i++]=-1;
	seekdir(dp,0);
	i=0;
	while(i!=cnt)
	{
		if(readdir_r(dp,&dirent_buf,&dirent_p)<0)
		{perr("%s",strerror(errno));closedir(dp);return NULL;}
		if(!dirent_p)
			break;
		if(strcmp(dirent_p->d_name,".")&&strcmp(dirent_p->d_name,".."))
			ret[i++]=atoi(dirent_p->d_name);
	}
	closedir(dp);
	return ret;
}

int system2(const char * cmdstring)
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
		int i=0,*fds=get_fds(getpid());
		//while(fds&&fds[i]!=-1)
		//	close(fds[i++]);
		execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);exit(127); 
	} 
	else
	{ 
		while(waitpid(pid, &status, 0) < 0)
		{
			status = -EINTR; break;
		}
	} 
	return status; 
} 
int main(int argc,char** argv)
{
	system2(argv[1]);
	return 0;
}