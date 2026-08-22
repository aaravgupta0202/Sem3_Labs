//Write a recursive C program to implement Selection Sort using pointers.
//•The recursive function should sort the array using the Selection Sort algorithm.
//•Access and manipulate the array elements using pointers (i.e., avoid using arr[i] style directly).
//•The program should read the array from the user in the main function, call the recursive sorting function, and display the sorted array.
#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *arr, int size, int index)
{
    if (index >= size - 1)
        return;

    int *min = arr + index;

    for (int *p = arr + index + 1; p < arr + size; p++)
    {
        if (*p < *min)
            min = p;
    }

    if (min != arr + index)
    {
        int temp = *min;
        *min = *(arr + index);
        *(arr + index) = temp;
    }

    selectionSort(arr, size, index + 1);
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
        scanf("%d", array + i);
    }

    selectionSort(array, size, 0);

    printf("Sorted array: ");
    for (int *p = array; p < array + size; p++)
    {
        printf("%d ", *p);
    }

    free(array);
    return 0;
}
