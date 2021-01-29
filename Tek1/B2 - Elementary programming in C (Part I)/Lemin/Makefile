##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	lib/my_strdup.c							\
		lib/is_in_str.c							\
		src/lemin.c								\
		src/connect_links.c						\
		src/create_link.c						\
		src/print_link.c						\
		src/print_data_of_connected_links.c		\
		src/print_my_graph_data.c				\
		src/error_handling/error_handling.c		\
		src/error_handling/input_is_wrong.c		\
		src/get_input.c							\
		src/init_input_list.c					\
		src/error_handling/check_first_line.c	\
		src/error_handling/find_start.c						\
		src/error_handling/check_end_start.c	\
		src/error_handling/check_pipes.c		\
		src/error_handling/find_pipe_start.c	\
		src/error_handling/check_line.c			\
		src/error_handling/remove_comments.c	\
		src/load_infos.c						\
		src/display_start_infos.c				\
		src/load_graph.c						\
		src/load_line.c							\
		src/init_cell_list.c					\
		src/transform_list_in_graph.c			\
		src/find_link.c							\
		src/resolver/ways.c						\
		main.c

NAME	=	lem_in

all:	$(NAME)

$(NAME):
	make -sC ./lib/my/
	gcc -o $(NAME) $(SRC) -L ./lib/my/ -I ./include/ -lmy -lm

clean:
	make fclean -sC ./lib/my/

fclean:	clean
	rm -f $(NAME)

re: fclean all

debug:
	make -sC ./lib/my/
	gcc -o $(NAME) $(SRC) -L ./lib/my/ -I ./include/ -lmy -g
