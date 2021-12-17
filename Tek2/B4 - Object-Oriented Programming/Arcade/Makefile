##
## EPITECH PROJECT, 2021
## B-OOP-400-STG-4-1-arcade-pierre.jeannin
## File description:
## Makefile
##

all: core games graphicals

core:
	@echo "Core compilation"
	@cd Core && $(MAKE)

games:
	@echo "Games compilation"
	@cd Games && $(MAKE)

graphicals:
	@echo "Graphicals compilation"
	@cd Graphicals && $(MAKE)

clean:
	@cd Core && $(MAKE) clean
	@cd Games && $(MAKE) clean
	@cd Graphicals && $(MAKE) clean

fclean: clean
	@rm -f arcade
	@rm -f lib/*.so

re: fclean all

.PHONY: all core games graphicals clean fclean