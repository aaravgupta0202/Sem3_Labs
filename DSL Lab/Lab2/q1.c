//1. Write a small function to find the smallest element in an array using pointers.
//In the main function, create a dynamically allocated array, read the values from the keyboard, and pass the array to the function.
//Display the result (smallest element) in the main function.
#include <stdio.h>
#include <stdlib.h>

int findSmallest(int *arr, int size)
{
    int min = *arr;

    for (int i = 1; i < size; i++)
     {
        if (*(arr + i) < min)
        {
            min = *(arr + i);
        }
    }
    return min;
}

int main()
{
    int size;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int *array = (int *)malloc(size * sizeof(int));

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", (array + i));
    }

    printf("The smallest element in the array is: %d\n", findSmallest(array, size));
    free(array);

    return 0;
}
