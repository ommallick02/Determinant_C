//C Program to calculate determinant
//Author : ommallick02.github.io

//Header Files and Macros
#include <stdio.h>
#include <math.h>
#define maxsize 10

//Function Declarations
int Input_Size();
void Input_Array(float array[maxsize][maxsize], int size);
void Print_Array(float array[maxsize][maxsize], int size);
float Determinant(float array[maxsize][maxsize], int size);
void Copy_Array(float array[maxsize][maxsize], float array1[maxsize][maxsize], int size, int row, int col);

//Main Function
int main(void)
{
    float array[maxsize][maxsize], det;

    //Input Order of Matrix
    int size = Input_Size();

    //Input Matrix
    Input_Array(array, size);

    //Print Matrix
    Print_Array(array, size);

    //Calculate and Print Determinant of Matrix
    det = Determinant(array, size);
    printf("\nDeterminant of the matrix is: %.2f\n", det);

    return 0;
}

//Function Definations
//Function to Input Order of Matrix
int Input_Size()
{
    int size;
    char ch;
    do
    {
        do
        {
            printf("\nEnter the order of the matrix (max. %d): ", maxsize);
            scanf(" %d", &size);
            scanf("%c", &ch);
        }
        while (ch != '\n');
    }
    while (size < 1 || size > maxsize);
    return size;
}
//Function to Input Matrix
void Input_Array(float array[maxsize][maxsize], int size)
{
    int i, j;
    for (i = 0; i < size; ++i)
    {
        printf("\nEnter Elements of Row %d:\n", i + 1);
        for (j = 0; j < size; ++j)
        {
            printf("Element %d: ", j + 1);
            scanf(" %f", &array[i][j]);
        }
    }
}
//Function to Print Matrix
void Print_Array(float array[maxsize][maxsize], int size)
{
    int i, j;
    printf("\nMatrix:\n");
    for (i = 0; i < size; ++i)
    {
        for (j = 0; j < size; ++j)
        {
            printf("%.2f\t", array[i][j]);
        }
        printf("\n");
    }
}
//Function to Calculate determinant
float Determinant(float array[maxsize][maxsize], int size)
{
    if (size == 1)
    {
        return array[0][0];
    }

    int i, j;
    float sum = 0, array1[size - 1][size - 1], sign, det;

    for (i = 0, j = 0; j < size; ++j)
    {
        sign = pow(-1, i + j);
        Copy_Array(array, array1, size, i, j);
        det = Determinant(array1, size - 1);
        sum += sign * array[i][j] * det;
    }
    return sum;
}
//Function to copy elements of one matrix to another
void Copy_Array(float array[maxsize][maxsize], float array1[maxsize][maxsize], int size, int row, int col)
{
    int i, j, k, l;
    for (i = 0, k = 0; i < size; ++i)
    {
        if (i == row)
        {
            continue;
        }
        for (j = 0, l = 0; j < size; ++j)
        {
            if (j == col)
            {
                continue;
            }
            array1[k][l] = array[i][j];
            ++l;
        }
        ++k;
    }
}