#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int
main(){
    FILE *fptr;
    int rc = fork();
    fptr = fopen("file.txt", "a");
    if (rc == 0){
        
        fprintf(fptr, "Child Was here");
    }else{
        fprintf(fptr, "Parent Was here");
        
    }
    fclose(fptr); 
    return 0;
}