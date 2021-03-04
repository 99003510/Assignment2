
#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
  

void sighup(); 
void sigint(); 
void sigquit(); 
  

void main() 
{ 
    int pid; 
  
    /*  the Child process */
    if ((pid = fork()) < 0) { 
        perror("fork"); 
        exit(1); 
    } 
  
    if (pid == 0) { /* child */
        signal(SIGHUP, sighup); 
        signal(SIGINT, sigint); 
        signal(SIGQUIT, sigquit); 
        for (;;) 
            ; /* loop runs forever */
    } 
  
    else /* parent */
    { /* pid hold id of child */
        printf("\nPARENT: sending SIGHUP\n\n"); 
        kill(pid, SIGHUP); 
  
        sleep(3); /* sleep for 3 secs */
        printf("\nPARENT: sending SIGINT\n\n"); 
        kill(pid, SIGINT); 
  
        sleep(3); /* sleep for 3 sec */
        printf("\nPARENT: sending SIGQUIT\n\n"); 
        kill(pid, SIGQUIT); 
        sleep(3); 
    } 
} 
  
// sighup() function definition 
void sighup() 
  
{ 
    signal(SIGHUP, sighup); /* reset signal */
    printf("CHILD has received a SIGHUP\n"); 
} 
  
// sigint() function definition 
void sigint() 
  
{ 
    signal(SIGINT, sigint); /* reset signal */
    printf("CHILD has received a SIGINT\n"); 
} 
  
// sigquit() function definition 
void sigquit() 
{ 
    printf("Mommy and Daddy Killed me:(\n"); 
    exit(0); 
}