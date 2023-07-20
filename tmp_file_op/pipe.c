#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

void main(){

	int fd[2];
	pid_t p;
	if(pipe(fd) == -1){
		fprintf(stderr, "pipe failed");
	
	}
#if 0
	p = fork();
	if(p < 0)
	{
		fprintf(stderr, "fork fail");
	}
#endif
	char buff[30];
	write(fd[1],"hello shivam",30);
	read(fd[0],buff,30);
	printf("The buffer is %s\n",buff);

}





