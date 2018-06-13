#include<stdio.h>
int main()
{
int i;
printf("Hello before fork \n");
printf("i : %d\n",i);
i=fork();
printf("\n");
if(i==0)
{
printf("Child has started\n\n");
printf("getpid : %d getppid : %d \n",getpid(),getppid());
}
else
{
printf("Parent has started\n\n");
printf("getpid : %d getppid : %d \n",getpid(),getppid());
}
}
