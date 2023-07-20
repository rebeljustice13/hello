#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int doneflag = 0;
char buf[100];

//producer
void *threadA(void *p){
	printf("threadA scheduled first\n");
	sleep(1);
	pthread_mutex_lock(&mtx);
	printf("critical section");
	doneflag =1;
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&mtx);
}


//consumer thread

void *threadB(void *p){

	printf("Thread B scheduled first\n");
	pthread_mutex_lock(&mtx);
	if(doneflag == 0)
		pthread_cond_wait(&cond,&mtx);
	pthread_mutex_unlock(&mtx);
}


void main(){
	pthread_t pt1,pt2;
	pthread_create(&pt1,NULL,threadA,NULL);
	pthread_create(&pt2,NULL,threadB,NULL);

	pthread_join(threadA,NULL);
	pthread_join(threadB,NULL);

	return (EXIT_SUCCESS);
}




















