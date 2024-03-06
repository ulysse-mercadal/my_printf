/*
** EPITECH PROJECT, 2023
** my_put_str
** File description:
** print une string de nombres
*/
#include <stdio.h>
#include "../prf.h"

int my_put_nbr_quote(int nb, int g)
{
    if (nb < 0) {
        nb = -nb;
    }
    if ((nb >= 10) && (g != 0)) {
        my_put_nbr_quote(nb / 10, g - 1);
    }
    if ((nb >= 10) && (g == 0)) {
        my_put_nbr_quote(nb / 10, 2);
    }
    if ((g == 0) && (nb >= 10)){
        my_putchar(39);
    }
    my_putchar((nb % 10) + 48);
    return 0;
}
/*
int main (void)
{
    int g = 2;
    int nbr = 12345;

    my_put_nbr_quote(nbr, g);
    printf("\n%-4d", 12345);
}
*/
