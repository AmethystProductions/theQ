#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include "binaries.h"

ds_Register reg_list[1];

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
            printf("Executing command {%s} with arguments {%s}\n", token, rest);
            int reg_index = GetInt(strtok_r(rest, " ", &rest)); 
            ds_Register reg = reg_list[reg_index];
            int q = GetInt(strtok_r(rest, " ", &rest)); 
            double theta = GetDouble(strtok_r(rest, " ", &rest)); 
            int time = GetInt(strtok_r(rest, " ", &rest));
            ds_yrot(reg, q, theta, time);
        }
        else
        {
            printf("Command error.\n");
        }
        
        // else if (strcmp(token, "yrot") == 0)
        // {
        //     printf("Executing command {%s} with arguments {%s}\n", token, rest);
        //     char** arguments = str_split(rest, ' ');
        //     ds_yrot(ds_reg, rand() % i,ds_Pi*ds_uniform(),0);
        // }
    }
    return 0;
}

int GetInt(char* arg)
{
    return 0;
}

double GetDouble(char* arg)
{
    return 0;
}