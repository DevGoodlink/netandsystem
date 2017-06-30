#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

typedef struct data {
	int var;
	pthread_mutex_t mutex;
} data;
main(){
	data new_data;
	new_data.var=1;
	new_data.mutex =(pthread_mutex_t) PTHREAD_MUTEX_INITIALIZER;
	
	printf("mutex = %d",new_data.mutex);
	printf("ok %d \n",new_data.var);
	//return EXIT_SUCCESS;
}
