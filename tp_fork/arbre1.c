#include<stdio.h>
#include<unistd.h>
void main(){
	int i;
	for(i=0;i<3;i++){
		fork();
		printf("nouveau processus \n");
	}


}
