#if 0

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *handler(void *arg){

	char *str = (char *) arg;
	printf("Threadfunc: arguments passed to thread are: %s, pid = (%d)\n",str,getpid());
	sleep(2);
	pthread_t p = pthread_self();
	printf("P = %lu\n",p);
	printf("THreadfunc: exiting\n");
	return(0);
}


void main(){

	pthread_t t1;
	int s;

	s = pthread_create(&t1,NULL,handler,"HEllo world");
	if(s != 0){
		perror("Thread create error\n");
	}
	printf("Main thread: Message from main(), pid = (%d)\n",getpid());
	pthread_t mp = pthread_self();
	printf("Main thread id = %lu\n",mp);
	sleep(5);
	printf("Main thread: exiting now\n");

	exit(0);
}
#endif

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

static void *thread_hand(void *arg){

	pthread_t t1;
	t1 = pthread_self();
	char *s = (char *)arg;
	printf("Running in the thread\n");
	printf("The argument pass is %s\n",s);
	sleep(20);
	pthread_cancel(t1);
	printf("Not printed\n");
}


void main(){
	pthread_t pt;
	int s;

	s = pthread_create(&pt,NULL,thread_hand,"Shivam");
	printf("The current process id is %d\n",getpid());
	if(s != 0)
	{
		printf("Some error in thread occurance\n");
	}
	
	printf("The main thread is running\n");

	sleep(15);
	pthread_t t;
	t = pthread_self();
	printf("Exiting from the main thread\n");
	pthread_exit(0);
}

















