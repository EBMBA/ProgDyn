#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatrix(int **matrix, int size_t){
    for (int i = 0; i < size_t; i++)
    {
        for (int n = 0; n < size_t; n++)
        {
            if (matrix[i][n] == 1)
                printf("* ");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void initMatrix(int **matrix, int size_t, int numberOne){

    int numberOneDone = 0;
    srand(time(NULL));

    for (int i = 0; i < size_t; i++)
    {
        for (int n = 0; n < size_t; n++)
        {
            matrix[i][n] = 0;
        }
    }

    while (numberOneDone < numberOne)
    {
        int col = rand() % size_t;
        int row = rand() % size_t;

        matrix[row][col] = 1;
        numberOneDone++;
    }
    
    
    printMatrix(matrix, size_t);
}
