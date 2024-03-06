/*
** EPITECH PROJECT, 2023
** flags
** File description:
** coding in c part 2 project printf
*/

#include <stdarg.h>
#include <stdio.h>
#include "../prf.h"

int big_switch_case4(char format, va_list ap, char *str, int *i_c)
{
    switch (format) {
    case 'p':
        i_c[1] = my_putstr("p");
        break;
    case 'n':
        i_c[1] = my_putstr("n");
        break;
    case 'E':
        i_c[1] = print_sci0(ap, str, i_c[0]);
        break;
    case 'd':
        i_c[1] = print_intd(ap, str, i_c[0], format);
        break;
    case 'x':
        i_c[1] = print_hexa_min(ap, str, i_c[0], i_c[0]);
        break;
    }
    return (i_c[1]);
}

int big_switch_case3(char format, va_list ap, char *str, int *i_c)
{
    switch (format) {
    case 'e':
        i_c[1] = print_sci(ap, str, i_c[0]);
        break;
    case 'g':
    case 'G':
        i_c[1] = my_putstr("g / G");
        break;
    case 'a':
    case 'A':
        i_c[1] = my_putstr("a / A");
        break;
    default:
        i_c[1] = big_switch_case4(format, ap, str, i_c);
        break;
    }
    return (i_c[1]);
}

int big_switch_case2(char format, va_list ap, char *str, int *i_c)
{
    switch (format) {
    case 'o':
        i_c[1] = print_octogonal(ap, str, i_c[0], i_c[0]);
        break;
    case 'u':
        i_c[1] = print_uint(ap, str, i_c[0], format);
        break;
    case 'X':
        i_c[1] = print_hexa_maj(ap, str, i_c[0], i_c[0]);
        break;
    case 'f':
    case 'F':
        i_c[1] = my_putstr("f / F");
        break;
    default:
        i_c[1] = big_switch_case3(format, ap, str, i_c);
        break;
    }
    return (i_c[1]);
}

int big_switch_case(char format, va_list ap, char *str, int *i_c)
{
    switch (format){
    case 'i':
        i_c[1] = print_int(ap, str, i_c[0]);
        break;
    case 's':
        i_c[1] = print_string(ap, str, i_c[0], 0);
        break;
    case 'c':
        i_c[1] = print_char(ap, str, i_c[0], 0);
        break;
    case '%':
        my_putchar('%');
        i_c[1] = 1;
        break;
    default:
        i_c[1] = big_switch_case2(format, ap, str, i_c);
        break;
    }
    return (i_c[1]);
}
