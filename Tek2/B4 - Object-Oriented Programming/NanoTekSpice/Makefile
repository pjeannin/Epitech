##
## EPITECH PROJECT, 2021
## B-OOP-400-STG-4-1-tekspice-pierre.jeannin
## File description:
## Makefile
##

CXX = g++

CFLAGS = #options de compilation

LDFLAGS = #options de link

SRC = 	main.cpp						\
		src/Pins.cpp					\
		src/Handler.cpp					\
		src/Minishell.cpp				\
		src/Error.cpp					\
		src/Gates.cpp					\
		src/Create.cpp					\
		src/parser/Parser.cpp			\
		src/component/AComponent.cpp	\
		src/component/Clock.cpp			\
		src/component/Component2716.cpp	\
		src/component/Component4001.cpp	\
		src/component/Component4008.cpp	\
		src/component/Component4011.cpp	\
		src/component/Component4013.cpp	\
		src/component/Component4017.cpp	\
		src/component/Component4030.cpp	\
		src/component/Component4040.cpp	\
		src/component/Component4069.cpp	\
		src/component/Component4071.cpp	\
		src/component/Component4081.cpp	\
		src/component/Component4094.cpp	\
		src/component/Component4512.cpp	\
		src/component/Component4514.cpp	\
		src/component/Component4801.cpp	\
		src/component/False.cpp			\
		src/component/Input.cpp			\
		src/component/Output.cpp		\
		src/component/True.cpp			\
		src/circuit/Circuit.cpp

OBJ = $(SRC:.cpp=.o)

OUTPUT = nanotekspice #nom de l'exectutable

all: $(OBJ)
	@$(CXX) $(LDFLAGS) -o $(OUTPUT) $^
	@echo "Compilation ended"

$(OBJ): %.o: %.cpp
	@$(CXX) $(CFLAGS) -c $< -o $@
	@echo "$@ Creation"

clean:
	@rm -rf src/*.o
	@rm -rf src/circuit/*.o
	@rm -rf src/component/*.o
	@rm -rf src/parser/*.o
	@echo "Clean"

fclean: clean
	@rm -rf $(OUTPUT)
	@echo "Fclean"

re: fclean all