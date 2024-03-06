/*
** EPITECH PROJECT, 2023
** task02 pointer
** File description:
** coding in c D04 pointers
*/

#include <unistd.h>
#include <stdarg.h>
#include "my.h"
#include "../prf.h"

int my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0'){
        my_putchar(str[i]);
        i++;
    }
    return i;
}
