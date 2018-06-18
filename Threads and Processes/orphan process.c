#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
int main()
{
    // Fork returns process id
    // in parent process
    pid_t child_pid = fork();
    int status;
    // Parent process 
    if (child_pid > 0)
	{
		printf("Before Child Pid=%d  parent pid = %d and Parent's Parent pid = %d",child_pid, getpid(),getppid());
		sleep(3);
		
		
	}
 
    // Child process
    else    
	{
		
		
        	exit(0);

        	
	}
 
    return 0;
}

