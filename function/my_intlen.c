/*
** EPITECH PROJECT, 2023
** my_intlen
** File description:
** coding in c part 2
*/

#include "my.h"

int my_intlen(int nmb)
{
    int count = 1;

    while (nmb > 1){
        nmb /= 10;
        count++;
    }
    return count;
}
