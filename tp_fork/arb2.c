#include<stdio.h>
#include<unistd.h>
void main(){
	printf("processus pere %d \n",getpid());
	if(fork()){
		printf(" 1- %d \n",getpid());
	}
	if(!fork()){

		printf("2- %d \n",getpid);
	}


}
