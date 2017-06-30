#include <stdio.h>
#include <sys/fcntl.h>
main()
{
int fd;
fd=open("tube1.fifo",O_WRONLY);
write(fd,"Bonjour",7);
printf("%d > fin écriture",getpid());
}
