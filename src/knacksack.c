/**
 * @file knacksack.c
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
#include "../include/knacksack.h"

/**
 * @brief Swap two Object in array of Objects
 * 
 * @param h Array of objects
 * @param index1 
 * @param index2 
 */
void swap_object(Object *h, int index1, int index2){
    Object temp = h[index1];
    h[index1] = h[index2];
    h[index2] = temp;
}

/**
 * @brief Calculate value on weight 
 * 
 * @param tab 
 * @param index 
 * @return float 
 */
float calculate(Object *tab, int index){
    return ((float) tab[index].value / tab[index].weight);
}

/**
 * @brief Sort array of Objects
 * 
 * @param tab array of Objects
 * @param size_t 
 */
void sort(Object *tab, int size_t){
    for (int i = 0; i < size_t -1 ; i++)
    {
        for (int j = i+1; j < size_t; j++)
        {
            if (calculate(tab, i) < calculate(tab, j))
            {
                swap_object(tab, i, j);
            }
            
        }
    }
}

/**
 * @brief Display array of Objects
 * 
 * @param tab array of Objects
 * @param size 
 */
void printObjectTab(Object *tab, int size){
    for (int i = 0; i < size; i++)
    {
        printf("Index : %d\n", i);
        printf("Value : %d\n", tab[i].value);
        printf("Weight : %d\n\n", tab[i].weight);
    }
    
}

/**
 * @brief Fill bag by the heaviest Object 
 * 
 * @param tab array of Objects
 * @param size Size of the array of Objects
 * @param weightMax Weight max that the bag can support 
 * @param final Bag 
 */
void knackSack(Object *tab, int size, int weightMax, Object *final){
    int w_conso = 0;
    printObjectTab(tab, size);
    sort(tab, size);
    printObjectTab(tab, size);
    for (int i = 0; i < size; i++)
    {
        if (tab[i].weight + w_conso <= weightMax)
        {
            final[i] = tab[i];
            w_conso+=tab[i].weight;
        }
    }
    
}

