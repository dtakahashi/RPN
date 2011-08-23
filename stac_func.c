#include <stdio.h>
#include "stac.h"
#include "enume.h"

void stack_func(FILE *in_file)
{
    int i, num;
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
        default:
            printf("*************error\n");
            break;
        }
    }
}
