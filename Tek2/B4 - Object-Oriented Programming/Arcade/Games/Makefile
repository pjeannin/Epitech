##
## EPITECH PROJECT, 2021
## B-OOP-400-STG-4-1-arcade-pierre.jeannin
## File description:
## Makefile
##

all: pacman nibbler

pacman:
	@echo "Pacman Compilation"
	@cd Pacman && $(MAKE)

nibbler:
	@echo "Nibbler Compilation"
	@cd Nibbler && $(MAKE)

clean:
	@cd Nibbler && $(MAKE) clean
	@cd Pacman && $(MAKE) clean

fclean: clean
	@rm -f arcade_pacman.so arcade_nibbler.so

re: fclean all

.PHONY: re fclean clean pacman nibbler all