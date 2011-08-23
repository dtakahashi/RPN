#include <stdio.h>
#include <stdlib.h>
#include "stac.h"
#define STACK_MAX 64

signed stack[STACK_MAX];

int stack_top = 0;

void stack_push(signed val)
{
    if(stack_top == STACK_MAX)
    {
        printf("Error:Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        stack[stack_top] = val;
        ++stack_top;
    }

}

signed stack_pop(void)
{
    if(stack_top == 0)
    {
        printf("Error:Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        --stack_top;
        return stack[stack_top];
    }
}
