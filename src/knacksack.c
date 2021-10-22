#include <stdio.h>
#include <stdlib.h>
#include "../include/knacksack.h"

void swap_object(Object *h, int index1, int index2){
    Object temp = h[index1];
    h[index1] = h[index2];
    h[index2] = temp;
}

float calculate(Object *tab, int index){
    return ((float) tab[index].value / tab[index].weight);
}

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

void printObjectTab(Object *tab, int size_t){
    for (int i = 0; i < size_t; i++)
    {
        printf("Index : %d\n", i);
        printf("Value : %d\n", tab[i].value);
        printf("Weight : %d\n\n", tab[i].weight);
    }
    
}

Object *knackSack(Object *tab, int size_t, int weightMax){
    int w_conso = 0;
    //printObjectTab(tab, size_t);
    Object *final = malloc(size_t * sizeof(Object));
    sort(tab, size_t);
    //printObjectTab(tab, size_t);
    for (int i = 0; i < size_t; i++)
    {
        if (tab[i].weight + w_conso <= weightMax)
        {
            final[i] = tab[i];
            w_conso+=tab[i].weight;
        }
    }

    return final;
    
}

