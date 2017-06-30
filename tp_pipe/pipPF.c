#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int p[2],retour,valeur;
	char *c,*s;
	valeur=0;
	pipe(p);
	c="1";
	write(p[1],c,1);
	if(retour==0){
		if(read(p[0],s,1)==-1){
			//sprintf(s,"%d",valeur);
		}else{
			valeur=atoi(s);
			if(valeur==9){
				exit(0);
			}
			valeur++;
			sprintf(c,"%d",valeur);
			write(p[1],c,1);
			printf("écriture %s",c);		
		}
		
	}
	else{
		if(read(p[0],s,1)==-1){
			//sprintf(s,"%d",valeur);
		}else{
			printf("écriture %s",s);
			valeur++;
			sprintf(c,"%d",valeur);
			write(p[1],c,1);
		}
		
		
	}
	return 0;
}
