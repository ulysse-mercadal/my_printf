/*
** EPITECH PROJECT, 2023
** coding for the flag n
** File description:
** coding in c part 2 evoluting...
*/

#include "my.h"
#include "../prf.h"

int my_stock(char const *str)
{
    int j = 0;

    while ( str[j] != '%' ){
        my_putchar(str[j]);
        j++;
    }
    return j;
}

int main(void)
{
    int nb;

    nb = my_stock("lalala%·\n");
    return nb;
}
