##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Create a binary file and our famous library
##

SRC	=	unit_test/main.cpp  \

SRC1	=	santa/main.cpp  \

NAME	=	SantaKoalaus

NAME1	=	santa

all:	$(NAME)

$(NAME):
	g++ -g -o $(NAME) $(SRC) -Wall -Wextra -Werror
	g++ -g -o $(NAME1) $(SRC1) -Wall -Wextra -Werror

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)

unit:
	g++ ./unit_test/*.cpp ./class/*.cpp -o unit -Wall -Wextra -Werror

re:     fclean all
		rm $(NAME)
		make