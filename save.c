#include <stdio.h>
#include <stdlib.h>
#include "draw.h"
#include "func.h"

unsigned char data[72][34];

//データを書き出す関数
void save(char *out_file){
    FILE *file;
    static int x, y;

    file=fopen(out_file,"w");
    
    for(y = 0; y < 34; y++){
        for(x = 0;x < 72; x++){
            fputc(data[x][y], file);
        }
    }  
    fclose(file);
}
