#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void signal_handler(int signo){
	if(signo == SIGINT)
		printf("Caught SIGINT\n");
	else if(signo == SIGTERM)
		printf("Caught SIGTERM\n");
//	exit(EXIT_SUCCESS);
}


static void display(int signo){
	printf("The signal detected is sigalarm\n");
	
	signal(SIGALRM,SIG_IGN);
	alarm(2);
}

void main(void){
	printf("\nProcess ID is %d\n",getpid());
	if(signal(SIGINT, SIG_IGN) == SIG_ERR){
		fprintf(stderr,"Cannot handle sighup\n");
		exit(-1);
	}

	if(signal(SIGTERM, SIG_DFL) == SIG_ERR){
		fprintf(stderr,"Cannot handle sigterm\n");
		exit(-1);
	}
	if(signal(SIGALRM,display) == SIG_ERR){
		fprintf(stderr, "Cannot handle sigaram");
	}
	alarm(2);
	while(1);
}
