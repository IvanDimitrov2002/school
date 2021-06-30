#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    pid_t pid;
    int status;

    while(1){
        pid = fork();
        if(pid < 0){
            perror("fork");
            
        } else if(pid == 0){
            if(execvp(argv[1], &argv[1]) != 0){
                perror(argv[1]);
                return -1;
            }
        } else {
            if(waitpid(pid, &status, 0) != pid){
                perror("");
                return -1;
            }
            sleep(2);
        }
    }
    return 0;
}