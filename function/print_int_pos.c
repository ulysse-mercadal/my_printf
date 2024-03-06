/*
** EPITECH PROJECT, 2023
** print_int
** File description:
** coding in c part2
*/

#include <stdarg.h>
#include <stdio.h>
#include "./my.h"
#include "../prf.h"

int my_intlen(int nmb)
{
    int count = 0;

    while (nmb > 1){
        nmb /= 10;
        count++;
    }
    return count;
}

int print_int_pos(int d, va_list ap)
{
    if (d < 0)
        d *= -1;
    d = va_arg(ap, int);
    my_put_nbr(d);
    return my_intlen(d);
}
