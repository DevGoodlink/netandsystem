#include<stdio.h>
#include<sys/fcntl.h>
main()
{
int fd;
fd=open("toto",O_WRONLY);
write(fd,"bonjour",7);
printf("%d]>fin écriture",getpid());

}
