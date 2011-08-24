#include <stdio.h>
#include "stac.h"
#include "enume.h"
#include "draw.h"

void stack_func(FILE *in_file)
{
    int i, j, num;
    char name[][100] = {"result.txt", "image.txt", "graphic.txt"}; 
    unsigned short num_stack[128];
    unsigned short num1, num2;
    unsigned short buf[256];

    num = fread(buf, sizeof(unsigned short), 100, in_file);

    for(i = 0; i < num; i++){
        switch(buf[i])
        {
        case NOP:
            break;
        case PUSH:
            stack_push(buf[i + 1]);
            i++;
            break;
        case POP:
            stack_pop();
            break;
        case PRINT:
            printf("stack:%d\n",stack_pop());            
            break;
        case PLUS:
            num1 = stack_pop();
            num2 = stack_pop();
            stack_push(num1 + num2);
            break;
        case MINUS:
            num1 = stack_pop();
            num2 = stack_pop();
            stack_push(num2 - num1);
            break;
        case MULTI:
            num1 = stack_pop();
            num2 = stack_pop();
            stack_push(num1 * num2);
            break;
        case DIVI:
            num1 = stack_pop();
            num2 = stack_pop();
            stack_push(num2 / num1);
            break;
        case MOD:
            num1 = stack_pop();
            num2 = stack_pop();
            stack_push(num2 % num1);
        case DUP:
            num1 = stack_pop();
            stack_push(num1);
            stack_push(num1);
            break;
        case ROT:
            num1 = stack_pop();
            num2 = stack_pop();
            stack_push(num1);
            stack_push(num2);
            break;
        case SHOW:
            show();
            putchar('\n');
            break;
        case INIT:
            init();
            break;
        case SAVE:
            num1 = stack_pop();
            save(name[num1]);
            break;
        case LOAD:
            num1 = stack_pop();
            load(name[num1]);
            break;
        case POINT:
            for(j = 0; j < 3; j++){
                num_stack[j] = stack_pop();
            }
            point(num_stack[2], num_stack[1], num_stack[0]);
            break;
        case LINE:
            for(j = 0; j < 5; j++){
                num_stack[j] = stack_pop();
            }
            draw_line(num_stack[4], num_stack[3], num_stack[2], 
                      num_stack[1], num_stack[0]);
            break;
        case RECT:
            for(j = 0; j < 5; j++){
                num_stack[j] = stack_pop();
            }
            rect(num_stack[4], num_stack[3], num_stack[2],
                 num_stack[1], num_stack[0]);
            break;
        case FILL_RECT:
            for(j = 0; j < 5; j++){
                num_stack[j] = stack_pop();
            }
            fill_rect(num_stack[4], num_stack[3], num_stack[2],
                      num_stack[1], num_stack[0]);
            break;
        case TRI:
            for(j = 0; j < 7; j++){
                num_stack[j] = stack_pop();
            }
            draw_tri(num_stack[6], num_stack[5], num_stack[4], 
                     num_stack[3], num_stack[2], num_stack[1], num_stack[0]);
            break;
        default:
            printf("*************error \n");
            break;
        }
    }
}
