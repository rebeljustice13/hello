#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
	printf("Running in process 2\n");
	for(int i=0;i<argc;i++){
		printf("\n argv[%d] = %s\n",i,argv[i]);
	}

	return 0;
}
