##
## EPITECH PROJECT, 2019
## Day10
## File description:
##
##

SRC     =   my_showmem.c    \
            my_str_isupper.c        \
            my_compute_power_rec.c  \
            my_showstr.c    \
            my_strlen.c     \
            my_compute_square_root.c        \
            my_sort_int_array.c     \
            my_strlowcase.c \
            my_find_prime_sup.c     \
            my_strcapitalize.c      \
            my_strncat.c    \
            my_getnbr.c     \
            my_strcat.c     \
            my_strncmp.c    \
            my_isneg.c      \
            my_strcmp.c     \
            my_strncpy.c    \
            my_is_prime.c   \
            my_strcpy.c     \
            my_strstr.c     \
            my_putchar.c    \
            my_str_isalpha.c        \
            my_strupcase.c  \
            my_put_nbr.c    \
            my_str_islower.c        \
            my_swap.c       \
            my_putstr.c     \
            my_str_isnum.c  \
            my_revstr.c     \
            my_str_isprintable.c

NAME	=	libmy.a

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)
	rm -rf ../$(NAME)

re: fclean all