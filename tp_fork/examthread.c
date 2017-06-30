#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t th1,th2,th3,th4;
void *r;

void *afficherth1(void *v){
printf("<<th1>>");
return v;
}

void *afficherth2(void *v){

printf("<<th2>>");
pthread_join(th1,&r);
return v;
}

void *afficherth3(void *v){
printf("<<th3>>");
return v;
}

void *afficherth4(void *v){
printf("<<th4>>");
pthread_join(th3,&r);
return v;
}

main(){
	int a,b;
	a=fork();
	if(a!=0)
	{
		b=fork();
		if(b!=0){
		
			pthread_create(&th1,NULL,afficherth1(NULL),NULL);
			
			pthread_create(&th2,NULL,afficherth2(NULL),NULL);
		
		}
		else
		{
		pthread_create(&th3,NULL,afficherth3(NULL),NULL);
		
		pthread_create(&th4,NULL,afficherth4(NULL),NULL);
		}
	}
	else
	{
	
	}
}

