/*FIFO-Server*/
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
main()
{
char buf[1000];
int fd1,fd2,n,fd;
mkfifo("LIFE",S_IFIFO|0777);
printf("\n server started\n server is waiting");
fd1=open("LIFE",O_RDONLY);
n=read(fd1,buf,128);
buf[n]='\0';
close(fd1);
fd2=open("LIFE",O_WRONLY);
if((fd=open(buf,O_RDONLY))<0)
{
write(fd2,"file not found\n",16);
printf("server termintated");
}
23
while((n=read(fd,buf,128))>0)
write(fd2,buf,n);
close(fd);
close(fd2);
printf("\n server terminates\n");
}