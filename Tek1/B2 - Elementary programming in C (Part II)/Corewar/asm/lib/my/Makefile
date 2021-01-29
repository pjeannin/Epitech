##
## EPITECH PROJECT, 2019
## makefile
## File description:
## make files
##

SRC	:=	my_putchar.c		\
		my_putstr.c			\
		my_strlen.c			\
		my_str_isnum.c		\
		my_calloc.c			\
		my_strcomp.c		\
		str_compare.c		\
		my_strdup.c			\
		parser.c			\
		my_glue_sep.c		\
		my_contains.c		\
		my_str_isalpha.c	\
		my_str_isfloat.c	\
		my_strcat.c			\
		my_printf.c			\
		freer.c				\
		my_char2len.c		\
		my_char2dup.c		\
		read_file.c			\
		my_slice.c			\
		my_atoi.c			\
		my_atof.c			\
		my_strfind.c		\
		my_revstr.c			\
		my_swap.c			\
		square.c			\
		find_word.c			\
		my_error.c			\
		my_free.c			\
		my_malloc.c			\
		string_format.c		\

CFLAGS	+=	-Wall -Werror

OBJ	:=	$(SRC:.c=.o)

NAME	:=	$(addprefix lib, $(addsuffix .a, $(notdir $(CURDIR))))

COLOR	:=	\033[01;38;5;201m

WHITE	:=	\033[0;0m

CLEAR	:=	\033[2K

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@mv $(NAME) ../
	@echo -e "$(CLEAR)$(NAME) : $(COLOR)OK$(WHITE)"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS);
	@echo -ne "$(CLEAR)Compiled $< : $(COLOR)OK$(WHITE)\r"

clean:
	@rm -f *.o

fclean: clean
	@rm -f ../$(NAME)

re:	fclean all
