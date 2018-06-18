#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
// Let us create a global variable to change it in threads
int g = 0;
// The function to be executed by all threads
void *myThreadFun(void *data)
{
// Store the value argument passed to this thread
int *intPTR = (int *) data;
int myid = *intPTR;
// Let us create a static variable to observe its changes
int s = 0;
// Change static and global variables
++s;
++g;
// Print the argument, static and global variables
printf("Thread ID: %d, Static: %d, Global: %d\n", myid, s,g);
}
int main()
{
int i;
pthread_t thread_id;
// Let us create three threads
for (i=0;i<3;i++)
{
pthread_create(&thread_id,NULL,myThreadFun,(void *)
(&i));
sleep(1);
}
pthread_exit(NULL);
return 0;
}

