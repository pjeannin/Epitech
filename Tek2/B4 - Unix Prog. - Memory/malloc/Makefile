##
## EPITECH PROJECT, 2021
## B-PSU-400-STG-4-1-malloc-pierre.jeannin
## File description:
## Makefile
##

SRC		=	src/malloc.c				\
			src/calloc.c				\
			src/utils_block.c			\
			src/create_delete_block.c	\
			src/find_power_of_two.c

CFLAGS	=	-Wall -Wextra -Wno-deprecated -g3 -fPIC

OBJS	=	$(SRC:.c=.o)

NAME	=	libmy_malloc.so

all:	$(NAME)

$(NAME): $(OBJS)
	@gcc -fPIC -shared -o $(NAME) $(OBJS) $(CFLAGS)
	@echo "Lib created"

clean:
	@rm -rf $(OBJS)
	@echo "clean success"

fclean:	clean
	@rm -f $(NAME)
	@echo "fclean success"

re:	fclean all
