/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** print float
*/

#include "../prf.h"

int my_putfloat(float a)
{
    int b;
    int c;

    b = a;
    c = (a * 100) - b * 100;
    my_put_nbr(b);
    my_putchar('.');
    my_put_nbr(c);
    if (c == 0)
        my_putchar('0');
    return 0;
}
