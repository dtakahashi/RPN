#include <stdio.h>
#include <stdlib.h>
#include "draw.h"

void help();
extern unsigned char data[72][34];

//四角形を書く関数
void rect(int x0, int y0, int x1, int y1, int color){
  static int x,y;
  
  if(x0 < 0 || y0 < 0 || x1 > 72 || y1 > 34){
    printf("error x0 < 0 or y0 < 0\n");
    printf("error x1 > width or y1 > height\n");
  }
  for(x = x0; x < x1 + 1; x++){
    dot(x,y0,color);
    dot(x,y1,color);
  }
  for(y = y0 + 1; y < y1; y++){
    dot(x0,y,color);
    dot(x1,y,color);
  } 
}

//引数の数が足りないときにhelpを出す関数
void help(){
    printf("このプログラムは\n");
    printf("\n");
    printf("第1引数で与えられた72×34の白黒イメージのrawイメージデータに\n");
    printf("四角形を書き加え第2引数で与えられた名前のファイルに変換するプログラムです\n");
    printf("\n");
    printf("この文章が出ているということは引数の数が合っていないはずなので\n");
    printf("第1引数に72×34の白黒イメージのrawイメージデータの名前を\n");
    printf("第2引数には出力させるrawイメージデータの名前を\n");
    printf("それぞれ入力してください\n");
    exit(9);
}
