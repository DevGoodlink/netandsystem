#include <stdio.h>
#include <stdlib.h>

void main(){

for(int i=1;i<=2;i++){
	pid_t ret = fork();
	if(ret == 0) printf("fils de %d %d %d pid = %d \n",getppid(),i,ret,getpid());
	else{
		 printf("père %d %d pid= %d  \n",i,ret,getpid());
		wait(0);
	}
	
}


}
