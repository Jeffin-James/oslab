#include<stdio.h>
void main(int argc,char *argv[])
{
int b[10],temp,i,j,n,wait[10],burst[10],turn[10];
float w=0,t=0;
printf("Enter the no. of processes");
scanf("%d",&n);
burst[0]=0;
b[0]=0;
printf("Enter the burst time");
for(i=1;i<=n;i++)
{
scanf("%d",&burst[i]);
}
for(i=1;i<=n;i++)
b[i]=burst[i];
for(i=1;i<n;i++)
for(j=i+1;j<=n;j++)
if(b[i]>b[j])
{
temp=b[i];
b[i]=b[j];
b[j]=temp;
}
printf("\nGantt chart");
printf("\n________________________________________________________\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
if(b[i]==b[j])
printf("P%d|\t",j);
printf("\n_________________________________________________________\n");
j=0;
for(i=0;i<=n;i++)
{
j=j+b[i];
wait[i+1]=j;
turn[i]=j;
printf("%d\t",j);
}
for(i=1;i<=n;i++)
w=w+wait[i];
for(i=0;i<=n;i++)
t=t+turn[i];
w=w/n;
t=t/n;
printf("\nAverage waiting time is %0.2f",w);
printf("\nAverage turnaroundtime is %0.2f",t);
}

