#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

main(){
if(fork()==0){
printf("je suis le fils, mon PID est %d \n",getpid());
sleep(1);
}else{
printf("je suis le père mon PID est %d \n",getpid());
sleep(30);
}


}
