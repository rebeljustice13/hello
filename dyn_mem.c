#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <alloca.h>

int main(){
	int *cal;
       	cal = (int *)calloc(5,sizeof(int));
	if(cal == NULL){
		printf("Failed to allocate memory using malloc.\n");
	}

	for(int i=0;i<5;i++){
		cal[i] = cal[i]+1;
		printf("%d ",cal[i]);
	}
	printf("\n");
	int *mal = (int *)malloc(sizeof(int) * 5);
	for(int i=0; i<5; i++){
		mal[i] = mal[i] + 1;
		printf("%d ",mal[i]);
	}
	printf("\n");
	int* allo= alloca(5*sizeof(int));
	if(allo == NULL){
		printf("Failed to allocate memory \n");
	}
	for(int i=0; i<5; i++){
		allo[i] = i + 1;
                
        }
        printf("\n");
	for(int i=0; i<5; i++){
                
                printf("%d ",allo[i]);
        }


	//use of realloc
	printf("The use of reloc \n");
	int* relo = realloc(mal, 10);
	for(int i= 0; i<10;i++){
		printf("%d ",mal[i]);
	}
	free(cal);
	free(mal);
	
	return 0;

}


