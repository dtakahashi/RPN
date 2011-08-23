#include <stdio.h>
#include <string.h>
#include <mystring.h>

void num_and_atr(char buf[]){
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

    for(i = 1; i < num_array; i++){
        num[i] = atoi(str[i]);
    }
    
}
