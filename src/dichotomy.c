/**
 * @file dichotomy.c
 * @author Emile METRAL
 * @brief 
 * @version 0.1
 * @date 2021-10-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

/**
 * @brief Search by dichotomy in an integer array
 * @param array The array of values
 * @param size_t  The size of the array
 * @param value  The value to find
 * @return The position of the value found  or -1
 */
int find_by_dichotomy(int array[], int size_t, int value ) {
    int max = size_t, min = 0, position = 0, index = -1;

    do
    {
        position = (min + max) / 2;
        if (array[position] < value)
        {
            min = position+1;
            //printf(" min : %d", min);
        }
        else{
            max =  position-1;
            //printf(" max : %d", max);
        }
        if (min >= max)
            break;

    } while ( array[position] != value );


    if (array[position] == value )
    {
        index = position;
    }
    return index ;

}