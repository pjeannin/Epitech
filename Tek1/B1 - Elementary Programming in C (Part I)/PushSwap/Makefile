##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

DEPS	=	include/

SRC	=	lib/my_getnbr.c									\
		lib/put.c										\
		lib/linked_list_lib/utils_linked_list.c			\
		lib/linked_list_lib/utils_linked_list_bis.c		\
		lib/linked_list_lib/utils_linked_list_bis_bis.c	\
		src/error_handling.c							\
		src/sort_utils.c								\
		src/sort.c										\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	push_swap

%.o:	%.c
	$(CC) -c -o $@ $< -I$(DEPS)

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -I${DEPS}

debug:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -I${DEPS} -g

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

deb:	fclean debug

re: 	fclean all
