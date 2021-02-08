##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

DEPS	=	include/

SRC	=	main.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	my_cat

%.o:	%.c
	$(CC) -c -o $@ $< -I$(DEPS)

all:	$(OBJ)
	g++ -o $(NAME) $(OBJ) -I${DEPS} -Wall -Wextra -Werror

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all