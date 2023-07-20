#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>



#define BUF_SIZE 50

void main(int argc,char* argv[]){

	int pi[2];
	char buff[50];
	int numRead;

	if(pipe(pi) == -1){
		perror("pipe error");
		exit(1);
	}

	switch(fork()){

		case -1:
			perror("Error in fork creation\n");
			exit(-1);
			break;

		case 0:
			//runningin child

			if(close(pi[1]) == -1){
				exit(-1);
			}

			while(1){
				strcpy(buff,"");
				numRead = read(pi[0],buff,BUF_SIZE);
				if(numRead == -1)
				exit(-1);
				if(numRead == 0){
					printf("Parent close write end\n");
					break;
					}
				printf("Data received in child process is %s\n",buff);

				}
				if(close(pi[1]) == -1){
					exit(-1);
					}

				break;

		default :
			if(close(pi[0]) == -1)
				exit(-1);

			printf("Sending user input string to child process %s\n",argv[1]);
			write(pi[1],argv[1],strlen(argv[1]));
			sleep(2);
			if(close(pi[1]) == -1)
				exit(-1);
			wait(NULL);
			exit(0);

	}
	



}


