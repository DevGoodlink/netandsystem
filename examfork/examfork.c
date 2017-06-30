#include <stdio.h>
#include <stdlib.h>

int main(){

if(fork()){

	printf("1\n");
	if(!fork()){
		printf("2\n");
	
	}

}
fork();
printf("3");
while(!wait());
return 0;

}
