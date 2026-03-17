#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


//Exec vector needs the specific path
// int main(){
//     int rc = fork();
//     char *args[] = {"ls", NULL};
//     if (rc == 0) {
//         execv("/bin/ls", args);
//     }else{
//         printf("Parent Here \n");
//     }
// }

//exec vector path, will searhc for the file
// int main(){
//     int rc = fork();
//     char *args[] = {"ls", NULL};
//     if (rc == 0) {
//         execvp(args[0], args);
//     }else{
//         printf("Parent Here \n");
//     }
// }


// int main(){
//     int rc = fork();
//     char *args[] = {"/bin/ls", NULL};
//     if (rc == 0) {
//         execl("/bin/ls","ls", NULL);
//     }else{
//         printf("Parent Here \n");
//     }
// }


// int main(){
//     int rc = fork();
//     char *args[] = {"/bin/ls", NULL};
//     if (rc == 0) {
//         execlp("ls","ls", NULL);
//     }else{
//         printf("Parent Here \n");
//     }
// }

// int main(){
//     int rc = fork();
//     char *args[] = {"ls", NULL};
//     char *env[] = {"PATH=/bin", "HOME=/root", NULL};
//     if (rc == 0) {
//         execvpe(args[0], args, env);
//     }else{
//         printf("Parent Here \n");
//     }
// }

int main(){
    int rc = fork();
    char *args[] = {"/bin/ls", NULL};
    char *env[] = {"PATH=/bin", "HOME=/root", NULL};
    if (rc == 0) {
        execle("/bin/ls", "ls", NULL, env);
    }else{
        printf("Parent Here \n");
    }
}
