/*
** EPITECH PROJECT, 2023
** flag g
** File description:
** coding in c project printf
*/

#include "../prf.h"

int my_putfloatg(float a)
{
    int b;
    int c;

    b = a;
    c = (a * 100) - b * 100;
    my_put_nbr(b);
    my_putchar('.');
    my_put_nbr(c);
    my_putchar('\n');
    return 0;
}
