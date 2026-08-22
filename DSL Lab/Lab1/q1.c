//1. Given an array of n integers and a key element, write a C program to search the element using linear search.
#include <stdio.h>
int main()
{
    int arr[100], n, i, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter key to search: ");
    scanf("%d", &k);
    for(i = 0; i < n; i++)
    {
        if(arr[i] == k)
        {
            printf("Element found at index %d", i);
        }
    }
}
