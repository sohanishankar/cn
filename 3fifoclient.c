#include<stdio.h>
#include<fcntl.h>
#include<string.h>
main()
{
char buf[1000];
int fd1,fd2,n;
fd1=open("LIFE",O_WRONLY);
printf("\n enter the filename: ");
scanf("%s",buf);
write(fd1,buf,strlen(buf));
close(fd1);
fd2=open("LIFE",O_RDONLY);
while((n=read(fd2,buf,128))>0)
write(1,buf,n);
close(fd2);
}