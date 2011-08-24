#include <stdio.h>
#include <stdlib.h>
#include "draw.h"
#include "func.h"

unsigned char data[72][34];

//初期化関数
void init(){
    static int x,y;
    
    for(y = 0; y < 34; y++){
        for(x = 0; x < 72; x++){
            data[x][y] = 0;
        }
    }
    
}

//表示させる関数
void show(){
    static int x,y;
    
    for(y = 0; y < 34; y++){
        
        for(x = 0; x < 72; x++){
            if(data[x][y] == 0){
                printf("_");
            }else if(data[x][y] <= 128){
                printf("a");
            }else{
                printf("b");
            }
        }
        printf("\n");
    }
    
}

//データに値を格納する関数
void dot(int x, int y , int c){
    data[x][y] = c;
}

//点を描画する
void point(int x0, int y0, int color){
    dot(x0, y0, color);
}
