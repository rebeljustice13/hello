
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mqueue.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

#define queue "/shivam_mq"


int main(){

    mqd_t mq;

    struct mq_attr attr;
    size_t msq_len;
    char buffer[256];

    //use mq_open to open the message queue
    if((mq = mq_open(queue,O_RDWR | O_CREAT, 0660, NULL)) == (mqd_t)-1){
        perror("mq_open");
        exit(1);
    }

    //using mq_getattr for retrive the attribute
    if(mq_getattr(mq,&attr)){
        perror("msq_attr");
        mq_close(mq);
        return 1;
    }

    printf("The message length is %d and maxsize %d\n",(int)attr.mq_msgsize,(int)attr.mq_maxmsg);

    sprintf(buffer,"Hello shivam how are you");

    //sending the message
    if(mq_send(mq,buffer,strlen(buffer)+1,0) == -1){
        perror("msq_send");
        exit(1);

    }

    printf("message send successfully\n");


    char* msq_ptr = calloc(1,attr.mq_msgsize);

    //receiving the message
    if(mq_receive(mq,msq_ptr,attr.mq_msgsize,0) == -1){
        perror("mq_receive");
        exit(1);
    }
    printf("Receive message: %s\n", buffer);

    if(mq_close(mq) == -1){
        perror("mq_close");
        exit(1);
    }

    if(mq_unlink(queue) == -1){
        perror("mq_unlink");
        exit(1);

    }
    printf("Message queue close and unlinked\n");

    return 0;
}
