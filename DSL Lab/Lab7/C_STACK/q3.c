#include <stdio.h>
#include <ctype.h>
#include "stack.h"

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

int main()
{
    C_STACK s;
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    int i, j = 0;
    char ch;

    s.top = -1;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        // Operand
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }

        // Opening bracket
        else if (ch == '(')
        {
            c_push(&s, ch);
        }

        // Closing bracket
        else if (ch == ')')
        {
            while (!c_isEmpty(&s) && c_peek(&s) != '(')
            {
                postfix[j++] = c_pop(&s);
            }

            if (!c_isEmpty(&s))
                c_pop(&s);
        }

        // Operator
        else
        {
            while (!c_isEmpty(&s) &&
                   precedence(c_peek(&s)) >= precedence(ch))
            {
                postfix[j++] = c_pop(&s);
            }

            c_push(&s, ch);
        }
    }

    // Pop remaining operators
    while (!c_isEmpty(&s))
    {
        postfix[j++] = c_pop(&s);
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

