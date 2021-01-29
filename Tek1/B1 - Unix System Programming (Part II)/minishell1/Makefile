##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

DEPS	=	include/

SRC	=	main.c					\
		src/minishell.c			\
		src/get_command.c		\
		src/exit_command.c		\
		src/my_getnbr.c			\
		src/env_command.c		\
		src/setenv_command.c	\
		src/unsetenv_command.c	\
		src/cd_command.c		\
		src/exe_command.c		\
		utils/put_nbr.c			\
		utils/transform_en.c	\
		utils/move_beginning.c	\
		utils/move_end.c		\
		utils/free_list.c		\
		utils/count_spaces.c	\
		utils/comp_str.c		\
		utils/is_root.c			\
		utils/set.c				\
		utils/concat_str.c		\
		utils/find_val.c		\
		utils/list_len.c		\
		utils/list_to_tab.c		\
		utils/free_tab.c		\
		utils/clean_cmd.c		\
		utils/str_word_array.c	\
		utils/creat_tab.c		\
		utils/str.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

%.o:	%.c
	$(CC) -c -o $@ $< -I$(DEPS) 

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -I${DEPS}

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all