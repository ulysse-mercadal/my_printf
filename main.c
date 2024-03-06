/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** main file of my_printf
*/
#include <stdio.h>
#include <stdarg.h>
#include "prf.h"

int is_a_main_flag_2(char letter)
{
    switch (letter) {
    case 'a':
    case 'c':
    case 's':
    case 'p':
    case 'n':
    case '%':
        return (letter);
        break;
    default:
        return ('w');
        break;
    }
}

char is_a_main_flag(char letter)
{
    switch (letter) {
    case 'd':
    case 'i':
    case 'o':
    case 'u':
    case 'x':
    case 'X':
    case 'e':
    case 'E':
    case 'f':
    case 'F':
    case 'g':
    case 'G':
    case 'A':
        return (letter);
        break;
    default:
        return (is_a_main_flag_2(letter));
        break;
    }
}

char get_full_param(char *str, int i)
{
    char main_flag = 'w';

    while (str[i] != '\0') {
        main_flag = is_a_main_flag(str[i]);
        if (main_flag != 'w')
            return (main_flag);
        i++;
    }
    return str[i];
}

int my_printf(char *str, ...)
{
    char main_flag;
    va_list ap;
    int char_displayed = -1;

    va_start(ap, str);
    for (int i = 0; str[i] != '\0'; i++) {
        char_displayed += my_printf_plus(str, i, main_flag, ap);
        if ((str[i] == '%') && (str[i - 1] != '%')) {
            main_flag = get_full_param(str, i + 1);
            i = skip(str, i, main_flag);
        }
        char_displayed ++;
    }
    va_end(ap);
    return char_displayed;
}
/*
int main(void)
{
    my_printf("hello %54.42s re hello\n", "heloo");
    printf("hello %54.42s re hello\n", "heloo");
}
*/
