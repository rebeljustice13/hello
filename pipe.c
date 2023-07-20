#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


void main(){
	int fd[2];
	char buff[50];
	char data[50] = {};

	if(pipe(fd) == -1){
		perror("Pipe");
		exit(1);
	}

	sprintf(buff,"shivam is a good boy");

	write(fd[1],buff,strlen(buff));

	read(fd[0], data,5);
	printf("%s\n", data);

	read(fd[0], data,30);
	printf("%s\n",data);
}


