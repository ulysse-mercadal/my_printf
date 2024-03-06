/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** case flag = d
*/
#include <stdarg.h>
#include "../../prf.h"

int print_intd(va_list ap, char *str, int i, int c)
{
    int array_of_params [] = {' ', 'a', -1, -1};
    int y = i;

    while (str[i] != 'd') {
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
    c = printer_int(array_of_params, y, str, ap);
    return (c);
}
