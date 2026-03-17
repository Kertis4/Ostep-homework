#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>



int
main(){
    int rc = fork();
    if (rc == 0){
        close(STDOUT_FILENO);
        printf("hello world\n");
    }else{
        printf("hellow wordl \n");
    }
}