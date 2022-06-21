#include<stdio.h>
void main(int argc,char *argv[])
{
int i,j=0,n,burst[10],wait[10],turn[10];
float w=0,t=0;
printf("Enter the no. of processes");
scanf("%d",&n);
burst[0]=0;
printf("Enter the burst time");
for(i=1;i<=n;i++)
{
scanf("%d",&burst[i]);
}
printf("\n\nGantt chart\n");
printf("\n________________________________________________________\n");
for(i=1;i<=n;i++)
printf("\tP%d\t|",i);
printf("\n________________________________________________________\n");
for(i=0;i<=n;i++)
{
j=j+burst[i];
wait[i+1]=j;
turn[i]=j;
printf("%d\t\t",j);
}
for(i=1;i<=n;i++)
w=w+wait[i];
for(i=0;i<=n;i++)
t=t+turn[i];
w=w/n;
t=t/n;
printf("\nAverage waiting time %0.2f",w);
printf("\nAverage turnaroundtime %0.2f",t);
}

