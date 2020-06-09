
//  main.c
//  QuBOX
//
//  Created by Simon Devitt on 2/8/19.
//  Copyright © 2019 Simon Devitt. All rights reserved.
//

#include <stdlib.h>
#include <time.h>
#include "stdio.h"
#include <math.h>
#include "Simulator/sim.h"
#include "Simulator/norm.h"
#include <string.h>
//#include <stdint.h>
#include "Simulator/binaries.h"


int main(){
    
    int i,j,k,N, qubit;
    FILE *out=fopen("out.dat","w");
    clock_t start, end;
    double cpu_time_used;

    // create register with 12 qubits
    ds_Register reg;
    int exit = 0;
    int num_qubits = 12;
    start = clock();
    ds_initialize_simulator(0);
    reg = ds_create_register(num_qubits, 0, 0);
    reg_list[0] = reg;
    
    while (!exit)
    {
        char command[20];
        printf("%d qubits initialized, input command: \n", num_qubits);
        fgets(command, 20, stdin);

        exit = parse_input(command);
    }


    // for(i=1; i<=12; i++){
    //     printf("Qubits = %d\n", i);
    //     for(j=1; j<=100; j++){  
        
    //         start = clock();
    //         ds_initialize_simulator(0);
    //         reg = ds_create_register(i, 0, 0);
    //         ds_set_state(reg, 0, 1, 0);
    
    //         for(k=0; k<j; k++){
    //             ds_yrot(reg,rand() % i,ds_Pi*ds_uniform(),0);
    //         }
            
            ds_destroy_register(reg);
    
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            fprintf(out, "%d, %d, %f\n", i, j, cpu_time_used);
    //     }
    // }
    
    fclose(out);
    return 0;

}

;
/*-----------------------end-------------------------------*/

// Does not work, too many functions with too many varied arguments.
// typedef struct command_list 
// {
//     char *command;
//     void (*function)(char *arguments);
// }
