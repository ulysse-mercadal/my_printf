/*
** EPITECH PROJECT, 2023
** print octal number
** File description:
** coding in c octal
*/

#include <stdlib.h>
#include <stdio.h>
#include "../prf.h"

int pr_octal(int ap)
{
    int i = 0;
    char str[my_int_len(ap) + 1];

    while (ap > 1){
        str[i] = ap % 8 + 48;
        ap /= 8;
        i++;
    }
    str[i] = ap % 8 + 48;
    if (str[i] == '0')
        str[i] = '\0';
    str[i + 1] = '\0';
    my_putstr(my_revstr(str));
    return 0;
}
