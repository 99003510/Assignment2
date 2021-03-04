#include<unistd.h>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/wait.h>
#include <string.h>



int main()
{
	int ret,return_value;
	int c1=fork();
	int c2;
	int c3;
	int c4;
	int c5;
	char *s;
	char *ss;
	ss="./s.out";
	s="s.out"; 
	if(c1<0||c2<0||c3<0)
	{
	perror("fork");
	exit(1);
	}
	if(c1==0)
	{ 
	execl("/bin/gcc","gcc","-c","test.c",NULL);
    	}
    	else
    	{
    	waitpid(c1, &return_value, 0);
    	c2=fork();
    	}
	if(c2==0)
    	execl("/bin/gcc","gcc","-c","multiply.c",NULL);
    	else
    	{waitpid(c2, &return_value, 0);
    	c3=fork();}
	if(c3==0)
  	execl("/bin/gcc","gcc","test.o","-o",s,NULL);
    	else
    	{
    	waitpid(c3, &return_value, 0);
    	c4=fork();
	} 
	if(c4==0)
	execl("./s.out", "./s.out", NULL); 
	else
	{
	  
	} 	 
	exit(0);
}
