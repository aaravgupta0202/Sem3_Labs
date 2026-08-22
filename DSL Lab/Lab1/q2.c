//2. Given an array of integers, implement binary search to find the position of a given key.
#include <stdio.h>
int main()
{
    int arr[100], n, i, k, m, l, r;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter key to search using binary search: ");
    scanf("%d", &k);
    l = 0;
    r = n;
    m = n/2;
    i = arr[m];
    while(arr[m] != k)
    {
         if(k>arr[m])
         {
              l = m+1;
              m = (l+r)/2;
         }
         else if(k<arr[m])
         {
              r = m-1;
              m = (l+r)/2;
         }
    }
    printf("Element found at index %d", m);
}
