#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *th1(void *arg)
{
	printf("Dans le thread\n");
	(void) arg;
	pthread_exit(NULL);
}
int main(void)
{
	pthread_t thr1;
	printf("Avant la création \n");
	printf("adresse memoire de thr1 = %d \n",&thr1);
	int a=pthread_create(&thr1,NULL,th1,NULL);
	if(a==-1)
	{ perror("erreur de création\n");
	  return EXIT_FAILURE;}
	printf("après exécution du thread \n");
	return EXIT_SUCCESS;

}
