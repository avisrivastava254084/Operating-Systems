#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t readAccess;
sem_t dbAccess;
int readCount=0;

void *Reader(void *arg);
void *Writer(void *arg);

int main()
{
int i=0,noofRT=0,noofWT;
sem_init(&readAccess,0,1);
sem_init(&dbAccess,0,1);

pthread_t Readers_thr[100],Writer_thr[100];
printf(“\nEnter number of Readers thread(MAX 10)”);
scanf(“%d”,&noofRT);
printf(“\nEnter number of Writers thread(MAX 10)”);
scanf(“%d”,&noofWT);

for(i=0;i<numberofreaderthread;i++)
{
pthread_create(&Readers_thr[i],NULL,Reader,(void *)i);
}
for(i=0;i<numberofwriterthread;i++)
{
pthread_create(&Writer_thr[i],NULL,Writer,(void *)i);
}
for(i=0;i<noofWT;i++)
{
pthread_join(Writer_thr[i],NULL);
}

for(i=0;i<noofRT;i++)
{
pthread_join(Readers_thr[i],NULL);
}
sem_destroy(&dbAccess);
sem_destroy(&readAccess);
return 0;
}

void * Writer(void *arg)
{

sleep(1);
int temp=(int)arg;
printf(“\nWriter %d is trying to enter into database for modifying the data”,temp);
sem_wait(&dbAccess);
printf(“\nWriter %d is writting into the database”,temp);
printf(“\nWriter %d is leaving the database”);
sem_post(&dbAccess);
}

void *Reader(void *arg)
{
sleep(1);
int temp=(int)arg;
printf(“\nReader %d is trying to enter into the Database for reading the data”,temp);
sem_wait(&readAccess);
readCount++;
if(readCount==1)
{
sem_wait(&dbAccess);
printf(“\nReader %d is reading the database”,temp);
}
sem_post(&readAccess);
sem_wait(&readAccess);
readCount–;
if(readCount==0)
{
printf(“\nReader %d is leaving the database”,temp);
sem_post(&dbAccess);
}
sem_post(&readAccess);
}
