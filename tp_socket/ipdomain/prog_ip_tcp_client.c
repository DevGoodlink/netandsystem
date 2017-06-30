#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h> 
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#define TAILLEBUF 20

int main(int argc, char *argv[]) 
{
	static struct sockaddr_in addr_serveur; // identification socket d'écoute du serveur
	int s_id;
	//char *message = "Bonjour maudit socket"; // message à envoyer au serveur
	char *message="bonjour";  
	char *chaine_recue;// chaïne où sera écrite le message reçu
	char reponse[TAILLEBUF];
	int nb_octets; // nombre d'octets envoyés/reçus

	s_id = socket(AF_INET, SOCK_STREAM, 0);
	if (s_id == -1) {
	      perror("Problème de création du socket");
	      exit(1); 
	 }
	host_serveur=gethostbyname("localhost");
	addr_serveur.sin_family = AF_INET;
	addr_serveur.sin_port=htons(4000);
	
	memcpy(&addr_serveur.sin_addr.s_addr,host_serveur->h_addr,host_serveur->h_length);
	// connexion de la socket client locale à la socket coté serveur
	
	int resConnect=connect(s_id,(struct sockaddr *)&addr_serveur,sizeof(struct sockaddr_in));
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
