##
## EPITECH PROJECT, 2019
## makefile
## File description:
## make files
##

################################   COMPILATION FILES   #######################

########## SRC ##############

FSRC	:=	src/
SRC	:=	main.c	\
		utils.c

########## ALL FILES ########

_FILES	:=	$(addprefix $(FSRC), $(SRC))		\

################################   OPTIONS/SETTINGS    #######################


########## BIN NAME #########
NAME	:=	corewar

########## RUN LINES ########
RUN_LINE	:=
VALGRIND_LINE	:=	-s --leak-check=full --track-origins=yes

#############   MAKEFILES NAMES  (my in last) #################

_MAKEFILES	:=	linked	\
				regex	\
				my	\


##############   LINKING FLAGS      ###########################
LIBS	:=	$(addprefix -l, $(_MAKEFILES))
LDFLAGS +=	-L./lib $(LIBS)


##############   COMPILATION FLAGS  ###########################
CFLAGS	+=	-Wall -I./include
DFLAGS	=	-g

##############   COLORS             ###########################
COLOR	:=	\033[01;38;5;31m
VALGRIND_COLOR	:=	\033[01;38;5;1m
RUN_COLOR	:=	\033[01;38;5;2m
WHITE	:=	\033[0;0m

###################################################################################
##############   DO NOT TOUCH       ###############################################
###################################################################################

OBJ	:=	$(_FILES:.c=.o)

CLEAR	:=	\033[2K

all:	$(NAME)

$(NAME):	$(OBJ)	make_all
	@$(CC)  $(OBJ) -o $(NAME) $(LDFLAGS)
	@echo -e "$(CLEAR)$(NAME) : $(COLOR)OK$(WHITE)"

%.o:	%.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo -ne "$(CLEAR)Compiled $< : $(COLOR)OK$(WHITE)\r"

clean:	make_clean
	@find ./$(FSRC) -name "*.o" -delete
	@rm -f vgcore*
	@echo -e "'.o' Deletion : \033[01;38;5;220mDONE$(WHITE)"

fclean: clean	make_fclean
	@rm -f $(NAME)
	@echo -e "'$(NAME)' deletion : \033[01;38;5;222mDONE$(WHITE)"

re:	fclean	all

debug:	$(CFLAGS) += $(DFLAGS)
debug:	all
	@echo -e "$(VALGRIND_COLOR)Valgrind Output :$(WHITE)"
	@valgrind $(VALGRIND_LINE) ./$(NAME) $(RUN_LINE)

run:	all
	@echo -e "$(RUN_COLOR)Run output :$(WHITE)"
	@./$(NAME) $(RUN_LINE)

make_all:
	@for makefile in $(_MAKEFILES); do	\
	$(MAKE) --no-print-directory -C lib/$$makefile;	\
	done

make_clean:
	@for makefile in $(_MAKEFILES); do	\
	$(MAKE) --no-print-directory -C lib/$$makefile clean;	\
	done

make_fclean:
	@for makefile in $(_MAKEFILES); do	\
	$(MAKE) --no-print-directory -C lib/$$makefile fclean;	\
	done

test: re
	@./lem_in < anthills/good/anthill_4


.PHONY:	$(NAME) clean fclean re run debug
