/**
 * @file pgcb.h
 * @author Emile METRAL
 * @brief 
 * @version 0.1
 * @date 2021-10-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef PGCB_H
#define PGCB_H

/**
 * @brief PGCB structure for storage biggest white square parameters
 * 
 */
typedef struct 
{
    int x;
    int y;
    int size;
} PGCB;


int **createMatrix(int nrows, int ncols);
void freeMatrix(int **matrix);
void initMatrix(int **matrix, int size_t, int numberOne);
void printMatrixSquare(int **matrix, int size_t, PGCB square);
PGCB gws(int **matrix,int nrows, int ncols);
#endif