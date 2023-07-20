#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

static void handler(int signo){
	if(signo == SIGUSR1){
		printf("Child Caught in SIGUSR1\n");
	}
}



void main(){

	pid_t cpid;
	int status = 0;
	cpid = fork();

	if(cpid == -1){
		printf("fork error\n");
		exit(-1);
	}
	else if(cpid == 0){
		//child process
		execl("./sigusr2","arg1","arg2",NULL);
		printf("Child line is not printed\n");
		}
	else{
		if(signal(SIGUSR1,handler)==SIG_ERR){
			fprintf(stderr,"Cannot handle SIGUSR1");
			exit(-1);
		}
		printf("Child process = %d\n",cpid);
		sleep(2);
		kill(cpid,SIGUSR2);
		cpid = wait(&status);
		printf("parent id = %d\n",getpid());
	}

}
