//--------------------------------------------
// NAME: Ivan Dimitrov
// CLASS: XIb
// NUMBER: 13
// PROBLEM: #2
// FILE NAME: shell.c (unix file name)
// FILE PURPOSE:
// Simple shell interpreter
//---------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

//--------------------------------------------
// FUNCTION: parse_cmdline
// Gets C-string and parses it into an array
// of C-strings
// PARAMETERS:
// cmdline (const char*) - C-string that is
// going to be parsed
//----------------------------------------------
char** parse_cmdline(const char* cmdline){
    int i = 0;
    char *copy_cmdline = strdup(cmdline);
    char *t = strtok(copy_cmdline, " ");
    char **parsedString = NULL;

    while (t != NULL)
    {
        parsedString = realloc(parsedString, sizeof(char *) * (i+2));
        parsedString[i++] = t;
        t = strtok (NULL, " ");
    }
    
    parsedString[i] = NULL;

    return parsedString;
}

//--------------------------------------------
// FUNCTION: shell
// Shell that executes given commands
// PARAMETERS:
// (void)
//----------------------------------------------
void shell(){
    size_t size = 5000;
    char buffer[size];
    char **commands;
    
    while(1){
        printf("$ ");
        if(fgets(buffer, size, stdin) == NULL) break;
        if(buffer[0] == '\n') continue;
        
        buffer[strlen(buffer)-1] = '\0';

        commands = parse_cmdline(buffer);
        
        pid_t pid;
        int status;

        pid = fork();
        if(pid < 0){
            perror("fork");
        } else if(pid == 0){
            if(execvp(commands[0], commands) < 0){
                perror(commands[0]);
                free(*commands);
                free(commands);
                exit(-1);
            }
            exit(0);
        } else {
            if(waitpid(pid, &status, 0) != pid){
                perror("");
            }
        }
        free(*commands);
        free(commands);
    }
}

int main()
{
    shell();
    return 0;
}
