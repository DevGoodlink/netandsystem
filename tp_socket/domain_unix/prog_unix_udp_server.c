#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include<string.h>
#define TAILLEBUF 20

int main(int argc, char *argv[]) {
    static struct sockaddr_un addr_client; // adresse socket coté client
    static struct sockaddr_un addr_serveur; // adresse socket locale
    int lg_addr; // longueur adresse
    int s_ecoute, s_service; // socket d'écoute et de service
    char message[TAILLEBUF]; // buffer qui contiendra le message reçu
    char *chaine_recue; // cha�ne re�ue du client 
    char *reponse = "Bien recu"; // cha�ne renvoy�e au client
    int nb_octets; // nombre d'octets re�us ou envoy�s
	s_ecoute=socket(AF_UNIX,SOCK_STREAM,0);
	if(s_ecoute==-1){
		perror("Erreur cr�ation socket");
		exit(1);
	}
	addr_serveur.sun_family=AF_UNIX;
	memcpy(addr_serveur.sun_path,"sock",strlen("sock"));
	int resBind = bind(s_ecoute,(struct sockaddr*)&addr_serveur,sizeof(addr_serveur));
	if(resBind==-1){
		perror("Erreur bind socket écoute");
		exit(1);
	}
	//configuration socket �coute : 5 connexions max en attente
	int resListen=listen(s_ecoute,5);	
	if(resListen==-1)
	{
		perror("Erreur listen");
		exit(1);	
	}
	lg_addr=sizeof(struct sockaddr_un);
	s_service=accept(s_ecoute,(struct sockaddr*)&addr_client,&lg_addr);
	if(s_service==-1)
	{
		perror("Erreur accept");
		exit(1);	
	}
	//la connexion est �tablie, on attend les donn�es envoy�es par le client
	nb_octets=read(s_service,message,TAILLEBUF);
	//affichage du message
	chaine_recue=(char*)malloc(nb_octets*sizeof(char));
	//allocation dynamique de la m�moire	
	memcpy(chaine_recue,message,nb_octets);
	printf("Message reçu  %s\n",chaine_recue);
	
	//on envoie la r�ponse au client
	nb_octets=write(s_service,reponse,strlen(reponse)+1);
	//on ferme les sockets
	close(s_service);
	close(s_ecoute);

}
