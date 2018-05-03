#include<stdio.h>
#define MAX 25
int n=0,np=17;
int crc[MAX],temp[MAX],input[MAX];
int poly[17]={1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1};
void genCRC(void);
void convert2bin(int);
void makeerror(int);
int main()
{
int i, j, num, pos, ch, f=0;
clrscr();
printf("\n\nEnter the dataword(number)\
scanf("%d",&num);
convert2bin(num);
printf("The binary equivalent of %d is\n",num);
for(i=1;i<n;i++)
printf(" %d",input[i]);
for(i=n;i<n+np-1;i++)
input[i]=0;
genCRC();
printf("\nGenerated CRC is:\n");
for(i=n,j=0;i<n+np-1;i++)
{
input[i]=temp[j++];
printf(" %d",input[i]);
}
printf("\nTransmitted code word is:\n");
for(i=1;i<n+np-1;i++)
printf(" %d ",input[i]);
printf("\n\nDo you want to make an error(1/0): ");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("Enter the position\n");
scanf("%d",&pos);
if(pos>0 && pos<n+np-1)
f=1;
else
printf("Invalid position\n\n");
if(f)
{
makeerror(pos);
printf("\nReceived code word is:\n");
for(i=1;i<n+np-1;i++)
printf(" %d",input[i]);
genCRC();
for(i=0;i<np;i++)
if(temp[i]!=0)
break;
printf("\nMessage received has error\n\n");
}
break;
case 0: printf("\nNO change in code word\n\n");
}
23
getch();
return(0);
}
void genCRC()
{
int i,j,k,s;
for(i=0;i<np;i++)
temp[i]=input[i];
while(i<n+np)
{
k=0;j=0;
if(temp[k]==poly[j])
while(k<np)
crc[k]=temp[k++]^poly[j++];
else
while(k<np)
crc[k]=temp[k++]^0;
for(s=1,j=0;s<np;s++)
temp[j++]=crc[s];
temp[j]=input[i++];
}
}
void convert2bin(int num)
{
int i=0;
while(num!=0)
{
temp[i++]=num%2;
num=num/2;
}
while(i>=0)
input[n++]=temp[i--];
}
void makeerror(int pos)
{
if(input[pos]==1)
input[pos]=0;
else
input[pos]=1;
}
