/**
 * @file pgcb.c
 * @author Emile METRAL
 * @brief 
 * @version 0.1
 * @date 2021-10-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pgcb.h"

/**
 * @brief Create a Matrix object
 * 
 * @param nrows Number of rows
 * @param ncols Number of columns 
 * @return int** Matrix
 */
int **createMatrix(int nrows, int ncols){
    int **matrix;
    matrix = malloc(nrows * sizeof(int *));
	if(matrix == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit;
	}
	for (int i = 0; i < nrows; i++)
	{
		matrix[i] = malloc(ncols * sizeof(int));
		if(matrix[i] == NULL)
		{
			fprintf(stderr, "out of memory\n");
			exit;
		}
	}
    return matrix;
}

/**
 * @brief Free matrix's allocation memory 
 * 
 * @param matrix 
 */
void freeMatrix(int **matrix){
	free(matrix[0]);
	free(matrix);
}

/**
 * @brief Display initial matrix
 * 
 * @param matrix Matrix
 * @param size_t Size 
 */
void printMatrix(int **matrix, int size_t){
    for (int i = 0; i < size_t; i++)
    {
        for (int n = 0; n < size_t; n++)
        {
            if (matrix[i][n] == 1)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

/**
 * @brief Display final matrix
 * 
 * @param matrix 
 * @param size_t 
 * @param square Greatest free white suare object
 */
void printMatrixSquare(int **matrix, int size_t, PGCB square){
  
    for (int i = square.x; i > (square.x - square.size); i--)
    {
        for (int n = square.y; n > (square.y - square.size); n--)
        {
            matrix[i][n] = 2;
        }
    }
    
    for (int i = 0; i < size_t; i++)
    {
        for (int n = 0; n < size_t; n++)
        {
            if (matrix[i][n] == 1)
                printf("* "); 
            else if (matrix[i][n] == 2)
                printf("# ");             
            else
                printf("  ");
        }
        printf("\n");
    }
    
}

/**
 * @brief Initialize matrix 
 * 
 * @param matrix 
 * @param size_t 
 * @param numberOne Number of black square
 */
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

/**
 * @brief Return lower number of the three
 * 
 * @param a 
 * @param b 
 * @param c 
 * @return int 
 */
int min (int a, int b, int c){
    if ( a > b && c > b)
    {
        return b;
    }
    else if ( a < b && c > a)
    {
        return a;
    }
    else if ( a > c && c < b)
    {
        return c;
    }
}

/**
 * @brief Return the biggest number of the two
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int max (int a, int b){
    if ( a < b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

/**
 * @brief Find the biggest white square and return it. 
 * 
 * @param matrix 
 * @param nrows Number of rows
 * @param ncols Number of columns 
 * @return PGCB biggest white square object
 */
PGCB gws(int **matrix,int nrows, int ncols){
    int **newMatrix = createMatrix(nrows, ncols);

    for (int i = 0; i < ncols; i++)
    {
        newMatrix[0][i] = 1;
    }

    for (int i = 0; i < nrows; i++)
    {
        newMatrix[i][0] = 1;
    }

    PGCB res;
    res.size = 0;
    int resMax = 1;
    //printMatrix(newMatrix, nrows);

    for (int i = 1; i < nrows; i++)
    {
        for (int j = 1; j < ncols; j++)
        {
            if( (matrix[i][j] == matrix[i-1][j]) && (matrix[i][j] == matrix[i][j-1])  && (matrix[i][j] == matrix[i-1][j-1]))
            {
                newMatrix[i][j] = 1 + min(newMatrix[i-1][j], newMatrix[i][j-1], newMatrix[i-1][j-1]);
                resMax = max(resMax, newMatrix[i][j]);

                if (resMax > res.size)
                {
                    res.size = resMax;
                    res.x = i;
                    res.y = j;
                }

                //printf("res : %d\nmatrix: %d\n", resMax, newMatrix[i][j]);

            }
            else
            {
                newMatrix[i][j] = 1;
            }
        }
        
    }
    //printMatrix(newMatrix, nrows);
    freeMatrix(newMatrix);    
    return res;
}