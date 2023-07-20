
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>


int main(int argc, char *argv[]){
    int fd;
    char *addr;
    struct stat len;
    fd = shm_open("/shm_1",O_RDONLY,0);
    if(fd == -1){
        printf("shm open error\n");
    }
    fstat(fd,&len);
    addr = mmap(NULL,len.st_size, PROT_READ , MAP_SHARED, fd, 0);
    if(addr == MAP_FAILED){
        printf("mmap error\n");
        return -1;
    }
    printf("Read data from shared memory %s\n",addr);
    exit(0);
}
