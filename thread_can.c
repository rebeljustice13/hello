//thread_cancel()

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *handle(void *arg){
	printf("Now running in thread\n");
	for(int i =0;i<20;i++){
		printf("Running\n");
	}
	sleep(1);
	printf("Exiting from thread\n");
}

void main(){

	pthread_t thr;
	int s;

	s = pthread_create(&thr,NULL,handle,NULL);
	if(s != 0)
		printf("thread creation error\n");

	sleep(5);
	pthread_cancel(thr);
	printf("Main thread exiting now\n");
	pthread_exit(NULL);
}
