//3. Write a C program to sort a given list of elements using
//i)Bubble Sort
//ii)Selection Sort
//iii)Insertion Sort
#include <stdio.h>
int main()
{
    int arr[100], n, i, j, c, temp, min, ind, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter 0 for ascending, 1 for descending: ");
    scanf("%d", &c);
    if(c == 0)
    {
          printf("Enter 0 for Bubble Sort, 1 for Selection Sort, 2 for Insertion Sort: ");
          scanf("%d", &c);
          if(c == 0)
          {
               //Bubble Sort
               for(i = 0; i<n-1; i++)
               {
                    for(j = 0; j<n-1-i; j++)
                    {
                         if(arr[j]>arr[j+1])
                         {
                              temp = arr[j+1];
                              arr[j+1] = arr[j];
                              arr[j] = temp;
                         }
                    }
               }
               printf("Bubble Sort: \n");
          }

          else if(c ==1)
          {
               //Selection Sort
               for(i = 0; i<n; i++)
               {
                    min = arr[i];
                    ind = i;
                    for(j = i+1; j<n; j++)
                    {
                         if(arr[j]<min)
                         {
                              min = arr[j];
                              ind = j;
                         }
                    }
                    temp = arr[ind];
                    arr[ind] = arr[i];
                    arr[i] = temp;
               }
               printf("Selection Sort: \n");
          }

          else if(c == 2)
          {
               for (i = 1; i<n; ++i)
               {
                    key = arr[i];
                    j = i - 1;

                    while (j >= 0 && arr[j] > key)
                    {
                         arr[j + 1] = arr[j];
                         j = j - 1;
                    }
                    arr[j + 1] = key;
               }
          }
     }
     for(int i = 0; i<n; i++)
     {
          printf("%d   ", arr[i]);
     }
     printf("\n");
}
