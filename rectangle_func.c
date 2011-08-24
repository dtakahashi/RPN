//四角形を描くプログラム
#include <stdio.h>
#include <stdlib.h>
#include "draw.h"


extern unsigned char data[72][34];//データを入れる配列

//四角形の内側を満たす関数
void fill_rect(int x0, int y0, int x1, int y1, int color){
  static int x,y;

  if(x0 < 0 || y0 < 0 || x1 > 72 || y1 > 34){
    printf("error x0 < 0 or y0 < 0\n");
    printf("error x1 > width or y1 > height\n");
    exit (10);
  }
  for(x = x0; x < x1 + 1; x++){
    for(y = y0; y < y1 + 1; y++){
      dot(x, y, color);
    }
  }
}
