#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//#include <mutex.h>


static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static int glo = 0;

static void *handle1(void *arg){
	int loc;
	int ret = pthread_mutex_lock(&mtx);
	if(ret != 0)
		perror("pthread_mutex_lock");
	for(int i = 0;i <10000;i++){
		loc = glo;
		loc++;
	       glo = loc;
	}
#if 1
	ret = pthread_mutex_unlock(&mtx);
	if(ret != 0)
                perror("pthread_mutex_lock");

#endif 
	return NULL;
}

static void *handle2(void *arg){
        int loc;
	int ret;
	ret = pthread_mutex_lock(&mtx);
	if(ret != 0)
                perror("pthread_mutex_lock");

        for(int i = 0;i <10000;i++){
                loc = glo;
                loc++;
               glo = loc;

	}
	ret = pthread_mutex_unlock(&mtx);
	if(ret != 0)
                perror("pthread_mutex_lock");

	return NULL;
}

void main(){
	
	printf("running in main thread\n");
	pthread_t pt1,pt2;
	int s1,s2;
	
	s1 = pthread_create(&pt1,NULL,handle1,NULL);
	if(s1 != 0)
		perror("pthread_create");
	s2 = pthread_create(&pt2,NULL,handle2,NULL);
	if(s2 != 0)
		perror("pthread_create");

	


	pthread_join(pt1,NULL);
	pthread_join(pt2,NULL);
	printf("The global value is %d\n",glo);

	printf("Exiting from main thread");
	pthread_exit(NULL);
}
