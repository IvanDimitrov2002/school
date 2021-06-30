#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[]){
    if(argc > 2){
        for(int i = 1; i < argc; i++){
            if(i != 1){
                write(STDOUT_FILENO, "\n", 1);
            }
            write(STDOUT_FILENO, "==> ", 4);
            write(STDOUT_FILENO, argv[i], strlen(argv[i]));
            write(STDOUT_FILENO, " <==\n", 5);
            int fd = open(argv[i], O_RDONLY);
            int status;
            char c;
            int lines = 0;
            while(lines < 10){
                status = read(fd, &c, 1);
                if(c == '\n'){
                    lines++;
                }
                write(STDOUT_FILENO, &c, status);
            }
        }
    } else
    {
        int fd = open(argv[1], O_RDONLY);
        int status;
        char c;
        int lines = 0;
        while(lines < 10){
            status = read(fd, &c, 1);
            if(c == '\n'){
                lines++;
            }
            write(STDOUT_FILENO, &c, status);
        }
    }
    
    return 0;
}