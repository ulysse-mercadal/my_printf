/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** calculate the len of a int
*/

#include "../prf.h"

int my_int_len(int nbr)
{
    int compt = 0;

    if (nbr < 0)
        nbr *= -1;
    while (nbr > 1) {
        nbr /= 10;
        compt++;
    }
    return (compt);
}
