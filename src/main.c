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
	bag = malloc(3 * sizeof(Object));
	bag = knackSack(tabBag, 3, 10);

	//printObjectTab(bag, 3);
	assert(bag[0].value == 7 && bag[0].weight == 6);

	// PGCB
	int **matrix;
	int nrows = 20, ncols = 20, sizeMatrix = 20;
	matrix = createMatrix(nrows, ncols);
	
	initMatrix(matrix, sizeMatrix, 10);

	PGCB square;
	square = maxSquare(matrix, sizeMatrix);
	printMatrixSquare(matrix, sizeMatrix, square);

	freeMatrix(matrix); free(bag); 
	return (0);
}