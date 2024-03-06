/*
** EPITECH PROJECT, 2023
** put nbr function
** File description:
** coding in c
*/

#include <stdarg.h>
#include "./my.h"
#include "../prf.h"

int my_put_nbr(int nmbr)
{
    if (nmbr < 0) {
        nmbr = nmbr * -1;
        my_putchar('-');
    }
    if (nmbr < -2147483647 || nmbr > 2147483647)
        return (84);
    if (nmbr >= 0 && nmbr <= 9)
        my_putchar(nmbr + '0');
    if (nmbr > 9) {
        my_put_nbr(nmbr / 10);
        nmbr %= 10;
        my_putchar(nmbr + '0');
    }
    return 0;
}
