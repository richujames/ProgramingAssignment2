#include <stdio.h>
#include <stdlib.h>
#include "selforg.h"

/*
The function openFile takes a string argument representing the name of the file to be opened. It attempts to open the file in read mode. If the file is successfully opened, the function returns a file pointer. 
If the file could not be opened, the function returns NULL.

 */

FILE* openFile(char name[12])
{       
    FILE* inputfile = fopen(name,"r"); 
    if(inputfile == NULL){             
        printf("error opening file\n");
        return NULL;                   
    }
    return inputfile;                 
}

/*
This function, writeIntoFile, takes a file name as an argument. It attempts to open the file in write mode. The function then checks if the file opening was successful. If the file opening failed, it returns NULL.
If the file opening was successful, it returns a file pointer.
*/

FILE* writeIntoFile(char name[12])
{
    FILE* outputfile = fopen(name,"w");
    if(outputfile == NULL){            
        return NULL;                   
    }
}