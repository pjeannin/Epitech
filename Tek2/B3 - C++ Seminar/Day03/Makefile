##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	string_init.c		\
		string_destroy.c	\
		string_append.c		\
		string_assign.c		\
		string_at.c			\
		string_clear.c		\
		string_size.c		\
		string_compare.c	\
		string_copy.c		\
		string_str.c		\
		string_empty.c		\
		string_find.c		\
		string_insert.c		\
		string_to_int.c		\
		string_split.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libstring.a

NAMEH	=	string.h

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -c $(OBJ)
		ar rc $(NAME) *.o
		rm -f $(OBJ)

remove:
		rm $(NAME)

re:	remove all
