#include <stdio.h>
#include "stack.h"


bool c_isFull(C_STACK *s)
{
    return s->top == MAX_SIZE - 1;
}

bool c_isEmpty(C_STACK *s)
{
    return s->top == -1;
}

void c_push(C_STACK *s, char item)
{
    if (c_isFull(s))
    {
        printf("Character Stack Overflow!\n");
        return;
    }

    s->ele[++s->top] = item;
}

char c_pop(C_STACK *s)
{
    if (c_isEmpty(s))
    {
        printf("Character Stack Underflow!\n");
        return '\0';
    }

    return s->ele[s->top--];
}

char c_peek(C_STACK *s)
{
    if (c_isEmpty(s))
        return '\0';

    return s->ele[s->top];
}




bool i_isFull(I_STACK *s)
{
    return s->top == MAX_SIZE - 1;
}

bool i_isEmpty(I_STACK *s)
{
    return s->top == -1;
}

void i_push(I_STACK *s, int item)
{
    if (i_isFull(s))
    {
        printf("Integer Stack Overflow!\n");
        return;
    }

    s->ele[++s->top] = item;
}

int i_pop(I_STACK *s)
{
    if (i_isEmpty(s))
    {
        printf("Integer Stack Underflow!\n");
        return -1;
    }

    return s->ele[s->top--];
}

int i_peek(I_STACK *s)
{
    if (i_isEmpty(s))
        return -1;

    return s->ele[s->top];
}
