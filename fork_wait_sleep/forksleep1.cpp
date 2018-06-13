#include<unistd.h>
#include<sys/wait.h>
#include<iostream>
using namespace std;
int main()
{
pid_t pid;
int status,died;
switch(pid=fork())
{
case -1: cout<<"can't fork \n";
	return(-1);
case 0:cout<<"the child went in sleep now\n";
sleep(2); //child runs
cout<<"pid_t in child=%d\n"<<pid;
break ;
default: died=wait(&status); // parent runs
cout<<"pid_t=%d\n"<<pid;
}
}
