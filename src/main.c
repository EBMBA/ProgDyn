/**
 * @file main.c
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
#include "../include/dichotomy.h"
#include "../include/knacksack.h"
#include "../include/pgcb.h"
#include <assert.h>

int main()
{
	int tab[10] = {1,2,3,4,5,6,7,8,9,10};
	assert(find_by_dichotomy(tab,10,11) == -1);
	assert(find_by_dichotomy(tab,10,4) == 3);
	assert(find_by_dichotomy(tab,10,0) == -1);

	// KnackSack 
	Object objectOne, objectTwo, objectThree;
	objectOne.value = 7;
	objectOne.weight = 6;

	objectTwo.value = 5;
	objectTwo.weight = 5;

	objectThree.value = 5;
	objectThree.weight = 5;

	Object tabBag[3] = {objectThree, objectTwo, objectOne}; 
	Object *bag ;
	int sizeBag = 3;
	bag = malloc(9 * sizeof(Object));
	if (bag == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit;
	}
	
	knackSack(tabBag, sizeBag, 10, bag);

	printf("----------------KNACKSACK----------------------\n");
	printObjectTab(bag, sizeBag);
	assert(bag[0].value == 7 && bag[0].weight == 6);

	// PGCB
	printf("----------------PGCB / GWS---------------------\n");
	int **matrix;
	int nrows = 20, ncols = 20, sizeMatrix = 20;
	matrix = createMatrix(nrows, ncols);
	
	initMatrix(matrix, sizeMatrix, 10);

	PGCB square = {0, 0, 0};

	square = gws(matrix, nrows, ncols);
	printf("x : %d\n", square.x);
	printf("y : %d\n", square.y);
	printf("size : %d\n", square.size);
	printMatrix(matrix, nrows);
	printf("---------------\n");
	printMatrixSquare(matrix, sizeMatrix, square);

	freeMatrix(matrix); //free(bag); 
	return (0);
}