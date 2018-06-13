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
	break;
case 0:printf("the child went in sleep now\n");
sleep(2); //child runs
printf("pid_t in child=%d\n",pid);
break ;
default: died=wait(&status); // parent runs
printf("pid_t=%d\n",pid);
}
}
