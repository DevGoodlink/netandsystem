#include <stdio.h>
#include <signal.h>
void hand(int signum){
	printf("Numéro du signal est %d \n",signum);
	printf("il faut appuyer ctrl+c une 2ème fois pour terminer\n");
	/*rétablir le handler par défaut du signal sigint en utilisant la macro "SIG_DFL" */
	signal(SIGINT,SIG_DFL);

}
int main(void){
	signal(SIGINT,hand);
	for(;;){}
	return 0;

}

