#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

void main(){
	pid_t pid;
	pid = fork();

	if(pid == -1){
		printf("Error occur in forking\n");
		exit(-1);
	}

	else if(pid == 0){
		//I am child process
		printf("Child process executing\n");
		sleep(20);
		printf("Child process exited\n");
		exit(3);
	}

	else{
		printf("The parent process is running\n");
		printf("The parent process is exiting\n");
		exit(0);
	}
}

