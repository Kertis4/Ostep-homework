#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int
main(){
    int pipefd[2];
    pid_t pid_out, pid_in;

    pipe(pipefd);

    if ((pid_out = fork()) == 0){
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);

        execl("/bin/cat", "cat","hw3.c", NULL);

    }
    if ((pid_in = fork()) == 0){
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[1]);

        execl("/usr/bin/grep", "grep","rc", NULL);

    }
    close(pipefd[0]);
    close(pipefd[1]);

    wait(NULL);
    wait(NULL);

    return 0;
}
