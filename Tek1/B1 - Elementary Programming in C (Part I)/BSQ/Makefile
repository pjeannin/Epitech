##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

DEPS	=	include/

SRC	=	lib/my_getnbr.c	\
		lib/put.c	\
		lib/str_dup.c	\
		lib/str_len.c	\
		src/read_map.c	\
		src/fill_find_square.c	\
		src/error_handling.c	\
		src/error_message.c	\
		src/set_st_square.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

%.o:	%.c
	$(CC) -c -o $@ $< -I$(DEPS)

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -I${DEPS}

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all
