/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** print d / i flag
*/

#include <stdarg.h>
#include <stdio.h>
#include "../../prf.h"

int width(char *s, int i, int nbr, int is_a_quote)
{
    int result = -1;
    int nbr_quote = 0;

    nbr = 0;
    is_a_quote = 0;
    while ((s[i] < '1') || (s[i] > 58 )) {
        if ((s[i] > 96) && (s[i] < 123))
            return (nbr);
        if ((s[i] > 64) && (s[i] < 91))
            return (is_a_quote);
        i++;
        }
    if ((s[i] > '0') && (s[i] < 58)) {
        result = (s[i] - '0');
        i++;
        for (int y = i; (s[y] > 47) && (s[y] < 58); y++) {
            result = result * 10 + s[i] - '0';
        }
    }
    return (result - nbr_quote);
}

int printer_int2(char before, int group, int nbr, int preci)
{
    int g = -1;

    if (group == 1)
        g = 2;
    if (nbr < 0)
        my_putchar('-');
    if ((nbr > 0) && (before != 'a')) {
        my_putchar(before);
    }
    for (int c = 1; c <= preci; c++)
        my_putchar('0');
    my_put_nbr_quote(nbr, g);
    return (my_int_len(nbr));
}

int return_int(char *str, int i, int nbr)
{
    int wid = width(str, i + 1, nbr, 0);

    if (wid < my_int_len(nbr))
        return my_int_len(nbr);
    else
        return wid;
}

int printer_int(int *aop, int i, char *str, va_list ap)
{
    int nbr = va_arg(ap, int);
    int field_width = width(str, i + 1, nbr, aop[3]) - i_pres(nbr, i + 1, str);

    if (aop[1] != 'a')
        field_width --;
    if (aop[2] != 1) {
        while (field_width > my_int_len(nbr)) {
            my_putchar(aop[0]);
            field_width --;
        }
        printer_int2(aop[1], aop[3], nbr, i_pres(nbr, i + 1, str));
    } else {
        printer_int2(aop[1], aop[3], nbr, i_pres(nbr, i + 1, str));
        while (field_width > my_int_len(nbr)) {
            my_putchar(aop[0]);
            field_width --;
        }
    }
    return (return_int(str, i, nbr));
}

int print_int(va_list ap, char *str, int i)
{
    int array_of_params [] = {' ', 'a', -1, -1};
    int y = i;

    while (str[i] != 'i') {
        if ((str[i] == '0') && ((str[i - 1] < 47) || (str[i - 1] > 58)))
            array_of_params[0] = '0';
        if (str[i] == ' ')
            array_of_params[1] = ' ';
        if (str[i] == '+')
            array_of_params[1] = '+';
        if (str[i] == '-')
            array_of_params[2] = 1;
        if (str[i] == 39)
            array_of_params[3] = 1;
        i++;
    }
    printer_int(array_of_params, y, str, ap);
}
