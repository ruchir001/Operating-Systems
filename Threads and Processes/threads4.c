#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
void * func(void * param){
printf(“Inside Thread function\n”);
char ** var = (char **)param;
printf(“The passed argument is \”%s\”\n”, *var);
int * i;
i=(int *)malloc(4);
*i=100;
pthread_exit((void*)i);
}
int main(int argc, char * argv[])
{ //Argument to be passed as command line argument
int * retval;
retval = (int *)malloc(4);
pthread_t tid;
pthread_attr_t attr;
pthread_attr_init(&attr);
pthread_create(&tid,&attr,func,&argv[1]);
pthread_join(tid, (void **)&retval);
printf(“retval is %d\n”, *retval);
}
