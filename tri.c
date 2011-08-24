//三角形を描画するプログラム
#include <stdio.h>
#include <stdlib.h>
#include "draw.h"

#define LINE_XY 0
#define LINE_YX 1

extern unsigned char data[72][34];

void Tri_help();

//プログラム説明関数
void Tri_help(){
  printf("このプログラムは\n");
  printf("第1引数と第2引数で与えられた点と第3引数と第4引数で与えられた点,\n");
  printf("さらには第5引数と第6引数で与えられた点との間に\n");
  printf("第7引数で与えられた値をもつ線分を書き、三角形を描画するプログラムです\n");
  printf("引数がおかしいはずなので再度確認して実行してください\n");
}

void draw_tri(int x0,int y0,int x1,int y1,int x2,int y2,int color){
  
  draw_line(x0,y0,x1,y1,color);
  draw_line(x1,y1,x2,y2,color);
  draw_line(x0,y0,x2,y2,color);
}
