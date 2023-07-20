#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>


//#define a 10

static int a = 100;


#if 0

void* add(){
	int a=10,b=20;
	printf("Sum = %d\n",a+b);
	printf("the another thread executes\n");
}

#endif


void* arg(void* val){
	int *data = (int *)val;
	printf("The sent variable is %d\n",*data);
	//int *data = (int *)val;
	printf("The a valude = %d\n",a);
	printf("The control is in arg\n");
	printf("The id of this thread is %ld",pthread_self());
}

//static int a=100;
void main(){

	pthread_t thr;
	int t,b=10;
	t = pthread_create(&thr,NULL,arg,&b);
	//t = pthread_create(&thr,NULL,add,NULL);
	if(t != 0){
		perror("Something went wrong in thread creation\n");
	}
	printf("MAIN: The thread is %ld",thr);
	pthread_join(thr,NULL);
	printf("The thread created successfully\n");
}

