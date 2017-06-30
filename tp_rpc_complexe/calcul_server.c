/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calcul.h"

complex *
addition_1_svc(operandes *argp, struct svc_req *rqstp)
{
	static complex  result;

	result.a=argp->x.a+argp->y.a;
	result.b=argp->x.b+argp->y.b;
	//printf("L'addition = %fi+%f/n ",reslutat.y,resultat.x);
	return &result;
}

complex *
multi_1_svc(operandes *argp, struct svc_req *rqstp)
{
	//(a+bi)(a+bi)=(aa-bb)+i(ab+ba)
	static complex  result;
	result.a=((argp->x.a * argp->x.b)-(argp->y.a * argp->y.b));
	result.b=((argp->x.a* argp->y.b)+(argp->x.a * argp->y.b));
	//printf("Le produit = %fi+%f/n ",reslutat.y,resultat.x);
	return &result;
}
