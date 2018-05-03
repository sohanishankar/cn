/*SOCKET-SERVER*/

#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/socket.h>
#define PORT_ID 50
struct sockaddr_in
{
short int sin_family;
unsigned short int sin_port;
unsigned long s_addr;
unsigned char sin_zero[8];
};
int main()
{
char buf[2000];
int fd1,n,fd2,size;
23
struct sockaddr_in s,s1;
printf("server is ready\n");
s.sin_family=AF_INET;
s.sin_port=htons(PORT_ID);
s.s_addr=inet_addr("127.0.0.1");
bzero(&(s.sin_zero),8);
fd1=socket(AF_INET,SOCK_STREAM,0);
if((bind(fd1,(struct sockaddr*)&s,sizeof(struct sockaddr)))==-1)
printf("Error.\n");
if((listen(fd1,5))==-1)
printf("Error\n");
size=sizeof(struct sockaddr);
printf("Waiting for client request\n");
fd2=accept(fd1,(struct sockaddr*)&s1,&size);
close(fd1);
size=recv(fd2,buf,sizeof(buf),0);
buf[size]='\0';
printf("File:%s\n",buf);
if((fd1=open(buf,O_RDONLY))!=-1)
while((n=read(fd1,buf,sizeof(buf)))>0)
send(fd2,buf,n,0);
else
send(fd2,"File not found",15,0);
close(fd1);
close(fd2);
printf("server terminated\n");
return 0;
}



