//線分を描画するプログラム
#include <stdio.h>
#include <stdlib.h>
#include "draw.h"

#define LINE_XY 0
#define LINE_YX 1

extern unsigned char data[72][34];

void error_check(int *x0,int *y0,int *x1,int *y1);
void L_help();


//プログラム説明関数
void L_help(){
  printf("このプログラムは\n");
  printf("第1引数と第2引数で与えられた点と第3引数と第4引数で与えられた点の間に\n");
  printf("第5引数で与えられたグレイスケールの値をもつ線分を描画するプログラムです\n");
  printf("引数がおかしいはずなので再度確認して実行してください\n");
}

//点が範囲を越えていた場合点を範囲の一番外側に訂正する関数
void error_check(int *x0,int *y0,int *x1,int *y1){

  if(*x0<0){
    *x0=0;
  }else if(*x0>71){
    *x0=71;
  }
  if(*x1<0){
    *x1=0;
  }else if(*x1>71){
    *x1=71;
  }
  if(*y0<0){
    *y0=0;
  }else if(*y0>33){
    *y0=33;
  }
  if(*y1<0){
    *y1=0;
  }else if(*y1>33){
    *y1=33;
  }
}

//傾きが45度以下のときに斜めに線分を描画する関数
void line_xy(int x0,int y0,int x1,int y1,int color){
  static int x,katamuki_100,y_totyu;
  static int x_end_100,x_start_100,y_syoki_100;

  katamuki_100=(y1-y0)*100/(x1-x0);//傾きを計算する
#ifdef DEBUG
  printf("%d\n",katamuki_100);
#endif

  if(x1>x0){
    x_start_100=x0*100;
    x_end_100=x1*100;
    y_syoki_100=y0*100;
  }else{
    x_start_100=x1*100;
    x_end_100=x0*100;
    y_syoki_100=y1*100;
  }

  for(x=x_start_100;x<=x_end_100;x+=100){
    y_totyu=(katamuki_100*x-katamuki_100*x_start_100)/100+y_syoki_100;
    if(y_totyu%100>=50){
      y_totyu=y_totyu+100;
    }
    dot(x/100,y_totyu/100,color);
#ifdef DEBUG
    printf("%d,%d\n",x,y_totyu);
#endif
  }

}

//傾きが45度より大きいときに斜めに線分を描画する関数
void line_yx(int x0,int y0,int x1,int y1,int color){
  static int y,katamuki_100,x_totyu;
  static int y_start_100,y_end_100,x_syoki_100;

  katamuki_100=(x1-x0)*100/(y1-y0);//傾きを計算
#ifdef DEBUG
  printf("%d\n",katamuki_100);
#endif

  if(y1>y0){
    y_start_100=y0*100;
    y_end_100=y1*100;
    x_syoki_100=x0*100;
  }else{
    y_start_100=y1*100;
    y_end_100=y0*100;
    x_syoki_100=x1*100;
  }

  for(y=y_start_100;y<=y_end_100;y+=100){
    x_totyu=(katamuki_100*y-katamuki_100*y_start_100)/100+x_syoki_100;
    if(x_totyu%100>=50){
      x_totyu=x_totyu+100;
    }
    dot(x_totyu/100,y/100,color);
#ifdef DEBUG
    printf("%d,%d\n",y,x_totyu);
#endif
  }
  
}


//線分を判断する関数
int line_pattern(int x0,int y0,int x1,int y1){
  static int flag;

  if(abs(x1-x0)>=abs(y1-y0)){
    flag=LINE_XY;
  }else if(abs(x1-x0)<abs(y1-y0)){
    flag=LINE_YX;
  }
  return (flag); 
}

//線分描写の関数
void draw_line(int x0,int y0,int x1,int y1,int color){
  static int flag;

  flag=line_pattern(x0,y0,x1,y1);
  switch(flag){
  case LINE_XY:
    line_xy(x0,y0,x1,y1,color);
    break;
  case LINE_YX:
    line_yx(x0,y0,x1,y1,color);
    break;
  default:
    printf("error\n");
    exit(8);
  }
}
