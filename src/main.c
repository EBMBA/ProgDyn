#include <stdio.h>
#include <stdlib.h>
#include "../include/dichotomy.h"
#include "../include/knacksack.h"
#include <assert.h>

int main()
{
	int tab[10] = {1,2,3,4,5,6,7,8,9,10};
	assert(find_by_dichotomy(tab,10,0) == -1);

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

	return (0);
}