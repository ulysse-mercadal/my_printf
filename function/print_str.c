/*
** EPITECH PROJECT, 2023
** print_str
** File description:
** coding in c part 2
*/

#include <stdarg.h>
#include "./my.h"
#include "../prf.h"

int print_str(char *s, va_list ap)
{
    s = va_arg(ap, char *);
    my_putstr(s);
    return my_strlen(s);
}
