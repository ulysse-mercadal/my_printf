/*
** EPITECH PROJECT, 2023
** printf
** File description:
** all function in .h
*/

#include <stdarg.h>

#ifndef MY_H_
    #define MY_H_

int my_putfloat(float a);
int my_stock(char const *str);
int error_return(int errno);
int my_int_len(int nmb);
int i_upre(int nbr, int i, char *str);
int my_uint_len(int nmb);
int my_put_nbr(int nmbr);
int my_putfloatg(float a);
int my_printf_plus(char *str, int i, char main_flag, va_list ap);
int condition2(int c, int compt);
int condition(int c, int compt);
int my_putfloat2(float a, int b, int preci);
int my_putfloat3(float a, int b, int preci);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *strr);
int pr_hexadeci_maj(int ap);
int pr_hexadeci_min(int ap);
int pr_octal(int ap);
int print_int_pos(int d, va_list ap);
int print_str(char *s, va_list ap);
int my_put_nbr_quote(int nb, int g);
int my_printf(char *str, ...);
int skip(char *str, int i, char flag);
char is_a_main_flag(char letter);
int is_a_main_flag_2(char letter);
char get_full_param(char *str, int i);
int big_switch_case(char format, va_list ap, char *str, int *i_c);
int big_switch2_case(char format, va_list ap, char *str, int *i_c);
int big_switch3_case(char format, va_list ap, char *str, int *i_c);
int big_switch4_case(char format, va_list ap, char *str, int *i_c);
int create_pointeur(va_list ap, char *str, int i, char format);
int hexa_pointer(va_list ap, char *str, int i, char format);
int print_float_sci0(va_list ap, char *str, int i, char format);
int print_intd(va_list ap, char *str, int i, int c);
int print_int(va_list ap, char *str, int i);
int printer_int(int *aop, int i, char *str, va_list ap);
int printer_int2(char before, int group, int nbr, int precision);
int width(char *s, int i, int nbr, int is_a_quote);
int i_pres(int nbr, int i, char *str);
int pr_bin(int ap);
int print_uint(va_list ap, char *str, int i, int c);
int my_put_unbr_quote(unsigned int nb, int g);
int print_char(va_list ap, char *str, int i, int tab_left);
int my_strlen(const char *str);
int my_putstr(const char *str);
int print_string(va_list ap, char *str, int i, int tab_left);
int print_octogonal(va_list ap, char *str, int i, int y);
int my_oct_len(int ap);
int my_hexa_len(int ap);
int print_hexa_maj(va_list ap, char *str, int i, int y);
int pr_hexa_maj(int ap);
int pr_hexa_min(int ap);
int return_int(char *str, int i, int nbr);
int return_char(char *str, int i, int c);
int print_hexa_min(va_list ap, char *str, int i, int y);
int print_sci0(va_list ap, char *str, int i);
int e2_pres(int nbr, int i, char *str);
int print_sci(va_list ap, char *str, int i);

#endif /* MY_H_ */
