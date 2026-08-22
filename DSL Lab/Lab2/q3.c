//Implement a C program to read, display, and find the product of two matrices using functions with appropriate parameters.
//•The matrices must be created using dynamic memory allocation (malloc or calloc).
//•Access matrix elements using array dereferencing (i.e., *(*(mat + i) + j) style).
#include <stdio.h>
#include <stdlib.h>

void readMatrix(int **mat, int rows, int cols)
{
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", (*(mat + i) + j));
        }
    }
}

void displayMatrix(int **mat, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
}

void multiplyMatrix(int **A, int **B, int **C, int r1, int c1, int c2)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            *(*(C + i) + j) = 0;

            for (int k = 0; k < c1; k++)
            {
                *(*(C + i) + j) += (*(*(A + i) + k)) * (*(*(B + k) + j));
            }
        }
    }
}

int main()
{
    int r1, c1, r2, c2;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2)
    {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    int **A = (int **)malloc(r1 * sizeof(int *));
    int **B = (int **)malloc(r2 * sizeof(int *));
    int **C = (int **)malloc(r1 * sizeof(int *));

    for (int i = 0; i < r1; i++)
        *(A + i) = (int *)malloc(c1 * sizeof(int));

    for (int i = 0; i < r2; i++)
        *(B + i) = (int *)malloc(c2 * sizeof(int));

    for (int i = 0; i < r1; i++)
        *(C + i) = (int *)malloc(c2 * sizeof(int));

    printf("First Matrix:\n");
    readMatrix(A, r1, c1);

    printf("Second Matrix:\n");
    readMatrix(B, r2, c2);

    printf("\nFirst Matrix:\n");
    displayMatrix(A, r1, c1);

    printf("\nSecond Matrix:\n");
    displayMatrix(B, r2, c2);

    multiplyMatrix(A, B, C, r1, c1, c2);

    printf("\nProduct Matrix:\n");
    displayMatrix(C, r1, c2);

    for (int i = 0; i < r1; i++)
        free(*(A + i));
    free(A);

    for (int i = 0; i < r2; i++)
        free(*(B + i));
    free(B);

    for (int i = 0; i < r1; i++)
        free(*(C + i));
    free(C);

    return 0;
}
