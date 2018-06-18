#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t pid;
    pid = fork();
    if (pid == 0) {
	
        //system("ps aux");
	system("ps");
	
    } else {
        
	printf("Child pid= %d, Parent pid=%d", pid,getpid());
	sleep(5);
	system("ps");
            kill(pid, SIGKILL);
	printf("Child killed");
		
	
    }
    return 0;
}	
