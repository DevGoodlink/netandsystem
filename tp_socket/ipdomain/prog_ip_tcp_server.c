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
	static struct sockaddr_in addr_client;
	static struct hostent *host_serveur;
	int lg_addr;  // longueur d'adresses
	int s_ecoute,s_service;
	//char *message = "Bonjour maudit socket"; // message à envoyer au serveur
	char message[TAILLEBUF];  // chaïne où sera écrite le message reçu
	char *chaine_recue;
	char *reponse ="Bien reçu";
	int nb_octets; // nombre d'octets envoyés/reçus

	s_ecoute = socket(AF_INET, SOCK_STREAM, 0);
	if (s_ecoute == -1) {
	      perror("Problème de creation du socket");
	      exit(1); 
	 }
	host_serveur=gethostbyname("localhost");
	addr_serveur.sin_family = AF_INET;
	addr_serveur.sin_port=htons(4000);
	
	memcpy(&addr_serveur.sin_addr.s_addr,host_serveur->h_addr,host_serveur->h_length);
	// connexion de la socket client locale à la socket coté serveur
	
	int resBind=bind(s_ecoute,(struct sockaddr *)&addr_serveur,sizeof(struct sockaddr_in));
	if (resBind == -1) 
	{
		perror("Erreur connexion serveur");
		exit(1);
	}
	do
	{	
		int resListen=listen(s_ecoute,5);
		if(resListen==-1)
		{
			perror("Erreur d'écoute");
			exit(1);
		}
		lg_addr=sizeof(struct sockaddr_in);
		s_service=accept(s_ecoute,(struct sockaddr*)&addr_client,&lg_addr);
		if(s_service==-1)
		{
			perror("Erreur de socket de service");
			exit(1);	
		}
		
		nb_octets = read(s_service, message, TAILLEBUF); 
		chaine_recue=(char *)malloc(nb_octets * sizeof(char));
		memcpy(chaine_recue,message,nb_octets);
		// connexion etablie, on envoie le message
		nb_octets = write(s_service, reponse, strlen(reponse)+1); 
		// on attend la réponse du serveur
		
		printf("Réponse reçue : %s \n", reponse);// on ferme la socket de service
		
		close(s_service);
	}
	while(strlen(chaine_recue)<1);

	close(s_ecoute);
}
