#include <stdio.h>
#include <stdlib.h>
#include "enume.h"

int main(int argc, char *argv[])
{
    int i, n;
    char c;
    unsigned short buf[256];
    FILE *in_file, *out_file;

    if(argc != 3){
        fprintf(stderr, "usagi:infile(bin) outfile\n");
        exit(1);
    }

    in_file=fopen(argv[1], "rb");
    if(in_file == NULL)
    {
        fprintf(stderr, "The file doesn't exist\n");
        exit(1);
    }

    n = fread(buf, sizeof(unsigned short), 100, in_file);
    fclose(in_file);

    out_file=fopen(argv[2], "w");
    if(out_file ==NULL)
    {
        fprintf(stderr, "The file doesn't exist\n");
        exit(1);
    }
    for(i = 0; i < n; i++){
        switch(buf[i]){
        case NOP:
            fprintf(out_file, "nop\n");
            break;
        case PUSH:
            fprintf(out_file, "push ");
            fprintf(out_file, "%d\n", buf[i + 1]);
            i++;
            break;
        case POP:
            fprintf(out_file, "pop\n");
            break;
        case PRINT:
            fprintf(out_file, "print\n");
            break;
        case PLUS:
            fprintf(out_file, "+\n");
            break;
        case MINUS:
            fprintf(out_file, "-\n");
            break;
        case MULTI:
            fprintf(out_file, "*\n");
            break;
        case DIVI:
            fprintf(out_file, "/\n");
            break;
        case MOD:
            fprintf(out_file, "%\n");
            break;
        default :
            fprintf(stderr, "error %d\n", c);
            break;
        }
    }
    
    fclose(out_file);
    return (0);
}
