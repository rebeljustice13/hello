#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


int main(){
	
	char *myfifo = "/tmp/shivam_fifo";

	mkfifo(myfifo,0660);

	char arr[80];

	int fd = open(myfifo, O_WRONLY);

	while(1){
		printf("Enter string to be sent via fifo\n");

		fgets(arr,80,stdin);

		write(fd,arr,strlen(arr)+1);
	}

	close(fd);

	return 0;
}


