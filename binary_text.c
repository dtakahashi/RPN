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
    out_file=fopen(argv[2], "w");
  
    n = fread(buf, sizeof(unsigned short), 100, in_file);
        
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
        case SEKI:
            fprintf(out_file, "*\n");
            break;
        case WARI:
            fprintf(out_file, "/\n");
            break;
        case AMARI:
            fprintf(out_file, "%\n");
            break;
        default :
            fprintf(stderr, "error %d\n", c);
            break;
        }
    }
    
    fclose(in_file);
    fclose(out_file);
    return (0);
}
