/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** print the D / I param
*/
#include <stdarg.h>
#include <stdio.h>
#include "../../prf.h"

int printer_uint2(char before, int group, int nbr, int precision)
{
    int g = -1;
    unsigned int unbr = nbr;
    int conv_diff = my_uint_len(unbr) - my_int_len(nbr);

    if (group == 1)
        g = 2;
    if ((nbr > 0) && (before != 'a')) {
        my_putchar(before);
    }
    for (int compt = 1 + conv_diff; compt <= precision; compt ++)
        my_putchar('0');
    my_put_unbr_quote(nbr, g);
    return (my_int_len(nbr));
}

int return_uint(char *str, int i, int nbr)
{
    int wid = width(str, i + 1, nbr, 0);

    if (wid < my_uint_len(nbr))
        return my_uint_len(nbr) - 1;
    else
        return wid;
}

int printer_uint(int *aop, int i, char *str, int nbr)
{
    int c = 0;
    int f_width = width(str, i + 1, nbr, aop[3]) + 1 - i_upre(nbr, i + 1, str);

    if (aop[1] != 'a')
        f_width --;
    if (aop[2] != 1) {
        while (f_width > my_int_len(nbr)) {
            my_putchar(aop[0]);
            f_width --;
        }
        printer_uint2(aop[1], aop[3], nbr, i_upre(nbr, i + 1, str));
    } else {
        printer_uint2(aop[1], aop[3], nbr, i_upre(nbr, i + 1, str));
        while (f_width > my_int_len(nbr)) {
            my_putchar(aop[0]);
            f_width --;
        }
    }
}

int print_uint(va_list ap, char *str, int i, int c)
{
    int nbr = va_arg(ap, int);
    int array_of_params [] = {' ', 'a', -1, -1};
    int y = i;

    while (str[i] != 'u') {
        if ((str[i] == '0') && ((str[i - 1] < 47) || (str[i - 1] > 58)))
            array_of_params[0] = '0';
        if (str[i] == '-')
            array_of_params[2] = 1;
        if (str[i] == 39)
            array_of_params[3] = 1;
        i++;
    }
    printer_uint(array_of_params, y, str, nbr);
    return (return_uint(str, y, nbr));
}
