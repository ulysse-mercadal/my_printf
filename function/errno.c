/*
** EPITECH PROJECT, 2023
** coding errno
** File description:
** coding in c part 2 errno
*/

#include <errno.h>
#include <stdarg.h>
#include "../prf.h"

int error_return(int errno)
{
    my_putstr(strerror(errno));
    return 0
}
