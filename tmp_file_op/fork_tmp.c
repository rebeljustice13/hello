#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){

	pid_t pid1=0,pid2=0;

	int n = 0;
	pid1 = fork();
	int status = 0;
	if(pid1 == 0){
		//child process
		printf("This is the child process with process id %d\n",getpid());
		n = n +20;
	       printf("The n value = %d\n",n);

	       sleep(5);
	}
	
	else{
	//PARENT process 
	printf("The parent current running process is %d\n",pid1);	
	printf("The parent  current running process is %d\n",getpid());
	printf("The parent current running process is %d\n",getppid());

	n = n + 100;
	pid2= wait(&status);
	printf("The value of n = %d\n",n);
	}

	printf("The value of n outside the child or parent %d\n",n);
}



