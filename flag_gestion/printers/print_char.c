/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** print a char with all param
*/
#include <stdarg.h>
#include "../../prf.h"
int get_char_width(char *str, int i)
{
    int result = 0;

    while ((str[i] < '1') || (str[i] > 58)) {
        if (str[i] == 'c')
            return (0);
        i++;
    }
    result = str[i] - 48;
    i++;
    while ((str[i] > 47) && (str[i] < 58)) {
        result = (result * 10);
        result = result + str[i] - 48;
        i++;
    }
    return (result);
}

int return_char(char *str, int i, int c)
{
    int width = get_char_width(str, i + 1) - 1;

    c = 1;
    if (width < 1)
        return c;
    else
        return width;
}

int print_char(va_list ap, char *str, int i, int tab_left)
{
    int width = get_char_width(str, i + 1) - 1;
    int c = va_arg(ap, int);

    for (int y = i; str[y] != 'c'; y++)
        if (str[y] == '-')
            tab_left = 1;
    if (tab_left == 1) {
        my_putchar(c);
        while (width >= 0) {
            width --;
            my_putchar(' ');
        }
    } else {
        while (width >= 0) {
            width --;
            my_putchar(' ');
        }
    my_putchar(c);
    }
    return (return_char(str, i, c));
}
