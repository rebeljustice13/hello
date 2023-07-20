#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>


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
		sleep(5);
		printf("Child process exited\n");
		printf("The process id of the child process is %d\n",getpid());
	
	}

	else{
		printf("The parent process is running\n");
		waitpid(pid,NULL,0);
		sleep(15);
		printf("The parent process is exiting\n");
		printf("The process id of the parent process is %d\n",getpid());
		
	}
}

