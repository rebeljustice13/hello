
#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    int fd;
    size_t len;
    char *addr;

    fd = shm_open("/shm_1",O_CREAT | O_RDWR, 0660);
    if(fd == -1){
        perror("creating error\n");
        exit(-1);
    }

    printf("shm open successfully\n");
    len = strlen(argv[1]);
    
    //giving the memory to the shared memory 
    //at the time of creation the size if 0
    if(ftruncate(fd,len) == -1){
        perror("ftrucate\n");
        exit(-1);
    }

    printf("Resizzed to %ld bytes\n",(long)len);

    addr = mmap(NULL,len, PROT_WRITE | PROT_READ, MAP_SHARED,fd,0);
    if(addr == MAP_FAILED){
        perror("mmap");
        exit(-1);
    }

    if(close(fd) == -1){
        perror("close");

    }
    memcpy(addr,argv[1],len);
    exit(0);
}