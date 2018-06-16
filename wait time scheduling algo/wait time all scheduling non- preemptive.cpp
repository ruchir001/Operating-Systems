#include<iostream>
using namespace std;
class process
{
public:
	char name[20];
	int duration;
	int order;
	int priority,arrival;
	int wait,turn;
};

void fcfs()
{
int n;float avgw=0,avgt=0;
cout<<"\nEnter the number of Processes  ";
cin>>n;
process p[n];
for(int i=0;i<n;i++)
{
cout<<"\n\nEnter the Process name, Duration, Order and Arrival Time of Process of  "<<(i+1)<<" Process\n";
cin>>p[i].name>>p[i].duration>>p[i].order>>p[i].arrival;

}
process temp;
for(int i=0;i<n;i++)
{
for(int j=i+1;j<n;j++)
{
if(p[i].order>p[j].order)
{
temp=p[i];
p[i]=p[j];
p[j]=temp;
}
}
}
cout<<"The Order of Processes is: ";
for(int i=0;i<n;i++)
{
cout<<"\n"<<p[i].name;
p[i].order=(i+1);
}
for(int i=0;i<n;i++)
{
if(i==0)
{p[i].wait=0;p[i].turn=p[i].wait+p[i].duration;avgt=avgt+p[i].turn;
}
else
{
	p[i].wait=p[i-1].turn-p[i].arrival;avgw=avgw+p[i].wait;p[i].turn=p[i].wait+p[i].duration;avgt=avgt+p[i].turn;}
}

for(int i=0;i<n;i++)
{
//System.out("cls");
cout<<"\n\nName \t\tDuration\t\t  Order\t\t  Arrival time\t\t   Wait Time\t\t  TurnAround Time\n";
cout<<"\n"<<p[i].name<<"\t\t\t"<<p[i].duration<<"\t\t\t"<<p[i].order<<"\t\t\t"<<p[i].arrival<<"\t\t\t"<<p[i].wait<<"\t\t\t"<<p[i].turn;
}

cout<<"\n\nAverage Waiting time: "<<avgw/n<<"\n\nAverage Turn Around time:"<<avgt/n<<"\n\n";
}


void sjf()
{

int n;float avgw=0,avgt=0;
cout<<"\nEnter the number of Processes  ";
cin>>n;
process p[n];
for(int i=0;i<n;i++)
{
cout<<"\n\nEnter the Process name, Duration, Order and Arrival Time of Process of  "<<(i+1)<<" Process\n";
cin>>p[i].name>>p[i].duration>>p[i].order>>p[i].arrival;

}
process temp;
for(int i=0;i<n;i++)
{
for(int j=i+1;j<n;j++)
{
if(p[i].duration>p[j].duration)
{
temp=p[i];
p[i]=p[j];
p[j]=temp;
}
}
}
cout<<"The Order of Processes is: ";
for(int i=0;i<n;i++)
{
cout<<"\n"<<p[i].name;
p[i].order=(i+1);
}
for(int i=0;i<n;i++)
{
if(i==0)
{p[i].wait=0;p[i].turn=p[i].wait+p[i].duration;avgt=avgt+p[i].turn;
}
else
{
	p[i].wait=p[i-1].turn-p[i].arrival;avgw=avgw+p[i].wait;p[i].turn=p[i].wait+p[i].duration;avgt=avgt+p[i].turn;}
}

for(int i=0;i<n;i++)
{
cout<<"\n\nName \t\tDuration\t\t  Order\t\t  Arrival time\t\t   Wait Time\t\t  TurnAround Time\n";
cout<<"\n"<<p[i].name<<"\t\t\t"<<p[i].duration<<"\t\t\t"<<p[i].order<<"\t\t\t"<<p[i].arrival<<"\t\t\t"<<p[i].wait<<"\t\t\t"<<p[i].turn;
}

cout<<"\n\nAverage Waiting time: "<<avgw/n<<"\n\nAverage Turn Around time:"<<avgt/n<<"\n\n";

}

void priority()
{
int n;float avgw=0,avgt=0;
cout<<"\nEnter the number of Processes  ";
cin>>n;
process p[n];
for(int i=0;i<n;i++)
{
cout<<"\n\nEnter the Process name, Duration, Priority and Arrival Time of Process of  "<<(i+1)<<" Process\n";
cin>>p[i].name>>p[i].duration>>p[i].priority>>p[i].arrival;
}
process temp;
for(int i=0;i<n;i++)
{
for(int j=i+1;j<n;j++)
{
if(p[i].priority>p[j].priority)
{
temp=p[i];
p[i]=p[j];
p[j]=temp;
}
}
}
cout<<"The Processes are processed in the order : ";
for(int i=0;i<n;i++)
{
cout<<"\n"<<p[i].name;
}
for(int i=0;i<n;i++)
{
if(i==0)
{p[i].wait=0;p[i].turn=p[i].wait+p[i].duration;avgt=avgt+p[i].turn;
}
else
{
	p[i].wait=p[i-1].turn-p[i].arrival;avgw=avgw+p[i].wait;p[i].turn=p[i].wait+p[i].duration;avgt=avgt+p[i].turn;}
}

for(int i=0;i<n;i++)
{
cout<<"\n\nName \t\tDuration\t\t  Priority\t\t  Arrival time\t\t   Wait Time\t\t  TurnAround Time\n";
cout<<"\n"<<p[i].name<<"\t\t\t"<<p[i].duration<<"\t\t\t"<<p[i].priority<<"\t\t\t"<<p[i].arrival<<"\t\t\t"<<p[i].wait<<"\t\t\t"<<p[i].turn;
}
cout<<"\n\nAverage Waiting time: "<<avgw/n<<"\n\nAverage Turn Around time:"<<avgt/n<<"\n\n";
}
int main()
{
int ch;
while(ch!=5)
{
cout<<"Enter the Scheduling algorithm: \n1. FCFS\n2. Shortest Job First\n3. Priority\n4. Exit\n\nEnter your Choice :  ";
cin>>ch;
switch(ch)
{
case 1: fcfs();
break ;
case 2: sjf();
break ;
case 3: priority();
break;
case 4: break;
default: cout<<"\n\nWrong Choice";
}
}
return(0);
}
