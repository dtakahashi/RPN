#include <stdio.h>
#include "stac.h"
#include "enume.h"
#include "draw.h"

void stack_func(FILE *in_file)
{
    int i, num, data;
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
        case DNP:
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
            data = buf[i + 1];
            save(save_name[data]);
            i++;
            break;
        case LOAD:
            data = buf[i + 1];
            load(load_name[data]);
            i++;
            break;
        case POINT:
            point(buf[i + 1], buf[i + 2], buf[i + 3]);
            i += 3;
            break;
        case LINE:
            draw_line(buf[i + 1], buf[i + 2], buf[i + 3], buf[i + 4], buf[i + 5]);
            i += 5;
            break;
        case RECT:
            rect(buf[i + 1], buf[i + 2], buf[i + 3], buf[i + 4], buf[i + 5]);
            i += 5;
            break;
        case FILL_RECT:
            fill_rect(buf[i + 1], buf[i + 2], buf[i + 3], buf[i + 4], buf[i + 5]);
            i += 5;
            break;
        case TRI:
            draw_tri(buf[i + 1], buf[i + 2], buf[i + 3], buf[i + 4], buf[i + 5],
                     buf[i + 6], buf[i + 7]);
            i += 7;
            break;
        default:
            printf("*************error \n");
            break;
        }
    }
}
