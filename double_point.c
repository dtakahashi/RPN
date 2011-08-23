#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystring.h"

//文字列とスペースで区切られた数字列を読み込み数字列を数に変換する関数
void double_point(char buf[], FILE *out_file){
    int syou, amari;
    unsigned short input;
    int i, i_start, num_array;
    unsigned short num[64];
    char str[16][128];
    
    num_array = 0;
    i_start = 0;
    
    for(i = 0; i < strlen(buf); i++){
        if((buf[i]  == ' ') || (buf[i] == '\n')){
            cpy(i_start, i, num_array, str, buf);
            i_start = i + 1;
                num_array++;
        }
    }
    
    num[1] = atoi(str[1]);
    
    input = num[1];
    syou =  input / 256;
    amari = input % 256;
    fputc(amari, out_file);
    fputc(syou, out_file);
}
