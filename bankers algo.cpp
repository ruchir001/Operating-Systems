#include<iostream>
using namespace std;
int main() {
int i, j, exec, r, p;
int count = 0;
bool safe = false;
cout<<("\nEnter the number of resources: ");
cin>>r;
cout<<("\nEnter the number of processes: ");
cin>>p;
int C[p][r];
int B[p][r], E[p][r];
int D[r];
int alloc[r],sseq[p],k=0;
int A[r];
for(i=0;i<r;i++)
{D[i]=0;alloc[i]=0;}
int running[p];
for (i = 0; i < p; i++) {
running[i] = 1;
count++;
}
cout<<("\nEnter Total resources Matrix A:\n ");
for (i = 0; i < r; i++)
cin>>A[i];
cout<<("\nEnter Maximum Claim table B: \n");
for (i = 0; i < p; i++) {
for (j = 0; j < r; j++)
cin>>B[i][j];
}
cout<<("\nEnter Allocated Resource Table C: \n");
for (i = 0; i < p; i++) {
for (j = 0; j < r; j++)
cin>>C[i][j];
}

cout<<("\nThe E matrix E is :\n");
for (i = 0; i < p; i++) {
for (j = 0; j < r; j++)
{
E[i][j]=B[i][j]-C[i][j];
cout<<"\t"<<E[i][j];
}
cout<<"\n";
}

for (i = 0; i < p; i++)
for (j = 0; j < r; j++)
alloc[j] += C[i][j];
cout<<("\n\nAllocated resources are : ");
for (i = 0; i < r; i++)
cout<<alloc[i]<<"\t";
for (i = 0; i < r; i++)
D[i] = A[i] - alloc[i];
cout<<"\n\nAvailable resources D : ";
for (i = 0; i < r; i++)
cout<<D[i]<<"\t";
cout<<"\n\t\n THE NAME OF PROCESSER SARTS FROM 1 P1,P2,P3,P4.....\n";
while (count != 0) {
safe = false;
for (i = 0; i < p; i++) {
if (running[i]) {
exec = 1;
for (j = 0; j < r; j++) {
if (B[i][j] - C[i][j] > D[j]) {
exec = 0;
break;
}
}
if (exec) {
cout<<"\n\nProcess P"<<(i+1)<<" is executing.\n";
running[i] = 0;
count--;
sseq[k]=(i+1);
k=k+1;
safe = true;
for (j = 0; j < r; j++)
{
D[j] += C[i][j];
}
break;
}
}
}
if (!safe) {
cout<<"\nThe processes are in unsafe state.";
break;
}
if (safe)
cout<<"The process is in safe state.";
cout<<"\nAvailable resources D : \n";
for (i = 0; i < r; i++)
cout<<D[i]<<"\t";
cout<<"\n\n";
}
cout<<"\n\nTHE SAFE SEQUENCE IS : \n";
for (i = 0; i<k;i++)
cout<<"P"<<sseq[i]<<"\t";

return 0;
}
