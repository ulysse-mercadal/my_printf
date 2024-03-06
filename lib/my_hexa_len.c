/*
** EPITECH PROJECT, 2023
** hexa maj
** File description:
** coding in c hexa maj
*/

#include <stdlib.h>
#include <stdio.h>
#include "../prf.h"

int my_hexa_len(int ap)
{
    int i = 0;
    char str[my_int_len(ap) + 1];
    char hexadecimal[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
        '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    while (ap > 1){
        str[i] = hexadecimal[ap % 16];
        ap /= 16;
        i++;
    }
    str[i] = hexadecimal[ap % 16];
    if (str[i] == '0')
        str[i] = '\0';
    str[i + 1] = '\0';
    return (my_strlen(str));
}
