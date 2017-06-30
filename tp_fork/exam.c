#include <stdio.h>
#include <stdlib.h>


main(){
//printf("le père %d",getpid());
if(fork()){
	
	printf("1\n");// pid = %d mon père = %d \n",getpid(),getppid());
	if(!fork()){
		printf("2\n");// mon pid= %d mon père = %d\n",getpid(),getppid());

	}
}
fork();
printf("3");// mon pid = %d \n",getpid());
while(!wait());

}
