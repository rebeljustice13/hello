#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(){
	printf("The p2 process is running but programm 1 will run on this process\n");
	execl("./p1","arg1","arg2","arg3",NULL);

	printf("This line will not be printed\n");

	//return 0;
}
