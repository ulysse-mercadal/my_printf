/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** print a char with all param
*/
#include <stdarg.h>
#include "../../prf.h"
int get_string_width(char *str, int i)
{
    int result = 0;

    while ((str[i] < '1') || (str[i] > 58)) {
        if (str[i] == 's')
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

int return_string(char *str, int i, char *string)
{
    int width = get_string_width(str, i + 1);

    if (width < my_strlen(string))
        return my_strlen(string) - 1;
    else
        return width - 1;
}

int print_string(va_list ap, char *str, int i, int tab_left)
{
    char *string = va_arg(ap, char *);
    int width = get_string_width(str, i) - my_strlen(string) - 1;

    for (int y = i; str[y] != 'c'; y++)
        if (str[y] == '-')
            tab_left = 1;
    if (tab_left == 1) {
        my_putstr(string);
        while (width >= 0) {
            width --;
            my_putchar(' ');
        }
    } else {
        while (width >= 0) {
            width --;
            my_putchar(' ');
        }
    my_putstr(string);
    }
    return (return_string(str, i, string));
}
