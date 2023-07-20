#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	int buffer[20];
	int *ptr = buffer;
	for(int i=0; i< sizeof(buffer)/sizeof(int); i++){
		buffer[i] = 0;
		//*(ptr++) = 0;
	}
	printf("The data inserted successfully\n");

	for(int i=0; i< sizeof(buffer)/sizeof(int); i++){
                printf("%d ",*ptr++);
        }
	printf("\n");

}
