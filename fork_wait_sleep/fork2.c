//System name. OS versions,machine architecture, used physical mem, used virtual mem, no of current process, uptime,
#include<stdio.h>
//#include<sys/sysvyf.h>
#include<sys/sysinfo.h>
#include<sys/utsname.h>
int main()
{
int r,a,q,p,b;
struct sysinfo s1; //analyse three structures TASK 2
struct utsname s2;
struct statfs s3;
r=sysinfo(&s1);
q=uname(&s2);
p=statfs("./",&s3);
a=(1024*1024);
b=(a*1024);
if(r==0&&q==0&&p==0)
{
printf("\nSystem name:%s",s2.sysname);
printf("\nVersion:%s",s2.version);
printf("\nRelease:%s",s2.release);
printf("\nMachine:%s",s2.machine);
printf("\nUptime:%ldsecond",s1.uptime);
printf("\nNo ofcurrent process: %d",s1.procs);
printf("\nTotal RAM: %ldMB",(s1.totalram/a));
printf("\nFree RAM: %ldMB",(s1.freeram/a));
printf("\nUsed RAM: %ldMB",(s1.totalram-s1.freeram)/a);
printf("\nTotal Swap space : %ldMB",(s1.totalswap/a)); //swap space is virtual mem(swapin/swapout-transferringb/w Ram and hardisk)
printf("\nFree Swap space : %ldMB",(s1.freeswap/a));
printf("\nUsed Swap space : %ldMB",(s1.totalswap-s1.freeswap)/a);
printf("\nTotal sizeofpartition: %ldGB",(s3.f_bsize*s3.f_blocks)/b);

}

}



