##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

DEPS	=	include/

SRC	=	main.c				\
		src/str_len.c		\
		src/list.c			\
		src/time.c			\
		src/my_getnbr.c		\
		src/sort.c			\
		src/swap_node.c		\
		src/comp_str.c		\
		src/disp.c			\
		src/disp_bis.c		\
		src/dis_all.c		\
		src/check_flags.c	\
		src/char_from_int.c	\
		src/find_longer.c	\
		src/my_ls.c			\
		src/disp_R.c		\
		src/dis_all_f.c		\
		src/dis_end.c		\
		src/fill_list.c		\
		src/concat_str.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

%.o:	%.c
	$(CC) -c -o $@ $< -I$(DEPS) 

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -I${DEPS}

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all