#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int 
main(){
    int rc = fork();
    if (rc == 0){
        int pid = getpid();
        printf("process id: %d \n", pid);
    }else{
        int w = wait(NULL);
        printf("Value of Wait:%d \n", w);
    }
}
