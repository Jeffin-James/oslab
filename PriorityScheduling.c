#include<stdio.h>
struct prcs
{
int pid;
int bt;
int pr;
int tt;
int wt;
};
int main()
{
 int no;
 int k=0,b=0,g=0;
 int i;
 int w=0;
 float n,m;
 struct prcs p[10];
 printf("enter the number of process");
 scanf("%d",&no);
 for(i=1;i<=no;i++)
  {
   printf("enter the process id");
   scanf("%d",&p[i].pid);
   printf(" enter the burst time");
   scanf("%d",&p[i].bt);
   printf("enter the priority");
   scanf("%d",&p[i].pr);
   p[i].wt=0;
   p[i].tt=0;
  }
 for(i=1;i<=no;i++)
  {
   int f=1,j;
   for(j=1;j<=no-i;j++)
    {
     int h=0,l=0,m=0;
     if(p[j].pr>p[j+1].pr && i<no)
      {
       f=0;
       l=p[j].pr;
       p[j].pr=p[j+1].pr;
       p[j+1].pr=l;
       h=p[j].pid;
       p[j].pid=p[j+1].pid;
       p[j+1].pid=h;
       g=p[j].bt;
       p[j].bt=p[j+1].bt;
       p[j+1].bt=g;
       if(f)
        break;
      }
    }
   }
 p[1].wt=0;
 p[1].tt=p[1].bt;
 for(i=2;i<=no;i++)
  {
   p[i].tt=p[i-1].tt+p[i].bt;
   p[i].wt=p[i-1].tt;
   b=p[i].wt+b;
   k=p[i].tt+k;
  }
 k=k+p[1].tt;
 m=(float)b/(float)no;
 n=(float)k/(float)no;
 for (i=1;i<=no;i++)
  {
   printf("the waiting time for p[%d]==%d\n",p[i].pid,p[i].wt);
   printf("the turnarround time for p[%d]==%d\n",p[i].pid,p[i].tt);
  }
 printf("the average waiting time==%f\n",m);
 printf("the average turnarround time==%f\n",n);
 printf("___________________________________\n");
 for (i=1;i<=no;i++)
  {
   printf("Process%d",p[i].pid);
  }
 printf("\n");
 printf("___________________________________\n");
 for(i=1;i<=no;i++)
  {
   printf("%d\t",p[i].wt);
  }
 printf("%d\n",p[no].tt); return(0);
}

