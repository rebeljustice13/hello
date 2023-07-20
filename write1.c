#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
//#include <errno.>

void main(){
	int buflen;
	char buff[100];
	FILE *fp;
	strncpy(buff,"Hello everyone my name is shivam",100);

	buflen = strlen(buff);

	int len = write(1,buff,buflen);
	printf("The length is %d\n",len);


	//create a file
	//int fd = open("my_file.txt", O_RDWR);
	int fd = open("my_file.txt",O_RDWR|O_CREAT);
	
	write(fd,buff,buflen);
	//close(fd); 
	const char *path = "/home/ee212899/Desktop/shivam_don.txt";	
	int pd =  open(path,O_WRONLY | O_CREAT, 0644);
	printf("The pd is %d\n",pd);
	close(pd);

	off_t offset = lseek(fd, 0, SEEK_SET);
	
	//read from the file
	char out[100];
	int sz = read(fd,out,buflen);
	out[sz] = '\0';
	printf("The value of the sz is %d\n",sz);
	printf("The value of read() - buffer %s\n",out);

}
