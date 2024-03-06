/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** print d / i flag
*/

#include <stdarg.h>
#include <stdio.h>
#include "../../prf.h"

int e2_pres(int nbr, int i, char *str)
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

int printer_sci02(int *aop, float nbr, int preci)
{
    int b = 0;

    if (nbr < 0)
        my_putchar('-');
    if ((nbr > 0) && (aop[1] != 'a')) {
        my_putchar(aop[1]);
    }
    my_putfloat3(nbr, b, preci);
    return (my_int_len(nbr));
}

int printer_sci0(int *aop, int i, char *str, va_list ap)
{
    int c = 0;
    float nbr = va_arg(ap, double);
    int field_w = width(str, i + 1, nbr, aop[3]) - i_pres(nbr, i + 1, str) - 7;

    if (aop[2] != 1) {
        while (field_w > my_int_len(nbr)) {
            my_putchar(aop[0]);
            field_w --;
        }
        c = printer_sci02(aop, nbr, e2_pres(nbr, i + 1, str));
    } else {
        c = printer_sci02(aop, nbr, e2_pres(nbr, i + 1, str));
        while (field_w > my_int_len(nbr)) {
            my_putchar(aop[0]);
            field_w --;
        }
    }
    return (c);
}

int print_sci0(va_list ap, char *str, int i)
{
    int array_of_params [] = {' ', 'a', -1, -1, -1};
    int y = i;

    while (str[i] != 'E') {
        if ((str[i] == '0') && ((str[i - 1] < 47) || (str[i - 1] > 58)))
            array_of_params[0] = '0';
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
    printer_sci0(array_of_params, y, str, ap);
    return 0;
}
