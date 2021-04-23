##
## EPITECH PROJECT, 2021
## B-OOP-400-STG-4-1-arcade-pierre.jeannin
## File description:
## Makefile
##

all: sdl sfml ncurses

ncurses:
	@echo "ncurses Compilation"
	@cd ncurses && $(MAKE)

sdl:
	@echo "SDL2 Compilation"
	@cd sdl && $(MAKE)

sfml:
	@echo "SFML Compilation"
	@cd SFML && $(MAKE)

clean:
	@cd ncurses && $(MAKE) clean
	@cd sdl && $(MAKE) clean
	@cd SFML && $(MAKE) clean

fclean: clean
	@cd ncurses && $(MAKE) fclean
	@cd sdl && $(MAKE) fclean
	@cd SFML && $(MAKE) fclean

re: fclean all

.PHONY: re fclean clean sdl ncurses sfml all