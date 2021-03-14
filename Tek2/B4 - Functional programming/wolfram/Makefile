##
## EPITECH PROJECT, 2021
## B-FUN-400-STG-4-1-wolfram-pierre.jeannin
## File description:
## Makefile
##

BINARY_PATH 	:=	$(shell stack path --local-install-root)
NAME 			= 	wolfram

all:
	stack build
	cp "$(BINARY_PATH)/bin/$(NAME)-exe" ./$(NAME)

clean:
	stack clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean r