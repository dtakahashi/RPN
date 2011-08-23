#include <stdio.h>
#include "mystring.h"

void cpy(int start, int end,int kaisu, char dst[][128], char src[]){

 int j;

 for(j=start; j<end; j++){
   dst[kaisu][j-start] = src[j];
 }
 dst[kaisu][j-start] = '\0';
 
}
