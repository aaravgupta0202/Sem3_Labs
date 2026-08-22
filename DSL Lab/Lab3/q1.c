//1. Write a program to perform following string operations without using string handling functions:
//a.)length of the string
//b.)string concatenation
//c.)string comparison
//d.)to insert a sub string
//e.)to delete a substring

#include <stdio.h>

int main()
{
    char str1[100], str2[100], result[200];
    int i, j, k, pos, len, cmp, length;

    // a) Length of the string
    printf("Enter a string: ");
    scanf(" %[^\n]", str1);

    i = 0;
    while (str1[i] != '\0')
    {
        i++;
    }

    length = i;
    printf("Length of the string = %d\n\n", length);


    // b) String concatenation
    printf("Enter first string: ");
    scanf(" %[^\n]", str1);

    printf("Enter second string: ");
    scanf(" %[^\n]", str2);

    i = 0;
    while (str1[i] != '\0')
    {
        result[i] = str1[i];
        i++;
    }

    j = 0;
    while (str2[j] != '\0')
    {
        result[i] = str2[j];
        i++;
        j++;
    }

    result[i] = '\0';

    printf("Concatenated string = %s\n\n", result);


    // c) String comparison
    printf("Enter first string: ");
    scanf(" %[^\n]", str1);

    printf("Enter second string: ");
    scanf(" %[^\n]", str2);

    i = 0;
    cmp = 0;

    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            cmp = str1[i] - str2[i];
            break;
        }
        i++;
    }

    if (cmp == 0)
    {
        cmp = str1[i] - str2[i];
    }

    if (cmp == 0)
    {
        printf("Both strings are equal.\n\n");
    }
    else if (cmp > 0)
    {
        printf("First string is greater than second string.\n\n");
    }
    else
    {
        printf("First string is smaller than second string.\n\n");
    }

    // d) Insert a substring
    printf("Enter main string: ");
    scanf(" %[^\n]", str1);

    printf("Enter substring to insert: ");
    scanf(" %[^\n]", str2);

    printf("Enter position (0-indexed): ");
    scanf("%d", &pos);

    // Find length of main string
    i = 0;
    while (str1[i] != '\0')
    {
        i++;
    }

    length = i;

    if (pos < 0 || pos > length)
    {
        pos = length;
    }

    i = 0;
    k = 0;

    // Copy characters before position
    while (i < pos)
    {
        result[k] = str1[i];
        i++;
        k++;
    }

    // Copy substring
    j = 0;
    while (str2[j] != '\0')
    {
        result[k] = str2[j];
        j++;
        k++;
    }

    // Copy remaining characters
    while (str1[i] != '\0')
    {
        result[k] = str1[i];
        i++;
        k++;
    }

    result[k] = '\0';

    printf("String after insertion = %s\n\n", result);


    // e) Delete a substring
    printf("Enter main string: ");
    scanf(" %[^\n]", str1);

    printf("Enter starting position to delete (0-indexed): ");
    scanf("%d", &pos);

    printf("Enter number of characters to delete: ");
    scanf("%d", &len);

    // Find length of main string
    i = 0;
    while (str1[i] != '\0')
    {
        i++;
    }

    length = i;

    if (pos < 0 || pos >= length || len <= 0)
    {
        // Copy original string
        i = 0;
        while (str1[i] != '\0')
        {
            result[i] = str1[i];
            i++;
        }
        result[i] = '\0';
    }
    else
    {
        i = 0;
        k = 0;

        while (str1[i] != '\0')
        {
            if (i >= pos && i < pos + len)
            {
                i++;
            }
            else
            {
                result[k] = str1[i];
                i++;
                k++;
            }
        }

        result[k] = '\0';
    }

    printf("String after deletion = %s\n", result);

    return 0;
}
