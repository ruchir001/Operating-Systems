#include<stdio.h>
int main()
{
        int i;
        printf("hello before fork \n");
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
         printf("parent has started\n");
         printf("getpid : %d  getppid : %d \n",getpid(),getppid());
         printf("\n");

        }
        return 0;


}

