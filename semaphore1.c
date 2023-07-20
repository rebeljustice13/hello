
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){

    sem_t *sem;
    int flags,sval;
    unsigned int value;


    sem = sem_open("/sem1",O_CREAT | O_RDWR, 0660, 1);
    
    if(sem == SEM_FAILED){
        perror("sem open fail");
        return -1;
    }

    printf("sem open successfully\n");

    sem_getvalue(sem ,&sval);

    printf("Before sem_wait semaphore value = %d\n",sval);

    sem_wait(sem);

    sem_getvalue(sem,&sval);

    printf("after sem_wait semaphore value %d\n",sval);

    printf("Executing the critical section\n");

    sleep(10);

    sem_post(sem);

    sem_getvalue(sem,&sval);

    printf("agter sem_post semaphpre value %d\n",sval);






    return 0;
}