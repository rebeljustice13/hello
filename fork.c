#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


int main(){
	pid_t cpid,cpid2;
	int status = 0;
	
	cpid = fork();

	if(cpid ==-1)
	{
		printf("The fork can not be created\n");
		exit(-1);
	}
	else if(cpid == 0){
		printf("This is the child process \n");
		printf("The process id of child process is %d\n",cpid);
		printf("This parent process id is %d\n",getppid());
		sleep(10);
		exit(3);
	}
	else{
		printf("This is the parent process this process id is %d\n",getpid());

	cpid2 = wait(NULL);
	//cpid2 = wait(&status);
	printf("\n cpid returned is (%d)\n",cpid2);
	printf("\n Status is (%d)\n",status);

	}
	return 0;
}


