/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** print d / i flag
*/

#include <stdarg.h>
#include <stdio.h>
#include "../../prf.h"

int h_pres(int nbr, int i, char *str)
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

int printer_hexa_maj2(int *aop, int nbr, int preci)
{
    if (aop[4] == 1)
        my_putstr("0X");
    if (nbr < 0)
        my_putchar('-');
    if ((nbr > 0) && (aop[1] != 'a')) {
        my_putchar(aop[1]);
    }
    for (int c = 1; c < preci; c++)
        my_putchar('0');
    pr_hexa_maj(nbr);
    return (my_int_len(nbr));
}

int return_hexa_maj(char *str, int i, int nbr)
{
    int wid = width(str, i + 1, nbr, 0) - 1;

    if (wid < my_hexa_len(nbr))
        return my_hexa_len(nbr) - 1;
    else
        return wid;
}

int printer_hexa_maj(int *aop, int i, char *str, int nbr)
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
        c = printer_hexa_maj2(aop, nbr, h_pres(nbr, i + 1, str));
    } else {
        c = printer_hexa_maj2(aop, nbr, h_pres(nbr, i + 1, str));
        while (field_width > my_int_len(nbr)) {
            my_putchar(aop[0]);
            field_width --;
        }
    }
    return (c);
}

int print_hexa_maj(va_list ap, char *str, int i, int y)
{
    int nbr = va_arg(ap, int);
    int array_of_params [] = {' ', 'a', -1, -1, -1};

    while (str[i] != 'X') {
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
    printer_hexa_maj(array_of_params, y, str, nbr);
    return (return_hexa_maj(str, y, nbr));
}
