/*
** EPITECH PROJECT, 2023
** my_strpy
** File description:
** copies a string to an other
*/
#include "../prf.h"
/*
int my_putchar(char c)
{
    write(1, &c, 1);
}

int  my_putstr(char *dest)
{
    int i = 0;

    while(dest[i] != '\0') {
        my_putchar(dest[i]);
        i++;
    }
}
*/
//fonction de swap
char *my_revstr(char *str)
{
    char swaper;
    int i = 0;
    int lengt;

    lengt = my_strlen(str) -1;
    while (i <= lengt / 2) {
        swaper = str[i];
        str[i] = str[lengt - i];
        str[lengt - i] = swaper;
        i ++;
    }
    return (str);
}
/*
int main(void)
{
    char str[] = "ca marche?";

    my_revstr(str);
}
*/
