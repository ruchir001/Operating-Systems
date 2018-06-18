#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
int main()
{
    pid_t child_pid = fork();
    int status;
    // Parent process 
    if (child_pid > 0)
	{
		printf("Child Pid=%d  parent pid = %d and Parent's Parent pid = %d",child_pid, getpid(),getppid());
		
        	sleep(6);
		
	}
 
    // Child process
    else    
	{
		printf("Child pid = %d and Parent pid= %d", getpid(),getppid()); 
		
        	exit(0);
	}
 
    return 0;
}

