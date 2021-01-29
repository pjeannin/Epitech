##
## EPITECH PROJECT, 2019
## makefile
## File description:
## make files
##

SRC	:=	count.c	\
		fillers.c	\
		getters.c	\
		regex.c	\
		regex_utils.c	\

CFLAGS	+=	-Wall -Werror

OBJ	:=	$(SRC:.c=.o)

NAME	:=	$(addprefix lib, $(addsuffix .a, $(notdir $(CURDIR))))

COLOR	:=	\033[01;38;5;100m

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
