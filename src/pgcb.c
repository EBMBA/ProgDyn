#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pgcb.h"


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

void freeMatrix(int **matrix){
	free(matrix[0]);
	free(matrix);
}

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

void printMatrixSquare(int **matrix, int size_t, PGCB square){
  
    for (int i = square.x; i > (square.x - square.size); i--)
    {
        for (int n = square.y; n > (square.y - square.size); n--)
        {
            matrix[i][n] = 2;
            //printf("2\n");
        }
        printf("\n");
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

PGCB maxSquare(int **matrix, int size){
    PGCB square;
    int max = 1; 
    square.size = 1;

    for (int i = 1; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if( (matrix[i][j] != 0)){
                int leftTop = matrix[i-max][j-max];
                int rightTop = matrix[i-max][j];
                int left = matrix[i][j-max];
                printf("leftTop : %d\n", leftTop);
                printf("rightTop : %d\n", rightTop);
                printf("left : %d\n", left);
                

                if (leftTop != 1 && rightTop != 1 && left != 1)
                {
                    max ++;
                    printf("max : %d\n", max);
                }
                if (max > square.size)
                {
                    square.size = max;
                    square.x = i;
                    square.y = j;
                }
                
            }
        }
    }
    
    return square;
}



// int **pgcb(int **matrix,int y, int x, int nrows, int ncols){
//     // if (matrix ==  NULL)
//     // {
//     //     matrix = createMatrix(nrows, ncols);
//     //     return matrix;
//     // }
//     // if (matrix[x][y] == 1)
//     // {
//     //     return 0;
//     // }
//     // if (x == 0 || y == 0) {
//     //     return 1;
//     // }  
//     // else{
//     //     matrix[x][y] = 1 + min(PGCB(x-1,y-1),PGCB(x,y-1),PGCB(x-1,y));
//     //     return matrix[x][y];
//     // }
// }