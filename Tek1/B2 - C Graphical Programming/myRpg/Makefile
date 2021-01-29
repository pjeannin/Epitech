##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## MY_RPG
##

SRC		=	src/menu/menu.c						\
			src/menu/parallax.c					\
			src/menu/init_par.c					\
			src/menu/init_but.c					\
			src/menu/init_echap.c				\
			src/menu/init_inventory.c			\
			src/menu/draw_menu.c				\
			src/menu/end_event.c				\
			src/menu/end_menu.c					\
			src/menu/anim_echap.c				\
			src/menu/draw_echap.c				\
			src/menu/check_button_end.c			\
			src/play/play_game.c				\
			src/play/init_end.c					\
			src/character/character.c			\
			src/character/stat.c				\
			src/character/check_key.c			\
			src/character/updates_levels.c		\
			src/map/init_map.c					\
			src/map/draw_map.c					\
			src/map/move_map.c					\
			src/objects/draw_objects.c			\
			src/objects/init_object_list.c		\
			src/objects/check_key_take_object.c	\
			src/objects/give_life_back.c		\
			src/quete/init_quete.c				\
			src/quete/display_quete.c			\
			src/quete/update_quete.c			\
			src/guardian/init_guardian.c		\
			src/guardian/draw_guardian.c		\
			src/guardian/move_guardian.c		\
			src/guardian/update_guardian_life.c	\
			src/fight/guardian_damage.c			\
			src/fight/player_damage.c			\
			src/particules/init_frame_buffer.c	\
			src/particules/draw_particules.c	\
			src/particules/create_particule.c	\
			src/particules/updates_particules.c	\
			src/particules/particlues_utils.c	\
			src/boss/init_boss.c				\
			src/boss/boss_damage.c				\
			src/boss/death_boss.c				\
			lib/char_from_int.c					\
			src/free/free_rpg.c					\
			src/set_text.c						\
			src/rpg.c							\
			src/main.c

OBJ		=	$(SRC:.c=.o)

NAME	=	my_rpg

CFLAGS	=	-L ./lib/my/		\
			-I include			\
			-lmy				\
			-lcsfml-graphics	\
			-lcsfml-system		\
			-lcsfml-window		\
			-lcsfml-audio

.PHONY: lib

all: $(NAME)

$(NAME): lib $(OBJ)
	gcc -o $(NAME) $(SRC) $(CFLAGS)

debug: CFLAGS += -g
debug: all

lib:
	make -sC ./lib/my/

clean:
	make fclean -sC ./lib/my/
	rm -f $(OBJ)
	rm -f $(NAME)

re:	clean all