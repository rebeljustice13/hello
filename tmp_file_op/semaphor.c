#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>

static int total = 0;
sem_t sem;

void* thread_a(void* arg){
	//change the value of total
	int temp = 0;
	sem_wait(&sem);
	for(int i = 0;i < 10000; i++){
		temp = total;
		temp += 1;
		total = temp;
	}
	sem_post(&sem);
	printf("Thread_a: toatal value =%d\n",total);
}

#if 0

void* thread_b(void* arg){
        //change the value of total
        int temp = 0;
	sem_wait(&sem);
        for(int i = 0;i < 10000; i++){
                temp = total;
                temp += 1;
                total = temp;
        }
	sem_post(&sem);
        printf("Thread_b: toatal value =%d\n",total);
}

#endif



void main(){
	pthread_t t,p;
	int r,m;
	sem_init(&sem,0,1);
	r = pthread_create(&t,NULL,thread_a,NULL);
	if(r != 0){
		perror("Error in thread creation\n");
	}
	m = pthread_create(&p,NULL,thread_a,NULL);
	if(m != 0){
		perror("Error in thread creation p\n");
	}
	pthread_join(t,NULL);
	pthread_join(p,NULL);
	printf("MAIN: The total value is %d\n",total);

}





