##
## EPITECH PROJECT, 2019
## makefile
## File description:
## make files
##

#############   MAKEFILES NAMES  (my in last) #################

_MAKEFILES	:=	asm	\
				corewar	\

##############   COLORS             ###########################
WHITE	:=	\033[0;0m
TEXTCOLOR	:=	\033[01;38;5;11m
COLOR	:=	\033[01;38;5;31m
VALGRIND_COLOR	:=	\033[01;38;5;1m

###################################################################################
##############   DO NOT TOUCH       ###############################################
###################################################################################

all:
	@for makefile in $(_MAKEFILES); do	\
	$(MAKE) --no-print-directory -C $$makefile;	\
	echo -e "$(TEXTCOLOR)$$makefile as been succesfully [compiled]$(WHITE)";	\
	done

clean:
	@for makefile in $(_MAKEFILES); do	\
	$(MAKE) --no-print-directory -C $$makefile clean;	\
	echo -e "$(TEXTCOLOR)$$makefile as been succesfully [cleaned]$(WHITE)";	\
	done

fclean:
	@for makefile in $(_MAKEFILES); do	\
	$(MAKE) --no-print-directory -C $$makefile fclean;	\
	echo -e "$(TEXTCOLOR)$$makefile as been succesfully [fcleaned]$(WHITE)";	\
	done

re:	fclean all

.PHONY:	$(NAME) clean fclean re run debug
