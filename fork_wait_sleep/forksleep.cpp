#include<stdio.h>
#include<sys/wait.h>
//#include<iostream>
int main()
{
pid_t pid;
int status,died;
switch(pid=fork())
{
case -1: printf("can't fork \n");
	break ;
case 0: sleep(2); //child runs
break ;
default: died=wait(&status); // parent runs
}
}
