//pthread detach

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


static void *handle(void *arg){
	pthread_t thr;
	printf("Thread is running\n");
	pthread_detach(pthread_self());
	sleep(10);
	printf("Thread threadfunc exiting now\n");
}

void main(){
	pthread_t ptd;
	int s;
	
	s = pthread_create(&ptd,NULL,handle,NULL);

	if(s != 0)
		printf("Thread creation error\n");
	
	printf("Main thread exiting now\n");
	pthread_exit(NULL);
}
