#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

pthread_t t1,t2,t3,t4;

pid_t p1,p2,p3,p4;

int A[2][2],B[2][2];
const int MAX = 100,MIN =1;
int somme[2][2],multi[2][2];
void *initialiser();
void *affichermatrice();
void *sommemultiplication();
void *affichernewmatrice();

int main(){

srand(time(NULL));

printf("avant le thread\n");
if(pthread_create(&t1,NULL,initialiser,NULL)){
perror("Echec Premier thread");
return EXIT_FAILURE;
}
if(pthread_join(t1,NULL)){
perror("echec join premier thread\n");
return EXIT_FAILURE;
}
if(pthread_create(&t2,NULL,affichermatrice,NULL)){
perror("Echec deuxieme thread");
return EXIT_FAILURE;
}
if(pthread_join(t2,NULL)){
perror("Echec join deuxieme thread\n");
return EXIT_FAILURE;
}
if(pthread_create(&t3,NULL,sommemultiplication,NULL)){
perror("echec creation thread 3");
return EXIT_FAILURE;
}
if(pthread_join(t3,NULL)){
perror("echec join thread 3");
return EXIT_FAILURE;
}
if(pthread_create(&t4,NULL,affichernewmatrice,NULL)){
perror("Echec 4eme thread");
return EXIT_FAILURE;
}
if(pthread_join(t4,NULL)){
perror("Echec join thread 4");
return EXIT_FAILURE;
}

printf("ok!!!! fin d'exécution \n");
return 0;
}

void *initialiser(){
printf("initialisation. \n");
for(int i=0;i<2;i++){
	for(int j=0;j<2;j++){
		A[i][j]=(rand() % (MAX - MIN +1))+MIN;
		B[i][j]=(rand() % (MAX - MIN +1))+MIN;
	}
}
pthread_exit(NULL);
}

void *affichermatrice(){
printf("Affichage matrice\n");
printf("Matrice A : \n");
for(int i=0;i<2;i++){
	for(int j=0;j<2;j++){
		printf("%d \t",A[i][j]);
	}
	printf("\n");
}
printf("Matrice B : \n");
for(int i=0;i<2;i++){
	for(int j=0;j<2;j++){
		printf("%d \t",B[i][j]);
	}
	printf("\n");
}
pthread_exit(NULL);
}

void *sommemultiplication(){
//int somme[2][2],multi[2][2];
printf("Somme et multiplicatin :\n");
for(int i=0;i<2;i++)
{
	for(int j=0;j<2;j++)
	{
		somme[i][j]=A[i][j]+B[i][j];
		multi[i][j]=A[i][j]*B[j][i];	
	}
}
pthread_exit(NULL);
}

void *affichernewmatrice(){
printf("Affichage somme  matrices : \n");
for(int i=0;i<2;i++){
	for(int j=0;j<2;j++){
		printf("%d \t",somme[i][j]);			
	}
	printf("\n");
}
printf("Affichage multiplication matrices :\n");
for(int i=0;i<2;i++){
	for(int j=0;j<2;j++)
	{
		printf("%d \t",multi[i][j]);
	}
	printf("\n");
}
pthread_exit(NULL);
}


