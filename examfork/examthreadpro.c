#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
pthread_t th[4];
pid_t p[2];
void *th1(void *arg){
printf("<th1>");

pthread_exit(NULL);
}
void *th2(void *arg){
printf("<th2>");
pthread_join(th[0],NULL);
pthread_exit(NULL);
}
void *th3(void *arg){
printf("<th3>");
pthread_exit(NULL);
}
void *th4(void *arg){
printf("<th4>");
pthread_join(th[2],NULL);
pthread_exit(NULL);
}
int main(void){

p[0]=fork();
if(p[0]==0){

	pthread_create(&th[0],NULL,th1,NULL);
	pthread_join(th[0],NULL);
	pthread_create(&th[1],NULL,th2,NULL);
}else{
	p[1]=fork();
	if(p[1]==0){
		pthread_create(&th[2],NULL,th3,NULL);
		pthread_join(th[2],NULL);
		pthread_create(&th[3],NULL,th4,NULL);
	}
}
//while(!wait());
return EXIT_SUCCESS;
}
