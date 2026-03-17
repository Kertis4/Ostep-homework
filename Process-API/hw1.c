#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int
main(){
    int x = 100;
    int rc = fork();
    if (rc == 0) {
        x = 999;
        printf("(Child) value of x: %d \n" , x);
    }else {
        x= 45;
        printf("value of x: %d \n" , x);

    }
     printf("value of x: %d \n" , x);
    return 0;
}