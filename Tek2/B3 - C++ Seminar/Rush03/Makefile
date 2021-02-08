##
## EPITECH PROJECT, 2021
## CPP_Pool
## File description:
## Makefile
##

CXXFLAGS =   -Werror -Wall -Wextra -g -lncurses -lsfml-graphics -lsfml-window -lsfml-system

SRC	=	main.cpp \
		OSModule.cpp \
		RamModule.cpp \
		TimeModule.cpp \
		UserModule.cpp \
		CpuModule.cpp	\
		ncursesDisplay.cpp	\
		NetworkModule.cpp	\
		SFML/GraphicalWindow.cpp \
		SFML/Affichage/print.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	MyGKrellm

all:	$(NAME)

$(NAME): $(OBJ)
	@g++ -o $(NAME) $(OBJ) $(CXXFLAGS)
	@rm -f $(OBJ)
	@echo -e "\033[01;38;5;10m================Compiling: Done\033[0;0m"

clean:
	@rm -f $(OBJ)
	@echo "============Deletion *o: Done"

fclean:	clean
	@rm -f $(NAME)
	@echo "============Deletion: Done"

re: fclean all
