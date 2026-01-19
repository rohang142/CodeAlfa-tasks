#include <stdio.h>

/* Function declarations */
void readMatrix(int a[10][10], int r, int c);
void printMatrix(int a[10][10], int r, int c);
void addMatrix(int a[10][10], int b[10][10], int r, int c);
void multiplyMatrix(int a[10][10], int b[10][10], int r1, int c1, int r2, int c2);
void transposeMatrix(int a[10][10], int r, int c);

int main()
{
    int a[10][10], b[10][10];
    int r1, c1, r2, c2;
    int choice;

    printf("Matrix Operations Menu\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Multiplication\n");
    printf("3. Transpose of Matrix\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter rows and columns: ");
            scanf("%d %d", &r1, &c1);

            printf("Enter first matrix:\n");
            readMatrix(a, r1, c1);

            printf("Enter second matrix:\n");
            readMatrix(b, r1, c1);

            addMatrix(a, b, r1, c1);
            break;

        case 2:
            printf("Enter rows and columns of first matrix: ");
            scanf("%d %d", &r1, &c1);

            printf("Enter rows and columns of second matrix: ");
            scanf("%d %d", &r2, &c2);

            if(c1 != r2)
            {
                printf("Matrix multiplication not possible!\n");
            }
            else
            {
                printf("Enter first matrix:\n");
                readMatrix(a, r1, c1);

                printf("Enter second matrix:\n");
                readMatrix(b, r2, c2);

                multiplyMatrix(a, b, r1, c1, r2, c2);
            }
            break;

        case 3:
            printf("Enter rows and columns: ");
            scanf("%d %d", &r1, &c1);

            printf("Enter matrix:\n");
            readMatrix(a, r1, c1);

            transposeMatrix(a, r1, c1);
            break;

        default:
            printf("Invalid choice!");
    }

    return 0;
}

/* Function to read matrix */
void readMatrix(int a[10][10], int r, int c)
{
    int i, j;
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

/* Function to print matrix */
void printMatrix(int a[10][10], int r, int c)
{
    int i, j;
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

/* Matrix Addition */
void addMatrix(int a[10][10], int b[10][10], int r, int c)
{
    int i, j, sum[10][10];

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("Resultant Matrix (Addition):\n");
    printMatrix(sum, r, c);
}

/* Matrix Multiplication */
void multiplyMatrix(int a[10][10], int b[10][10], int r1, int c1, int r2, int c2)
{
    int i, j, k;
    int mul[10][10] = {0};

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            for(k = 0; k < c1; k++)
            {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Resultant Matrix (Multiplication):\n");
    printMatrix(mul, r1, c2);
}

/* Transpose of Matrix */
void transposeMatrix(int a[10][10], int r, int c)
{
    int i, j, t[10][10];

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            t[j][i] = a[i][j];
        }
    }

    printf("Transpose of Matrix:\n");
    printMatrix(t, c, r);
    
}

