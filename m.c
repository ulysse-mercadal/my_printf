/*
** EPITECH PROJECT, 2023
** main for coding style
** File description:
** coding in c project printf
*/

#include "prf.h"
#include <stdarg.h>

int skip(char *str, int i, char flag)
{
    while (str[i] != flag)
        i++;
    return (i);
}

int my_printf_plus(char *str, int i, char main_flag, va_list ap)
{
    int r = 0;
    int c[] = {i, 0};

    if ((str[i] == '%') && (str[i - 1] != '%')) {
        main_flag = get_full_param(str, i + 1);
        c [1] = big_switch_case(main_flag, ap, str, c);
    } else if (str[i] == '%') {
        r++;
    } else {
        my_putchar(str[i]);
    }
    return (c[1]);
}
