/*
** EPITECH PROJECT, 2023
** task03 pointer
** File description:
** coding in c Day06 pointer
*/

#include "../prf.h"

static int compt(char *str)
{
    int j = 0;

    while ( str[j] != '\0' ){
        j++;
    }
    return j;
}

char *my_revstr(char *strr)
{
    int i = compt(strr);
    int half = 0;
    int left = 0;
    int right = 0;
    char s = 0;
    char *pr;
    char *pl;

    half = (i - ( i % 2 )) / 2;
    right = i - 1;
    while ((right >= half) && (left < half)){
        pr = &strr[right];
        pl = &strr[left];
        s = *pl;
        *pl = *pr;
        *pr = s;
        right--;
        left++;
    }
    return strr;
}
