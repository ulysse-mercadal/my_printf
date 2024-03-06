/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** calculate the len of a int
*/

int my_uint_len(unsigned int nbr)
{
    int compt = 0;

    while (nbr > 1) {
        nbr /= 10;
        compt++;
    }
    return (compt);
}
