//------------------------------------------------------------------------
// NAME: Ivan Dimitrov
// CLASS: XIb
// NUMBER: 13
// PROBLEM: #1
// FILE NAME: tail.c (unix file name)
// FILE PURPOSE:
// Replicating tail functionality
//------------------------------------------------------------------------
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

//------------------------------------------------------------------------
// FUNCTION: handleReadError
// Handles read errors
// PARAMETERS:
// name (char*) - name of the file at which the error raised
//------------------------------------------------------------------------
void handleReadError(char* name){
    write(STDERR_FILENO, "tail: error reading '", 21);
    write(STDERR_FILENO, name, strlen(name));
    write(STDERR_FILENO, "': ", 3);
    perror("");
}

//------------------------------------------------------------------------
// FUNCTION: handleWriteError
// Handles write errors
// PARAMETERS:
// (void)
//------------------------------------------------------------------------
void handleWriteError(){
    perror("tail: error writing 'standard output'");
}

//------------------------------------------------------------------------
// FUNCTION: handleOpenError
// Handles open errors
// PARAMETERS:
// name (char*) - name of the file at which the error raised
//------------------------------------------------------------------------
void handleOpenError(char* name){
    write(STDERR_FILENO, "tail: cannot open '", 19);
    write(STDERR_FILENO, name, strlen(name));
    write(STDERR_FILENO, "' for reading: ", 15);
    perror("");
}

//------------------------------------------------------------------------
// FUNCTION: handleInput
// Handles the STDIN
// PARAMETERS:
// (void)
//------------------------------------------------------------------------
void handleInput(){
    int i;
    int status_read, status_write, lines_count = 1, lines_count_check = 1;
    char c, buffer[5000] = "\0";

    //------------------------------------------------------------------------
    // Saves the input from STDIN to a buffer
    //------------------------------------------------------------------------
    while(1){
        status_read = read(STDIN_FILENO, &c, 1);
        if(status_read > 0){
            strncat(buffer, &c, 1);
        }
        else if(status_read == 0) break;
    }

    //------------------------------------------------------------------------
    // Count the newline characters in the buffer
    //------------------------------------------------------------------------
    for(i = 0; i < strlen(buffer); i++){
        if(buffer[i] == '\n'){
            lines_count++;
        }
    }

    //------------------------------------------------------------------------
    // Increments "i" to the point where the last 10 lines will be remaining
    //------------------------------------------------------------------------
    for(i = 0; lines_count_check < lines_count - 10; i++){
        if(buffer[i] == '\n'){
            lines_count_check++;
        }
    }

    //------------------------------------------------------------------------
    // Prints the last 10 lines of the buffer to the STDOUT
    //------------------------------------------------------------------------
    for(;i < strlen(buffer); i++){
        do{
            status_write = write(STDOUT_FILENO, &buffer[i], 1);
        } while(status_write == 0);
        if(status_write == -1){
            handleWriteError();
            break;
        }
    }
}

int main(int argc, char* argv[]){
    //------------------------------------------------------------------------
    // Handles the STDIN if no arguments are given
    //------------------------------------------------------------------------
    if(argc == 1){
        handleInput();
    }
    int had_error = 0;
    for(int i = 1; i < argc; i++){
        int status_write;
        //------------------------------------------------------------------------
        // Handles the STDIN if "-" argument is given
        //------------------------------------------------------------------------
        if(strcmp(argv[i], "-") == 0){
            if(i > 1){
                do{
                    status_write = write(STDOUT_FILENO, "\n", 1);
                } while(status_write == 0);
                if(status_write == -1){
                    if(had_error == 0){
                        if(argc < 2){
                            handleWriteError();
                        }
                        had_error = 1;
                    }
                }
            }

            if(argc > 2){
                do{
                    status_write = write(STDOUT_FILENO, "==> standard input <==\n", 23);
                } while(status_write == 0);
                if(status_write == -1){
                    if(had_error == 0){
                        if(argc < 2){
                            handleWriteError();
                        }
                        had_error = 1;
                    }
                }
            }

            handleInput();
            continue;
        }
        //------------------------------------------------------------------------
        // Opens a file
        //------------------------------------------------------------------------
        int fd = open(argv[i], O_RDONLY);
        if(fd == -1){
            handleOpenError(argv[i]);
            had_error = 1;
            continue;
        }

        int status_read, lines_count = 1, lines_count_check = 1;
        char c;

        //------------------------------------------------------------------------
        // Count the newline characters in the file
        //------------------------------------------------------------------------
        while(1){
            status_read = read(fd, &c, 1);
            if(status_read > 0){
                if(c == '\n') lines_count++;
            }
            else if(status_read == 0) break;
            else{
                handleReadError(argv[i]);
                had_error = 1;
                break;
            }
        }

        //------------------------------------------------------------------------
        // Goes back to the beginning of the file after the first read
        //------------------------------------------------------------------------
        lseek(fd, 0, SEEK_SET);

        //------------------------------------------------------------------------
        // Reads to the point where the last 10 lines will be remaining
        //------------------------------------------------------------------------
        while(lines_count_check < lines_count - 10){
            status_read = read(fd, &c, 1);
            if(status_read > 0){
                if(c == '\n') lines_count_check++;
            }
            else if(status_read == 0) break;
            else{
                handleReadError(argv[i]);
                had_error = 1;
                break;
            }
        }

        if(i > 1 && had_error == 0){
            do{
                status_write = write(STDOUT_FILENO, "\n", 1);
            } while(status_write == 0);
            if(status_write == -1){
                if(had_error == 0){
                    handleWriteError();
                    had_error = 1;
                }
            }
        }

        //------------------------------------------------------------------------
        // Prints file's header if needed
        //------------------------------------------------------------------------
        if(argc > 2){
            char header[1000] = "\0";
            strcat(header, "==> ");
            strcat(header, argv[i]);
            strcat(header, " <==\n");
            do{
                status_write = write(STDOUT_FILENO, header, strlen(header));
            } while(status_write == 0);
            if(status_write == -1){
                if(had_error == 0){
                    if(argc < 2){
                        handleWriteError();
                    }
                    had_error = 1;
                }
            }
        }

        //------------------------------------------------------------------------
        // Prints the last 10 lines of the file to the STDOUT
        //------------------------------------------------------------------------
        while(1){
            status_read = read(fd, &c, 1);
            if(status_read > 0){
                do{
                    status_write = write(STDOUT_FILENO, &c, status_read);
                } while(status_write == 0);
                if(status_write == -1){
                    if(had_error == 0){
                        handleWriteError();
                        had_error = 1;
                    }
                }
            }
            else if(status_read == 0) break;
            else{
                if(had_error == 0){
                    handleReadError(argv[i]);
                    had_error = 1;
                }
                break;
            }
        }

        //------------------------------------------------------------------------
        // Closes the file and checks for any errors
        //------------------------------------------------------------------------
        if(close(fd) == -1){
            handleReadError(argv[i]);
            had_error = 1;
        };
        had_error = 0;
    }
    return 0;
}