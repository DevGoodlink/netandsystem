#include<stdio.h>
#include<sys/fcntl.h>
main(){
int fd;
char buf[50];
fd=open("toto",O_RDONLY);
read(fd,buf,sizeof(buf));
printf("%d ]>reçu , %s \n",getpid(),buf);


}
