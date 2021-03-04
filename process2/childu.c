#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
    pid_t ret;
    int status_1;
    int executing_1;
    int n;

    ret=fork();
    if(ret < 0)
    {
        perror("fork");
        exit(1);
    }
    if(ret == 0)
    {
                                   
        executing_1 = execl("/usr/bin/gcc","gcc","-c","parent.c",NULL); 
	execl("/bin/gcc","gcc","parent.o","-o",n,NULL); 

                            
        if(executing_1<0)
        {
            perror("execv");
            exit(2);
        }
        exit(0);

    }
    else
    {
        waitpid(-1,&status_1,0); 
        printf("parents -> -> child exit status=%d\n",
			WEXITSTATUS(status_1));
		
    }
    return 0;

