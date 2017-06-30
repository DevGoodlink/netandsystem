#include<stdio.h>
#include<sys/stat.h>
main(){

int masque = umask(0); //modifier le masque par défaut
mkfifo("tube1.fifo",0664);
//S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH


}
