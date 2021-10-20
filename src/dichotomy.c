#include <stdio.h>

/**
 * Recherche par dichotomie dans un tableau d'entiers
 * @param array The array of values
 * @param size_t  The size of the array
 * @param value  The value to find
 * @return The position of the value found  or -1
 */
int find_by_dichotomy(int array[], int size_t, int value ) {
    int max = size_t, min = 0, position = 0, index = -1;

    if ( (value < array[max]) || (value > array[min]) )
    {
        do
        {
        position = (min + max) / 2;
        if (array[position] < value)
        {
            min = position;
            printf(" min : %d", min);
        }
        else{
            max =  position;
            printf(" max : %d", max);
        }

        } while (( array[position] != value ) || (value < array[max]));
    
    }
    
    
    if (array[position] == value )
    {
        index = position;
    }
    return index ;

}