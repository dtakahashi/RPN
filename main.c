#include <stdio.h>
#include <stdlib.h>
#include "stac.h"

int main(int argc, char *argv[])
{
    FILE *in_file;
    if(argc != 2)
    {
        fprintf(stderr, "usage:in_file(bin)\n");
        exit(1);
    }
    
    in_file = fopen(argv[1], "rb");
    if(in_file == NULL)           
    {
        fprintf(stderr, "Error:file not found\n");
        exit(1);
    }


    stack_func(in_file);
    fclose(in_file);
    
    return (0);
}
