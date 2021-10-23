/**
 * @file knacksack.h
 * @author Emile METRAL
 * @brief 
 * @version 0.1
 * @date 2021-10-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef KNACKSACK_H
#define KNACKSACK_H

typedef struct 
{
    int value;
    int weight;
} Object;

void knacksack(Object *tab, int size, int weightMax, Object *final);
void printObjectTab(Object *tab, int size);
#endif 


