#include <stdio.h>
#include <unistd.h>

main(){

int pip[2],status;
pid_t retour;
char chaine[7];
pipe(pip);
retour = fork();
if(retour == 0)
{
	close(pip[0]); /*pas de lecture sur le tube */
	write(pip[1],"Bonjour",7);
	close(pip[1]);
	exit(0);
}
else
{
	close(pip[1]);
	read(pip[0],chaine,7);
	close(pip[0]);
	printf("Chaine reçue = %s ",chaine);
	wait(&status);

}



}
