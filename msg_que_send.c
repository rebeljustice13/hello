#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <mqueue.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>

//what sys/stat.h refer for

int main(int argc,char **argv){
    mqd_t queue;
    struct mq_attr attrs;
    size_t msg_len;

    if(argc < 3){
        fprintf(stderr, "Add the argumets");
        return 1;

    }

    queue = mq_open(argv[1], O_WRONLY | O_CREAT, 0660, NULL);
    if(queue == (mqd_t)-1){
        perror("mq_open");
        return 1;
    }
    printf("%ul",(mqd_t)-1);


    if(mq_getattr(queue,&attrs) == -1){
        perror("mq_getattr");
        mq_close(queue);
        return 1;
    }

    printf("message queue mq_maxmsg = (%d), mq_msgsize is (%d)\n",(int)attrs.mq_maxmsg,(int)attrs.mq_msgsize);

    msg_len = strlen(argv[2]);

    if((long)msg_len > attrs.mq_msgsize){
        perror("msg to long for queue");
        mq_close(queue);
        return 1;
    }

    if(mq_send(queue,argv[2], strlen(argv[2]), 0) == -1){
	    perror("mq_send");
	    mq_close(queue);
	    return 1;
    }

    return 0;

}
