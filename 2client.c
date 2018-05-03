/*Socket-Client*/
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#define P_ID 50
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
int fd1,n;
struct sockaddr_in s,s1;
23
printf("Enter file request to server:");
scanf("%s",buf);
s.sin_family=AF_INET;
s.sin_port=htons(P_ID);
s.s_addr=inet_addr("127.0.0.1");
bzero(&(s.sin_zero),8);
fd1=socket(AF_INET,SOCK_STREAM,0);
if((connect(fd1,(struct sockaddr*)&s,sizeof(struct
sockaddr)))==-1)
printf("Error.\n");
send(fd1,buf,strlen(buf),0);
printf("\ncontents of file are\n\n");
while((n=recv(fd1,buf,sizeof(buf),0))>0)
{
buf[n]='\0';
printf("%s",buf);
}
printf("\n");
close(fd1);
return 0;
}