##
## EPITECH PROJECT, 2021
## B-OOP-400-STG-4-1-arcade-pierre.jeannin
## File description:
## Makefile
##

CXX		=	g++

NAME		=	../../lib/arcade_ncurses.so

RM		=	rm -rf

SRC		=	GraphicNcurses.cpp

CXXFLAGS	=	-Wall
CXXFLAGS	+=	-Wextra
CXXFLAGS	+=	-I include -I ../../inc
CXXFLAGS	+=	-fPIC

ifeq			($(DEBUG), yes)
CXXFLAGS	+=	-g
endif

LDFLAGS	+=	-L ./lib/ -shared
LDFLAGS	+=	-std=c++17 -lncurses

OBJ	=	$(SRC:.cpp=.o)

all:			$(NAME)

$(NAME):	$(OBJ)
		$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all