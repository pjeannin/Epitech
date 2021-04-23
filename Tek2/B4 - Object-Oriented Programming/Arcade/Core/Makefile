##
## EPITECH PROJECT, 2021
## B-OOP-400-STG-4-1-arcade-pierre.jeannin
## File description:
## Makefile
##

CXX = g++

CFLAGS = -Wall -Wextra -Wreorder -std=c++17  -ldl  -g -lstdc++fs#options de compilation

LDFLAGS = -ldl #options de link

SRC = 	Core.cpp \
		main.cpp

OBJ = $(SRC:.cpp=.o)

OUTPUT = arcade #nom de l'exectutable

all: $(OBJ)
	@$(CXX) -o $(OUTPUT) $^ $(LDFLAGS)
	mv arcade ..
	@echo "Compilation ended"

$(OBJ): %.o: %.cpp
	@$(CXX) $(CFLAGS) -c $< -o $@ -fconcepts
	@echo "$@ Creation"

clean:
	@rm -rf *.o
	@echo "Core Clean"

fclean: clean
	@rm -rf ../arcade
	@echo "Core Fclean"

re: fclean all