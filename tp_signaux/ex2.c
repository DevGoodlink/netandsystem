#include<stdio.h>
#include<signal.h>
struct sigaction action;
int main(void){

action.sa_handler=SIG_IGN;
sigaction(SIGINT,&action,NULL);
sigaction(SIGQUIT,&action,NULL);
printf("les signaux, SIGINT et SIGQUIT sont ignorés \n");
sleep(30);
printf("rétablissement des signaux \n");
action.sa_handler=SIG_DFL;
sigaction(SIGINT,&action,NULL);
sigaction(SIGQUIT,&action,NULL);
while(1);

return 0;
}

