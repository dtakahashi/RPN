#include <stdio.h>
#include <stdlib.h>
#include "draw.h"
#include "func.h"

unsigned char data[72][34];

//データを読み込む関数
void load(char *in_file){
    FILE *file;
    static int x,y;
    
    file=fopen(in_file,"r");
    
    if(file==NULL){
        fprintf(stderr, "ファイルの中身がありません\n");
        exit(10);
    }
    for(y = 0; y < 34; y++){
        for(x = 0; x < 72; x++){
            data[x][y] = fgetc(file);
        }
    }

    fclose(file);
    
}
