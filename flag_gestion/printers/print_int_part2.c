/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** part 2 of the i flag gestion
*/

#include "../../prf.h"

int i_pres(int nbr, int i, char *str)
{
    int precision = 0;

    while (str[i] != '.') {
        if (str[i] == 'i')
            return (0);
        i++;
    }
    i++;
    if ((str[i] > 47) && (str[i] < 58)) {
        precision = (str[i] - 48);
        i++;
    }
    while ((str[i] > 47) && (str[i] < 58)) {
        precision = precision * 10 +(str[i] - 48);
        i++;
    }
    precision = precision - my_int_len(nbr);
    if (precision < 0)
        return (0);
    return (precision);
}
