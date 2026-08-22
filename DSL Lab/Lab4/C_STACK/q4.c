
#include <stdio.h>
#include <ctype.h>
#include "stack.h"

int main()
{
    I_STACK s;
    char postfix[MAX_SIZE];

    int i;
    int operand1, operand2, result;

    s.top = -1;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        // Operand
        if (isdigit(postfix[i]))
        {
            i_push(&s, postfix[i] - '0');
        }

        // Operator
        else
        {
            operand2 = i_pop(&s);
            operand1 = i_pop(&s);

            switch (postfix[i])
            {
                case '+':
                    result = operand1 + operand2;
                    break;

                case '-':
                    result = operand1 - operand2;
                    break;

                case '*':
                    result = operand1 * operand2;
                    break;

                case '/':
                    result = operand1 / operand2;
                    break;

                default:
                    printf("Invalid operator!\n");
                    return 1;
            }

            i_push(&s, result);
        }
    }

    result = i_pop(&s);

    printf("Result = %d\n", result);

    return 0;
}
