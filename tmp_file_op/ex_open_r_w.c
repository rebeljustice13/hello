#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>


void main(){

	int fd,sz;
	char buff[18],suff[50];

	fd = open("shiva.txt",O_CREAT |O_EXCL |O_TRUNC | O_RDWR,0664);

	if(fd == -1){

		printf("The file cannot be oened\n");
	}

	//the file is opened
	
	strcpy(buff,"Hello from shivam");
	
	sz = write(fd,buff,strlen(buff));

	printf("The size of buffer are %d\n",sz);

	lseek(fd,0,SEEK_SET);

	sz = read(fd,suff,10);
	
	printf("The string in suff is %s\n",suff);
	printf("The size of suff are %d\n",sz);
	
	lseek(fd,0,SEEK_SET);

	lseek(fd,0,SEEK_END);


	write(fd,"Welcome to sasken",50);
	close(fd);
	printf("Exit");






}
