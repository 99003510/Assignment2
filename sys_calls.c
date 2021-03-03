#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int maxlen=128;
    int fd,fd1;
	char buf[maxlen];
    ssize_t ret1, ret2;
	//nbytes=read(0,buf,maxlen);
    fd=open("my_first_file.txt",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
    fd1=open("my_second_file.text",O_WRONLY|O_CREAT, 0666);
     if(fd1<0)
	{
		perror("open");
		exit(1);
	}
    while((ret1 = read(fd, &buf, maxlen))>0)
    {
        ret2 = write (fd1, &buf, ret1);
        if (ret2 != ret1)
        {
            perror("write");
            exit(1);
        }
    }
    close(fd);
  close(fd1);
  return 0;  


}