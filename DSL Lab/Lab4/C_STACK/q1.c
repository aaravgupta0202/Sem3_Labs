
#include <stdio.h>
#include <string.h>
#include "stack.h"

int main()
{
    C_STACK s;
    char str[MAX_SIZE];
    int i, len;
    int palindrome = 1;

    s.top = -1;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    for (i = 0; i < len; i++)
    {
        c_push(&s, str[i]);
    }

    for (i = 0; i < len; i++)
    {
        if (str[i] != c_pop(&s))
        {
            palindrome = 0;
            break;
        }
    }

    if (palindrome)
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    return 0;
}
