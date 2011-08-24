#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystring.h"
#include "enume.h"

int main(int argc, char *argv[])
{
    char buf[256];
    FILE *in_file, *out_file;

    if(argc != 3){
        fprintf(stderr, "usagi:text to bin in_file out_file\n");
        exit(1);
    }
    in_file = fopen(argv[1], "r");
    if(in_file == NULL)
    {
        fprintf(stderr, "Error :File not found\n");
        exit(1);
    }
    out_file = fopen(argv[2], "wb");
    if(out_file == NULL)
    {
        fprintf(stderr, "Error :File not found\n");
        exit(1);
    }
    while(fgets(buf, 256, in_file) != NULL)
    {
        if(strcmp(buf, "nop\n") == 0){
            fputc(NOP, out_file);
            fputc(0, out_file);
        }else if(strcmp(buf, "print\n") == 0){
            fputc(PRINT, out_file);
            fputc(0, out_file);
        }else if(strcmp(buf, "pop\n") == 0){
            fputc(POP, out_file);
            fputc(0, out_file);
        }else if(strncmp(buf, "push", 4) == 0){
            fputc(PUSH, out_file);
            fputc(0, out_file);
            double_point(buf, out_file);
        }else if(strcmp(buf, "+\n") == 0){
            fputc(PLUS, out_file);
            fputc(0, out_file);
        }else if(strcmp(buf, "-\n") == 0){
            fputc(MINUS, out_file);
            fputc(0, out_file);
        }else if(strcmp(buf, "*\n") == 0){
            fputc(MULTI, out_file);
            fputc(0, out_file);
        }else if(strcmp(buf, "/\n") == 0){
            fputc(DIVI, out_file);
            fputc(0, out_file);
        }else if(strcmp(buf, "%\n") == 0){
            fputc(MOD, out_file);
            fputc(0, out_file);
        }else if(strcmp(buf, "dnp\n") == 0){
            fputc(DNP, out_file);
            fputc(0, out_file);
        }else if(strcmp(buf, "rot\n") == 0){
            fputc(ROT, out_file);
            fputc(0, out_file);
        }else if(strcmp(buf, "img:show\n") == 0){
            fputc(SHOW, out_file);
            fputc(0, out_file);
        }else if(strcmp(buf, "img:init\n") == 0){
            fputc(INIT, out_file);
            fputc(0, out_file);
        }else if(strncmp(buf, "img:save", 8) == 0){
            fputc(SAVE, out_file);
            fputc(0, out_file);
            double_point(buf, out_file);
        }else if(strncmp(buf, "img:load", 8) == 0){
            fputc(LOAD, out_file);
            fputc(0, out_file);
            double_point(buf, out_file);
        }else if(strncmp(buf, "img:point", 9) == 0){
            fputc(POINT, out_file);
            fputc(0, out_file);
            double_point(buf, out_file);
        }else if(strncmp(buf, "img:line",  8) == 0){
            fputc(LINE, out_file);
            fputc(0, out_file);
            double_point(buf, out_file);
        }else if(strncmp(buf, "img:rect", 8) == 0){
            fputc(RECT, out_file);
            fputc(0, out_file);
            double_point(buf, out_file);
        }else if(strncmp(buf, "img:fill_rect", 13) == 0){
            fputc(FILL_RECT, out_file);
            fputc(0, out_file);
            double_point(buf, out_file);
        }else if(strncmp(buf, "img:tri", 7) == 0){
            fputc(TRI, out_file);
            fputc(0, out_file);
            double_point(buf, out_file);
        }else{
            printf("********************error %s\n", buf);
        }
    }

    fclose(out_file);
    fclose(in_file);
    
    return (0);
}
