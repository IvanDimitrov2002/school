#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(){
    int pipefd[2];
    if(pipe(pipefd) == -1){
        perror("");
        return -1;
    }
    pid_t pid = fork();
    if(pid == 0){
        if(close(pipefd[0]) == -1){
            perror("");
            return -1;
        };
        if(dup2(pipefd[1], STDOUT_FILENO) == -1){
            perror("");
            return -1;
        }
        if(execlp("ls", "ls", "-l", NULL) == -1){
            perror("");
            return -1;
        }
        if(close(pipefd[1]) == -1){
            perror("");
            return -1;
        };
    } else if(pid > 0){
        if(close(pipefd[1]) == -1){
            perror("");
            return -1;
        };
        if(dup2(pipefd[0], STDIN_FILENO) == -1){
            perror("");
            return -1;
        }
        if(execlp("wc", "wc", "-l", NULL) == -1){
            perror("");
            return -1;
        }
        if(close(pipefd[0]) == -1){
            perror("");
            return -1;
        };
    } else {
        perror("fork");
        return -1;
    }
    return 0;
}