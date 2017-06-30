#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h> 
#include <sys/un.h>
#define TAILLEBUF 20

int main(int argc, char *argv[]) 
{
	static struct sockaddr_un addr_serveur; // identification socket d'écoute du serveur
	int s_id;  // socket locale coté client
	char *message = "Bonjour maudit socket"; // message � envoyer au serveur
	char reponse[TAILLEBUF];  // chaïne où sera écrite le message reçu
	int nb_octets; // nombre d'octets envoyés/reçus
	s_id = socket(AF_UNIX, SOCK_STREAM, 0);
	if (s_id == -1) {
	      perror("Problème de creation du socket");
	      exit(1); 
	 }
	addr_serveur.sun_family = AF_UNIX;
	memcpy(addr_serveur.sun_path,"sock",strlen("sock"));
	// connexion de la socket client locale à la socket coté serveur
	int resConnect=connect(s_id,(struct sockaddr *)&addr_serveur,sizeof(struct sockaddr_un));
	if (resConnect == -1) 
	{
		perror("Erreur connexion serveur");
		exit(1);
	}	
	nb_octets = write(s_id, message, strlen(message)+1); 
	// connexion etablie, on envoie le message
	nb_octets = read(s_id, reponse, TAILLEBUF); 
	// on attend la réponse du serveur
	printf("Réponse reçue : %s\n", reponse);// on ferme la socket
	close(s_id);
}
