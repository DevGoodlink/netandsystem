#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define NB_THREADS 4

void * traitThread1(void *);
void * traitThread2(void *);
void * traitThread3(void *);
void * traitThread4(void *);
pthread_t idThread[NB_THREADS];
int main(void){
//wait();
//wait();
int err;
char chaine1[]={"numero1"};
char chaine2[]={"numero2"};
char chaine3[]={"numero3"};
char chaine4[]={"numero4"};

//pthread_t idThread[NB_THREADS];
void * retval;
pid_t pid=fork();
if(pid!=0){
err=pthread_create(&idThread[0], NULL, traitThread1,(void *)chaine1);
if(err!=0){
perror("echec création du thread1");
exit(1);
}
err=pthread_create(&idThread[1], NULL, traitThread2,(void *)chaine2);
if(err!=0){
perror("echec création du thread2");
exit(1);
}
//err=pthread_join(idThread[0], &retval);
//if(err!=0){
//perror("echec du join");
//}else{
//printf("Terminaison du thread numero =%d \n",idThread[0]);
//printf("chaine retourne = %d \n",(char * ) retval);
//}
}
else{
wait();
err=pthread_create(&idThread[2], NULL, traitThread3,(void *)chaine3);
if(err!=0){
perror("echec création du thread3");
exit(1);
}
err=pthread_create(&idThread[3], NULL, traitThread4,(void *)chaine4);
if(err!=0){
perror("echec création du thread4");
exit(1);
}
//err=pthread_join(idThread[2], &retval);
//if(err!=0){
//perror("echec du join");
//}else{
//printf("Terminaison du thread numero =%d \n",idThread[2]);
//printf("chaine retourne = %d \n",(char * ) retval);
//}
}

pthread_exit(NULL);
}


void * traitThread1(void * chaine){
static char mess[128]={"message du thread1: "};

printf("thread1 --> num = %d \n", pthread_self());
printf("thread1 -->chaine recue = %s \n", (char*)chaine);
strcat(mess,chaine);
return ((void*)mess);
}
void * traitThread2(void * chaine){
pthread_join(idThread[0],NULL);
static char mess[128]={"message du thread2: "};
printf("thread2 --> num = %d \n", pthread_self());
printf("thread2 -->chaine recue = %s \n", (char*)chaine);
strcat(mess,chaine);
return ((void*)mess);
}

void * traitThread3(void * chaine){
static char mess[128]={"message du thread3: "};
printf("thread3 --> num = %d \n", pthread_self());
printf("thread3 -->chaine recue = %s \n", (char*)chaine);
strcat(mess,chaine);
return ((void*)mess);
}
void * traitThread4(void * chaine){
pthread_join(idThread[2],NULL);
static char mess[128]={"message du thread4: "};
printf("thread4 --> num = %d \n", pthread_self());
printf("thread4 -->chaine recue = %s \n", (char*)chaine);
strcat(mess,chaine);
return ((void*)mess);
}














