#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
int main()
{
int child,shmid,i;
char *shmptr;
child=fork();
if(!child)
{
shmid=shmget(2041,32,0666|IPC_CREAT);
shmptr=shmat(shmid,0,0);
printf("\n PARENT PROCESS WRITING \n");
for(i=0;i<10;i++)
{
shmptr[i]='a'+i;
putchar(shmptr[i]);
}
printf("\n\n %s",shmptr);
wait(NULL);
}
else
{
shmid=shmget(2041,32,0666);
shmptr=shmat(shmid,0,0);
printf("\n CHILD PROCESS READING\n");
for(i=0;i<10;i++)
putchar(shmptr[i]);
shmdt(NULL);
shmctl(shmid,IPC_RMID,NULL);
}
return 0;
}

