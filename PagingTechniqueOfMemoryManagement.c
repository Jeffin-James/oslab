#include<stdio.h>
int i,j,k,ps,np1,op,np,np2,fn,f=0;
char p1[50][50],p2[50][50];
int pgtb(int r,int fn,int np)
{
for(i=0;i<np;i++)
printf("\n\t%d\t\t%d",i,r++);
if(i>np)
printf("\n\t%d\t\tPage Fault",i);
return(r);
}

void frame(int np1,int np2,int fn,int ps,char p1[50][50],char p2[50][50])
{
for(i=0;i<np1;i++)
{
if(i<fn)
{
printf("\n--------------------\n");
printf("\nFrame No:%d\n",i);
for(j=0;j<ps;j++)
printf("\t%c",p1[i][j]);
}}
k=np1;
for(i=0;i<np2;i++)
{
if(k<fn)
{
printf("\n--------------------\n");
printf("\nFrame No:%d\n",k);
k++;
for(j=0;j<ps;j++)
printf("\t%c",p2[i][j]);
}}}
int main()
{
printf("\nENTER THE PAGE SIZE:");
scanf("%d",&ps);
printf("\nENTER NO OF FRAMES:");
scanf("%d",&fn);
printf("\nENTER NO OF PAGES FOR PROCESS1:");
scanf("%d",&np1);
printf("\nENTER NO OF PAGES FOR PROCESS2:");
scanf("%d",&np2);
if(np1+np2>fn)
printf("\nPage Fault will occur\n");
printf("\nPROCESS1");
printf("\n--------------------\n");
p1[np1][ps];
p2[np2][ps];
for(i=0;i<np1;i++)
{
printf("Enter CHAR for PAGE%d:",i);
scanf("%s",&p1[i]);
}
printf("\nPROCESS2");
printf("\n--------------------\n");
for(i=0;i<np2;i++)
{
printf("Enter CHAR for PAGE%d:",i);
scanf("%s",&p2[i]);
}
while(1)
{
printf("\n1.Page Table for PROCESS1\n2.Page Table for PROCESS2\n3.Frame Allotment\n4.Free Frame List\n5.Exit\n");
printf("ENTER YOUR CHOICE:");
scanf("%d",&op);
switch(op)
{
case 1:
printf("Page Table for PROCESS1");
printf("\nPAGE INDEX\tFRAME INDEX\n");
f=pgtb(f,fn,np1);
break;
case 2:
printf("Page Table for PROCESS2");
printf("\nPAGE INDEX\tFRAME INDEX\n");
f=pgtb(f,fn,np2);
break;
case 3:
frame(np1,np2,fn,ps,p1,p2);
break;
case 4:
if(np1+np2>fn)
printf("Page Fault has occurred");
else if(np1+np2==fn)
printf("\nNo Free Frames");
else
{
printf("Free Frame List");
printf("\n----------------\n");
for(i=np1+np2;i<fn;i++)
printf("%dth frame",i);
}
break;
case 5:
return(0);
break;
}
}
}

