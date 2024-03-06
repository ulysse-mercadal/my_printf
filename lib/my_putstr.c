/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** print un str qvec myputchar
*/
#include "../prf.h"

int my_putstr(const char *str)
{
    int position = 0;

    while (str[position] != '\0') {
        my_putchar(str[position]);
        position ++;
    }
    return 0;
}
