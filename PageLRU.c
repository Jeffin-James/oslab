#include<stdio.h>
int f[30],fs;
int cnt[30];
int flag,ps[30];
main()
{
int p,i,pos=0,j,k,max,s,pf=0;
float pfr;
void increment();
int check();
printf("enter no of pages:");
scanf("%d",&p);
printf("enter the pages:");
for(i=0;i<p;i++)
scanf("%d",&ps[i]);
printf("enter the frame size:");
scanf("%d",&fs);
for(k=0;k<fs;k++)
 f[k]=-999;
 for(i=0,j=0;i<p;i++)
 {
 flag=0;
 if(f[i]==-999)
 {
 check(j,ps[j]);
 if(flag==0)
 {
 f[j]=ps[i];
 pf++;
 for(k=0;k<=j;k++)
 cnt[k]+=1;
 j++;
 }
 }
 else
 {
 check(fs,ps[i]);
 if(flag==0)
 {
 max=cnt[0],pos=0;
 for(k=1;k<fs;k++)
 if(max<cnt[k])
 max=cnt[k],pos=k;
 f[pos]=ps[i],pf++;
 increment(ps[i]);
 }
 }
 for(k=0;k<fs;k++)
 printf("%4d",f[k]);
 printf("\n");
 }
 pfr=(float)pf/p;
 printf("total no of page faults:%d\n",pf);
 printf("page fault rare:%f",pfr);
 getch();
 }
 void increment(int ele)
 {
 int k;
 for(k=0;k<fs;k++)
 {
 if(f[k]==ele)
 cnt[k]=1;
 else
 cnt[k]+=1;
 }
 }
 check(int pos,int ele)
 {
 int k,s;
 for(k=0;k<fs;k++)
 if(f[k]==ele)
 {
 cnt[k]=1;
 for(s=0;s<pos;s++)
 if(s!=k)
 cnt[s]+=1;
 flag=1;
 }
 }

