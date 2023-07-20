// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// //#include <mutex.h>
// #include <semaphore.h>



// // static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
// static int glo = 0;
// sem_t sem;

// static void *handle1(void *arg){
// 	int loc;
// 	// int ret = pthread_mutex_lock(&mtx);
// 	// if(ret != 0)
// 	// 	perror("pthread_mutex_lock");

//     sem_wait(&sem);


// 	for(int i = 0;i <10000;i++){
// 		loc = glo;
// 		loc++;
// 	       glo = loc;
// 	}

//     sem_post(&sem);

// #if 0
// 	// ret = pthread_mutex_unlock(&mtx);
// 	// if(ret != 0)
//     //             perror("pthread_mutex_lock");

// #endif 
// 	return NULL;
// }

// #if 0

// static void *handle2(void *arg){
//         int loc;
// 	int ret;
// 	ret = pthread_mutex_lock(&mtx);
// 	if(ret != 0)
//                 perror("pthread_mutex_lock");

//         for(int i = 0;i <10000;i++){
//                 loc = glo;
//                 loc++;
//                glo = loc;

// 	}
// 	ret = pthread_mutex_unlock(&mtx);
// 	if(ret != 0)
//                 perror("pthread_mutex_lock");

// 	return NULL;
// }

// #endif 

// void main(){
	
// 	printf("running in main thread\n");
// 	pthread_t pt1,pt2,pt3;
// 	int s1,s2,s3;
	
// 	s1 = pthread_create(&pt1,NULL,handle1,NULL);
// 	if(s1 != 0)
// 		perror("pthread_create");
// 	s2 = pthread_create(&pt2,NULL,handle1,NULL);
// 	if(s2 != 0)
// 		perror("pthread_create");
//     s3 = pthread_create(&pt3,NULL,handle1,NULL);
// 	if(s3 != 0)
// 		perror("pthread_create");
    
//     if(sem_init(&sem, 0, 1) == -1){
//         perror("error during sem_init");
//         exit(1);
//     }
	


// 	pthread_join(pt1,NULL);
// 	pthread_join(pt2,NULL);
//     pthread_join(pt3,NULL);

//     sem_destroy(&sem);

// 	printf("The global value is %d\n",glo);

// 	printf("Exiting from main thread");
// 	pthread_exit(NULL);
// }


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

sem_t sem;
static int glo = 0;

static void* handle(void *arg){

    printf("thread fucntion %s running",(char*) arg);
    int ret;
    ret =sem_wait(&sem);

    printf("semaphore available in %s\n",(char*)arg);

    if(ret != 0){
        perror("semaphore wait error \n");

    }
    int loc;
    for(int i = 0;i < 10000; i++){
        loc = glo;
        loc++;
        glo = loc;
    }

    ret = sem_post(&sem);

    printf("Thread func end for %s\n",(char*)arg);

    return NULL;

}

int main(int argc,char *argv[]){
    pthread_t t1,t2,t3;
    int loops,s;

    s = pthread_create(&t1,NULL,handle,"thr 1");
    if(s!=0)
    perror("pthread_create");
    s = pthread_create(&t2,NULL,handle,"thr2");
    if(s!=0)
    perror("pthread_create");
    s= pthread_create(&t3,NULL,handle,"thr3");
    if(s!=0)
    perror("pthread_create");

    //sem_init
    if(sem_init(&sem,0,1) == -1){
        perror("Error during sem_init");
        exit(1);
    }

    s = pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);

    sem_destroy(&sem);
    printf("Value of glob after both thread running is = %d\n",glo);

    exit(0);

}