#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

void main(){

	int fd = mkfifo("shiva_fifo", 0666);

	if(fd < 0){
		perror("Mkfifo error\n");
	}
	char *msg = "India is my country";

	write(fd,msg,strlen(msg));

	close(fd);
}

