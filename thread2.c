//pthread_join(&thread,retval)


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define max 50

static void *handler(void *arg){
	
	sleep(5);

	if(max < 500){
		return (void *)" max < 500";
	}
	else{
		return (void *)"max > 500";
	}
}



void main(){
	pthread_t t1_id;
	void *res;
	int s;

	s = pthread_create(&t1_id,NULL,handler,NULL);
	printf("Running in main thread\n");
	if(s != 0){
		printf("Thread create error\n");
	}

	pthread_join(t1_id,&res);
	printf("Main thread: thread returned %s\n",(char *)res);

	printf("Main thread exiting now\n");
	pthread_exit(NULL);
}
