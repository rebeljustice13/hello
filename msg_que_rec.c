#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <limits.h>

int main(int argc, char** argv){

	mqd_t queue;
	struct mq_attr attr;
	char *msg_ptr;
	ssize_t recvd;
	size_t i;

	if(argc < 2){
		fprintf(stderr,"Usage %s <queuename>\n", argv[0]);
		return 1;
	}

	queue = mq_open(argv[1],O_RDONLY | O_CREAT, 0600, NULL);

	if(queue == (mqd_t)-1){
		perror("mq_open");
		return 1;
	}

	if(mq_getattr(queue,&attr) == -1){
		perror("mq_getattr");
		return 1;
	}

	msg_ptr = calloc(1,attr.mq_msgsize);
	if(msg_ptr == NULL){
		perror("calloc for msg_ptr");
		mq_close(queue);
		return 1;
	}

	recvd = mq_receive(queue, msg_ptr,attr.mq_msgsize,NULL);
	if(recvd == -1){
		perror("mq_receive");
		return 1;
	}
	printf("REceive messag in msg queue %s\n",msg_ptr);
}


