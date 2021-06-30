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
// cmdline (char*) - C-string that is
// going to be parsed
// parsedString (char**) - Array full with 
// C-strings that are parsed from cmdline
//----------------------------------------------
void parse_cmdline(char **parsedString, char *cmdline){
    int i = 0;
    char *token = strtok (cmdline, " ");

    while (token != NULL)
    {
        parsedString[i++] = token;
        token = strtok (NULL, " ");
    }

    parsedString[i] = NULL;
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
    char *commands[size];
    
    while(1){
        printf("$ ");
        if(fgets(buffer, size, stdin) == NULL) break;
        if(buffer[0] == '\n') continue;

        buffer[strlen(buffer)-1] = '\0';

        parse_cmdline(commands, buffer);
        
        pid_t pid;
        int status;

        pid = fork();
        if(pid < 0){
            perror("fork");
            
        } else if(pid == 0){
            if(execvp(commands[0], commands) != 0){
                perror(commands[0]);
                exit(-1);
            }
            exit(0);
        } else {
            if(waitpid(pid, &status, 0) != pid){
                perror("");
            }
        }
    }
}

int main()
{
    shell();
    return 0;
}