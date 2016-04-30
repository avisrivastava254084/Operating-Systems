#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<wait.h>
int main (void) {
    pid_t pid, pid2;
    int status;
int avi;
    pid = fork();
int a=0; int b=1; int i=0; int sum;

    if (pid == 0) { //child process
        pid2 = fork();
        int status2;

        if (pid2 == 0) { //child of child process
         wait(&status);   printf("thnx \n");
         
        }
        else {
            //printf("thnx \n ");
//wait(&status2);          
scanf("%d",&avi);

 while(i<avi)
            {
              sum=a+b;
              printf("%d",sum); printf(" ");
              a=b; b=sum; i++;
            }   
            fflush(stdout);
            
        }
    }
    else { //parent process
        printf("Welcome ");
        fflush(stdout);
        wait(&status);
        printf("Bye ");

    }

    return 0;
}
