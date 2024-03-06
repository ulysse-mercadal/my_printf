/*
** EPITECH PROJECT, 2023
** decimal into bin
** File description:
** coding in c part 2 bin
*/

#include <stdlib.h>
#include <stdio.h>
#include "../prf.h"

int pr_bin(int ap)
{
    int i = 0;
    char str[64];

    while (ap > 0){
        str[i] = ap % 2 + 48;
        ap /= 2;
        i++;
    }
    str[i] = ap % 2 + 48;
     if (str[i] == '0')
        str[i] = '\0';
    str[i + 1] = '\0';
    my_putstr(my_revstr(str));
}

int main(void)
{
    int ap = 789;

    pr_bin(ap);
}
