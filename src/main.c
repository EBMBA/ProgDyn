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

	Object tabBag[3] = {objectOne, objectThree, objectThree}; 
	Object *bag ;
	bag = malloc(3 * sizeof(Object));
	bag = knackSack(tabBag, 3, 10);

	//printObjectTab(bag, 3);
	assert(bag[0].value == 7 && bag[0].weight == 6);

	// PGCB
	int **matrix;
	int nrows = 20, ncols = 20, sizeMatrix = 20;
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
	
	initMatrix(matrix, sizeMatrix, 10);

	free(matrix); free(bag); 
	return (0);
}