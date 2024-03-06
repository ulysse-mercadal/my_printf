/*
** EPITECH PROJECT, 2023
** float in scientist writing
** File description:
** coding in c part 2 printf flag e
*/

#include "../prf.h"

int condition(int c, int compt)
{
    if (compt <= 9) {
        my_putchar(48);
        my_put_nbr(compt);
    } else {
        my_put_nbr(compt);
    }
    if (c == 0)
        my_putchar('0');
    return 0;
}

int my_putfloat2(float a, int b, int preci)
{
    int c;
    int compt = 0;

    b = a;
    while (b > 9) {
        b /= 10;
        a /= 10;
        compt++;
    }
    c = (a * 1000000) - b * 1000000;
    if (compt == 1)
        c++;
    my_put_nbr(b);
    my_putchar('.');
    my_put_nbr(c);
    for (int c = 1; c < preci; c++)
        my_putchar('0');
    my_putstr("e+");
    condition(c, compt);
    return 0;
}
