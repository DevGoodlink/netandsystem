#include <stdio.h>
#include<unistd.h>
void main()
{
	/*printf("Exemple de la fonction fork \n");
	int id=fork();
	if(id==0)
	{
		printf("je suis le père \n");
	}
	else
	{
		printf("je suis le fils \n");
	}
	int i=8;
	printf("i=%d \n",i);
	int pid=fork();
	printf("Au revoir %d %d \n",i,pid);*/
	/*int idF = fork();
	if(idF!=0){
		sleep(3);
		printf("le père en exécution %d, idF= %d \n" ,getpid(),idF);

		//wait();
	}else{
		printf("Le fils en exécution %d, idF=%d \n",getpid(),idF);
		execl("/bin/ls","ls","-l",NULL);
		perror("echec de execl \n");	
	}*/
	/*int t=1;
	int t1=2;
	printf("main pid = %d \n",getpid());
	if(!fork()){
		if(!fork())
		{
			t++;
			printf("ok %d t=%d \n",getpid(),t);
			
		}else{

		t1++;
		printf("ok %d t1=%d \n",getpid(),t1);}
		
	}else{
	wait();
	printf("t+t1 = %d \n",t+t1);}*/
	if(fork() && fork() * fork()){ printf("ok \n");	}
	else{printf("ok \n");};

	//printf("ok %d \n",getpid());
	/*
	fork();
	printf("Je suis le troisième fils %d \n",getpid());
	printf("ok %d \n",getpid());*/

}

