##
## EPITECH PROJECT, 2023
## makefile for libmy
## File description:
## makefile for libmy
##

SRC		=	my_printf.c	\
			m.c	\
			lib/my_hexa_len.c	\
			lib/my_int_len.c	\
			lib/my_octo_len.c	\
			lib/my_putchar.c	\
			lib/my_put_float_sciwriting.c	\
			lib/my_put_float_sciwriting_maj.c	\
			lib/my_put_float_wo_0.c	\
			lib/my_put_nbr.c	\
			lib/my_put_nbr_quote.c	\
			lib/my_putstr.c	\
			lib/my_put_unbr_quote.c	\
			lib/my_revstr.c	\
			lib/my_strlen.c	\
			lib/my_uint_len.c	\
			lib/pr_hexa_maj.c	\
			lib/pr_hexa_min.c	\
			lib/pr_octo.c	\
			flag_gestion/big_switch_case.c	\
			flag_gestion/printers/print_char.c	\
			flag_gestion/printers/print_float_sci_maj.c	\
			flag_gestion/printers/print_hexa_min.c	\
			flag_gestion/printers/print_hexa_maj.c	\
			flag_gestion/printers/print_int.c	\
			flag_gestion/printers/print_intd.c	\
			flag_gestion/printers/print_int_part2.c	\
			flag_gestion/printers/print_octogonal.c	\
			flag_gestion/printers/print_string.c	\
			flag_gestion/printers/print_uint.c	\
			flag_gestion/printers/print_uint_part2.c	\
			flag_gestion/printers/print_float_sci_min.c

OBJ	 	= 	$(SRC:.c=.o)

ROOTOBJ		=	my_hexa_len.o	\
			my_int_len.o	\
			my_octo_len.o	\
			my_putchar.o	\
			my_put_float_sciwriting.o	\
			my_put_float_sciwriting_maj.o	\
			my_put_float_wo_0.o	\
			my_put_nbr.o	\
			my_put_nbr_quote.o	\
			my_putstr.o	\
			my_put_unbr_quote.o	\
			my_revstr.o	\
			my_strlen.o	\
			my_uint_len.o	\
			pr_hexa_maj.o	\
			pr_hexa_min.o	\
			pr_octo.o	\
			big_switch_case.o	\
			print_char.o	\
			print_float_sci_maj.o	\
			print_hexa_min.o	\
			print_hexa_maj.o	\
			print_int.o	\
			print_intd.o	\
			print_int_part2.o	\
			print_octogonal.o	\
			print_string.o	\
			print_uint.o	\
			print_uint_part2.o	\
			prf.h.gch \
			main.o \
			print_float_sci_min.o	\

NAME 	= 	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -c $(SRC) prf.h
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(ROOTOBJ)

fclean: clean
	rm -f $(NAME)

re:		fclean all
