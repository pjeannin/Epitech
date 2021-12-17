##
## EPITECH PROJECT, 2021
## B-OOP-400-STG-4-1-tekspice-pierre.jeannin
## File description:
## Makefile
##

CXX = g++

CFLAGS = #options de compilation

LDFLAGS = #options de link

SRC = 	main.cpp	\
		Hotline.cpp

OBJ = $(SRC:.cpp=.o)

OUTPUT = 203hotline #nom de l'exectutable

all: $(OBJ)
	@$(CXX) $(LDFLAGS) -o $(OUTPUT) $^
	@echo "Compilation ended"

$(OBJ): %.o: %.cpp
	@$(CXX) $(CFLAGS) -c $< -o $@
	@echo "$@ Creation"

clean:
	@rm -rf *.o
	@echo "Clean"

fclean: clean
	@rm -rf $(OUTPUT)
	@echo "Fclean"

re: fclean all