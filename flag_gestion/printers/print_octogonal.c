/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** print d / i flag
*/

#include <stdarg.h>
#include <stdio.h>
#include "../../prf.h"

int o_pres(int nbr, int i, char *str)
{
    int precision = 0;

    while (str[i] != '.') {
        if (str[i] == 'o')
            return (0);
        i++;
    }
    i++;
    if ((str[i] > 47) && (str[i] < 58)) {
        precision = (str[i] - 48);
        i++;
    }
    while ((str[i] > 47) && (str[i] < 58)) {
        precision = precision * 10 +(str[i] - 48);
        i++;
    }
    precision = precision - my_oct_len(nbr);
    if (precision < 0)
        return (0);
    return (precision + 1);
}

int printer_octo2(int *aop, int nbr, int preci)
{
    if (nbr < 0)
        my_putchar('-');
    if ((nbr > 0) && (aop[1] != 'a')) {
        my_putchar(aop[1]);
    }
    for (int c = 1; c < preci; c++)
        my_putchar('0');
    if (aop[4] == 1)
        my_putstr("0");
    pr_octal(nbr);
    return (my_int_len(nbr));
}

void printer_octo(int *aop, int i, char *str, int nbr)
{
    int c = 0;
    int field_w = width(str, i + 1, nbr, aop[3]) - i_pres(nbr, i + 1, str) - 1;

    if (aop[4] == 1) {
        c++;
    }
    if (aop[2] != 1) {
        while (field_w > my_int_len(nbr) + 1) {
            my_putchar(aop[0]);
            field_w --;
        }
        printer_octo2(aop, nbr, o_pres(nbr, i + 1, str) - c);
    } else {
        printer_octo2(aop, nbr, o_pres(nbr, i + 1, str) - c);
        while (field_w > my_int_len(nbr) + 1) {
            my_putchar(aop[0]);
            field_w --;
        }
    }
}

int return_octo(char *str, int i, int nbr)
{
    int wid = width(str, i + 1, nbr, 0) - 1;

    if (wid < my_oct_len(nbr))
        return my_oct_len(nbr) - 1;
    else
        return wid;
}

int print_octogonal(va_list ap, char *str, int i, int y)
{
    int nbr = va_arg(ap, int);
    int array_of_params [] = {' ', 'a', -1, -1, -1};

    while (str[i] != 'o') {
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
        if (str[i] == '#')
            array_of_params[4] = 1;
        i++;
    }
    printer_octo(array_of_params, y, str, nbr);
    return (return_octo(str, y, nbr));
}
