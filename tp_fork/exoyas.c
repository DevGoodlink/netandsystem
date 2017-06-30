#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
char first='1';char second='2';char third='3';char fourth='4';
int i=0;
pthread_t idThread[4];
void *traitement1(void *arg){
	printf("<<1>>");
	(void)arg;
	pthread_exit(NULL);
}
void *traitement2(void *arg){
	printf("<<2>>");
	(void)arg;
	pthread_join(idThread[1],NULL);
	pthread_exit(NULL);

}
void *traitement3(void *arg){
	printf("<<3>>");
	(void)arg;
	pthread_join(idThread[2],NULL);
	pthread_exit(NULL);
}
void *traitement4(void *arg){
	printf("<<4>>");
	(void)arg;
	pthread_exit(NULL);
}

int main(void){

pid_t a,b;

a = fork();
if(a!=0)
{
	if(pthread_create(&idThread[0],NULL,traitement1,NULL)==-1){
		perror("prob");
		return EXIT_FAILURE;
	}
//	pthread_join(idThread[0],NULL);
	pthread_create(&idThread[1],NULL,traitement2,NULL);
	b=fork();
	if(b!=0)
	{
		pthread_create(&idThread[2],NULL,traitement3,NULL);
//		pthread_join(idThread[2],NULL);
		pthread_create(&idThread[3],NULL,traitement4,NULL);

	}
}
return 0;
}

