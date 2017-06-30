#include <stdio.h>
#include<stdlib.h>
#define N 6
void main()
{

        char *c;
        int p[2],nb_ecrits;
        c=(char *)malloc(N*sizeof(char));
        c="ABCEDEF";
        pipe(p);
        nb_ecrits=write(p[1],c,6);
        if(nb_ecrits==-1){
                printf("Erreur");
                exit(0);

        }
        printf("nb_ecrits = %d",nb_ecrits);


}
