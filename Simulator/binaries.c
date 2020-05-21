#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "binaries.h"
#include <string.h>

int parse_input(char *command)
{
    char *token, *rest;

    command[strlen(command)-1] = '\0'; // replace the newline from input with null terminator
    
    // lowercase all input characters
    for (int i = 0; i < sizeof(command); i++)
    {
        command[i] = tolower(command[i]);
    }
        
    token = strtok_r(command, " ", &rest);
    if (token != NULL)
    {
        if (strcmp(token, "exit") == 0)
        {
            return 1;
        }        
        else if (strcmp(token, "yrot") == 0)
        {
            token = strtok_r(rest, " ", &rest);
            printf("Executing command yrot with arguments {%s}\n", token);
            // ds_yrot(reg,rand() % i,ds_Pi*ds_uniform(),0);
        }
        // else if ()
        // {
        //     /* code */
        // }
        
        else
        {
            printf("Command error.\n");
        }
        
    }
    return 0;
}