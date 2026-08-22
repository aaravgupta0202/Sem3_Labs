#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define MAX_SIZE 100

// Character Stack
typedef struct
{
    char ele[MAX_SIZE];
    int top;
} C_STACK;

// Integer Stack
typedef struct
{
    int ele[MAX_SIZE];
    int top;
} I_STACK;


// Character Stack Functions
bool c_isFull(C_STACK *s);
bool c_isEmpty(C_STACK *s);
void c_push(C_STACK *s, char item);
char c_pop(C_STACK *s);
char c_peek(C_STACK *s);


// Integer Stack Functions
bool i_isFull(I_STACK *s);
bool i_isEmpty(I_STACK *s);
void i_push(I_STACK *s, int item);
int i_pop(I_STACK *s);
int i_peek(I_STACK *s);

#endif
