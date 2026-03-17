#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int
main(){
    int rc = fork();
    if (rc == 0){
        printf("Hello");
    }else {
        wait(NULL);
        printf("Goodbye");
    }
}