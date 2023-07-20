#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

static void handler(int signo){

	if(signo == SIGUSR2){
		printf("SIGUSR2 catch\n");
	}
}




void main(int argc,char *argv[]){
	int i = 0;
	printf("Child-------------\n");
	printf("id = %d\n",getpid());

	if(signal(SIGUSR2, handler) == SIG_ERR){
		fprintf(stderr,"cannot handle siguser2\n");
		exit(-1);
	}

	for(i =0; i<argc ; i++){
		printf("Child argv[%d] = %s\n",i,argv[i]);
	}
	sleep(5);
	printf("Sending sigusr1 to parent\n");
	kill(getppid(),SIGUSR1);
	sleep(10);
	printf("Child exit\n");

}

