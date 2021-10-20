#ifndef KNACKSACK_H
#define KNACKSACK_H

typedef struct 
{
    int value;
    int weight;
} Object;

Object *knacksack(Object *tab, int size_t, int weightMax);
void printObjectTab(Object *tab, int size_t);
#endif 


