/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** print d / i flag
*/

#include <stdarg.h>
#include <stdio.h>
#include "../../prf.h"

int hm_pres(int nbr, int i, char *str)
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
    precision = precision - my_hexa_len(nbr);
    if (precision < 0)
        return (0);
    return (precision + 1);
}

int printer_hexa_min2(int *aop, int nbr, int preci)
{
    if (aop[4] == 1)
        my_putstr("0x");
    if (nbr < 0)
        my_putchar('-');
    if ((nbr > 0) && (aop[1] != 'a')) {
        my_putchar(aop[1]);
    }
    for (int c = 1; c < preci; c++)
        my_putchar('0');
    pr_hexa_min(nbr);
    return (my_int_len(nbr));
}

int printer_hexa_min(int *aop, int i, char *str, int nbr)
{
    int c = 0;
    int field_width = width(str, i + 1, nbr, aop[3]) - i_pres(nbr, i + 1, str);

    if (aop[4] == 1)
        field_width = field_width - 2;
    if (aop[2] != 1) {
        while (field_width > my_int_len(nbr)) {
            my_putchar(aop[0]);
            field_width --;
        }
        c = printer_hexa_min2(aop, nbr, hm_pres(nbr, i + 1, str));
    } else {
        c = printer_hexa_min2(aop, nbr, hm_pres(nbr, i + 1, str));
        while (field_width > my_int_len(nbr)) {
            my_putchar(aop[0]);
            field_width --;
        }
    }
    return (c);
}

int return_hexa_min(char *str, int i, int nbr)
{
    int wid = width(str, i + 1, nbr, 0) - 1;

    if (wid < my_hexa_len(nbr))
        return my_hexa_len(nbr) - 1;
    else
        return wid;
}

int print_hexa_min(va_list ap, char *str, int i, int y)
{
    int array_of_params [] = {' ', 'a', -1, -1, -1};
    int nbr = va_arg(ap, int);

    while (str[i] != 'x') {
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
    printer_hexa_min(array_of_params, y, str, nbr);
    return (return_hexa_min(str, y, nbr));
}
