#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *thread_1(void *arg)
{
	printf("nous sommes dans le thread \n");
	
	(void) arg;
	pthread_exit(NULL);

}
int main(void)
{
	pthread_t t1;
	printf("Avant la création du thread \n");
	if(pthread_create(&t1,NULL,thread_1,NULL)){
	perror("erreur de création du thread");
	return EXIT_FAILURE;

	}
	if(pthread_join(t1,NULL)){
	perror("pthread_ join");	
	}
	printf("Après la création du thread \n");
	return EXIT_SUCCESS;


}
