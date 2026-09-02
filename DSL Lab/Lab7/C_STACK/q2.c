#include <stdio.h>
#include "stack.h"
int main()
{
    C_STACK s;
    char exp[MAX_SIZE];
    char ch, topElement;
    int i;
    int valid = 1;

    s.top = -1;

    printf("Enter an expression: ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++)
    {
        ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            c_push(&s, ch);
        }

        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (c_isEmpty(&s))
            {
                valid = 0;
                break;
            }
            topElement = c_pop(&s);
            if ((ch == ')' && topElement != '(') ||
                (ch == '}' && topElement != '{') ||
                (ch == ']' && topElement != '[')){
                valid = 0;
                break;
            }
        }
    }
    if (!c_isEmpty(&s)){
        valid = 0;
    }
    if (valid)
        printf("Parentheses are matching.\n");
    else
        printf("Parentheses are not matching.\n");

    return 0;
}

