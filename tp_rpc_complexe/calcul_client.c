/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calcul.h"


void
math_calcul_1(char *host)
{
	CLIENT *clnt;
	complex  *result_1;
	operandes  addition_1_arg;
	complex  *result_2;
	operandes  multi_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, MATH_CALCUL, MATH_VERSION_1, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = addition_1(&addition_1_arg, clnt);
	if (result_1 == (complex *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_2 = multi_1(&multi_1_arg, clnt);
	if (result_2 == (complex *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main11 (int argc, char *argv[])//par défaut non utilisé
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	math_calcul_1 (host);
exit (0);
}

int main()
{
	CLIENT *client;
	operandes param; 
	complex *resultat;
	client = clnt_create("kali", MATH_CALCUL, MATH_VERSION_1, "udp");
	if (client == NULL) 
	{
		perror("Erreur creation client\n");
		exit(1);
	}

	param.x.a=2;  param.y.a=3; 
	param.x.b=5;  param.y.b=4; 
	
	resultat = addition_1(&param, client);
	printf("L'addition de 2+5i et 3+4i= %f+%fi\n",resultat->a,resultat->b);

	resultat =multi_1(&param,client);
	printf("Le produit 2+5i et 3+4i= %f+%fi\n",resultat->a,resultat->b);

	return 0;

}

