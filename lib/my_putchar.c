/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** ecrire un carractere
*/
#include <unistd.h>
#include "../prf.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
