#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void main(){

	char *myfifo = "/tmp/shivam_fifo";
	char arr[50];

	mkfifo("/tmp/shivam_fifo",0660);

	int fd = open(myfifo, O_RDONLY);

	while(1){

		printf("The string is = ");

		read(fd,arr,50);

		printf("%s\n",arr);

	}

	close(fd);


}

