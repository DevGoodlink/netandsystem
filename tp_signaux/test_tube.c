#include <stdio.h>
#include <stdlib.h>
#define N 6

main()
{
char *c,*s;
int p[2],nb_lus,nb_ecrits;
c=(char *)malloc(N*sizeof(char));
s=(char *)malloc(N*sizeof(char));
c="ABCDEF";
pipe(p);
if((nb_ecrits=write(p[1],c,N))==-1)
{
printf("Erreur d'écriture dans tube \n");
exit(0);
}
printf("nb_ecrits = %d \n",nb_ecrits);
if((nb_lus=read(p[0],s,N))==-1)
{
printf("Erreur de lecture dans le tube \n");
exit(0);
}
else
{
printf("Pas de caractère lu \n");
exit(0);
}
printf("La chaine lue est : %s \n",s);
}
