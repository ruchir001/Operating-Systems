#include<iostream>
using namespace std;
class process
{
public:
	char name[20];
	int burst,remain;
	int arrival;
	int priority;
	int wait,turn;
};
void roundrobin()
{
  int n,time_quantum;
  int wait_time=0,turnaround_time=0;
  cout<<"Enter Total Process:\t ";
  cin>>n;
  process p[n];
  for(int i=0;i<n;i++)
  {
    cout<<"Enter Name,Arrival Time and Burst Time for Process "<<(i+1)<<"\n";
    cin>>p[i].name>>p[i].arrival;
    cin>>p[i].burst;
    p[i].remain=p[i].burst;
  }
  cout<<"Enter time Quantum";
  cin>>time_quantum;
  cout<<"\n\nProcess\t|Turnaround Time|Waiting Time\n\n";
 int x=n,i=0,time=0,flag=0;
 while(x!=0)
 {
    if(p[i].remain<=time_quantum && p[i].remain>0)
    {
      time+=p[i].remain;
      p[i].remain=0;
      flag=1;
    }
    else if(p[i].remain>0)
    {
      p[i].remain-=time_quantum;
      time+=time_quantum;
    }
    if(p[i].remain==0 && flag==1)
    {
      x--;
      cout<<p[i].name<<"\t\t"<<time-p[i].arrival<<"\t\t"<<time-p[i].arrival-p[i].burst<<"\n";
      wait_time+=time-p[i].arrival-p[i].burst;
      turnaround_time+=time-p[i].arrival;
      flag=0;
    }
    if(i==n-1)
      i=0;
    else if(p[i+1].arrival<=time)
      i++;
    else
      i=0;
}
cout<<"\nAverage Waiting Time= "<<wait_time*1.0/n;
cout<<"\nAvg Turnaround Time = "<<turnaround_time*1.0/n;
}

void srt()
{
      int n,count=0,smallest;
  float wait_time=0,turnaround_time=0;
  cout<<"Enter Total Process:\t ";
  cin>>n;
  process p[n+1];
  for(int i=0;i<n;i++)
  {
    cout<<"Enter Name,Arrival Time and Burst Time for Process "<<(i+1)<<"\n";
    cin>>p[i].name>>p[i].arrival;
    cin>>p[i].burst;
    p[i].remain=p[i].burst;
  }
cout<<"\n\nProcess\t|Turnaround Time|Waiting Time\n\n";
 int time=0;
 p[n].remain=99999;
smallest=n;
while(count < n)
      {
            for(int i = 0; i < n; i++)
            {
                  if(p[i].arrival <= time && p[smallest].remain>0&&p[i].remain < p[smallest].remain && p[i].remain > 0)
                  {
                        smallest = i;
                  }
            }
            time=time+1;
            p[smallest].remain--;
            if(p[smallest].remain == 0)
            {
                  count++;
                  cout<<p[smallest].name<<"\t\t"<<time - p[smallest].arrival<<"\t\t"<<time - p[smallest].arrival - p[smallest].burst<<"\n";
                  wait_time = wait_time + time - p[smallest].arrival - p[smallest].burst;
                  turnaround_time = turnaround_time + time - p[smallest].arrival;
                  smallest=n;
            }
      }

      cout<<"\n\nAverage Waiting Time:\t"<<wait_time *1.0/ n;
      cout<<"\nAverage Turnaround Time:\t"<< turnaround_time *1.0/ n;
}


void priority()
{
  int n,count=0,dominant;
  float wait_time=0,turnaround_time=0;
  cout<<"Enter Total Process:\t ";
  cin>>n;
  process p[n+1];
  for(int i=0;i<n;i++)
  {
    cout<<"Enter Name,Arrival Time, Burst Time and Priority for Process "<<(i+1)<<"\n";
    cin>>p[i].name>>p[i].arrival;
    cin>>p[i].burst>>p[i].priority;
    p[i].remain=p[i].burst;
  }
cout<<"\n\nProcess\tPriority\t|Turnaround Time|Waiting Time\n\n";
 int time=0;
 p[n].priority=99999;
 p[n].remain=12;
dominant=n;
while(count < n)
      {
            for(int i = 0; i < n; i++)
            {
                  if(p[i].arrival <= time && p[dominant].remain>0&&p[i].priority < p[dominant].priority && p[i].remain > 0)
                  {
                        dominant = i;
                  }
            }
            time=time+1;
            p[dominant].remain--;
            if(p[dominant].remain == 0)
            {
                  count++;
                  cout<<p[dominant].name<<"\t"<<p[dominant].priority<<"\t\t"<<time - p[dominant].arrival<<"\t\t"<<time - p[dominant].arrival - p[dominant].burst<<"\n";
                  wait_time = wait_time + time - p[dominant].arrival - p[dominant].burst;
                  turnaround_time = turnaround_time + time - p[dominant].arrival;
                  dominant=n;
            }
      }

      cout<<"\n\nAverage Waiting Time:\t"<<wait_time *1.0/ n;
      cout<<"\nAverage Turnaround Time:\t"<< turnaround_time *1.0/ n;
}

int main()
{
int ch;
while(ch!=4)
{
cout<<"\nPreemptive Scheduling\n\n1. Round Robin\n2. Shortest Remaining Time\n3. Preemptive Priority\n4. Exit\nEnter your choice:  ";
cin>>ch;
switch(ch)
{
case 1: roundrobin();
break ;
case 2: srt();
break ;
case 3: priority();
break ;
case 4: break;
default: cout<<"\n\nWRONG CHOICE!!";
break;
}
}
}



