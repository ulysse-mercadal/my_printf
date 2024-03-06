/*
** EPITECH PROJECT, 2023
** print hexadecimal from decimal
** File description:
** coding in c print hexa
*/

#include <stdlib.h>
#include <stdio.h>
#include "../prf.h"

int pr_hexa_min(int ap)
{
    int i = 0;
    char str[my_int_len(ap) + 1];
    char hexadecimal[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
        '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    while (ap > 1){
        str[i] = hexadecimal[ap % 16];
        ap /= 16;
        i++;
    }
    str[i] = hexadecimal[ap % 16];
    if (str[i] == '0')
        str[i] = '\0';
    str[i + 1] = '\0';
    my_putstr(my_revstr(str));
    return 0;
}
