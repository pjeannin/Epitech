##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

DEPS	=	include/

FLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

SRC	=	src/lib/creat_window.c				\
		src/lib/init_button.c				\
		src/lib/sfvectorf.c					\
		src/lib/set_text.c					\
		src/lib/draw_button.c				\
		src/lib/clic_button.c				\
		src/lib/get_line.c					\
		src/lib/init_sprite_list.c			\
		src/lib/move_end.c					\
		src/lib/add_sprite_to_sprite_list.c	\
		src/lib/init_image.c				\
		src/lib/concat_str.c				\
		src/lib/str_len.c					\
		src/lib/char_from_int.c				\
		src/lib/my_revstr.c					\
		src/lib/free_picture.c				\
		src/init_defender.c					\
		src/load_map.c						\
		src/draw_exit_button.c				\
		src/scene_manager.c					\
		src/intro_scene.c					\
		src/main_menu_scene.c				\
		src/display_map.c					\
		src/init_ennemy_list.c				\
		src/create_ennemy.c					\
		src/find_initial_ennemy_pos.c		\
		src/move_ennemy.c					\
		src/event_intro_scene.c				\
		src/display_ennemy.c				\
		src/init_castle.c					\
		src/display_castle.c				\
		src/init_defense_list.c				\
		src/create_defense.c				\
		src/display_defense.c				\
		src/defense_attack.c				\
		src/ennemy_attack.c					\
		src/init_projectil_list.c			\
		src/display_projectil.c				\
		src/add_projectil.c					\
		src/move_projectil.c				\
		src/event_main_menu_scene.c			\
		src/init_button_list.c				\
		src/draw_main_menu_button.c			\
		src/game_scene.c					\
		src/rules_scene.c					\
		src/level_scene.c					\
		src/display_level_button.c			\
		src/event_level_scene.c				\
		src/game_scene_event.c				\
		src/create_empty_defense_list.c		\
		src/create_empty_ennemy_list.c		\
		src/display_game_button.c			\
		src/add_defense_animation.c			\
		src/add_defense.c					\
		src/add_ennemy.c					\
		src/display_player_money.c			\
		src/create_empty_projectil_list.c	\
		src/score_scene.c					\
		src/display_score_button.c			\
		src/event_score_scene.c				\
		src/display_score.c					\
		src/pause_scene.c					\
		src/event_pause_scene.c				\
		src/display_pause_scene_button.c	\
		src/find_x_and_y_move_ennemy.c		\
		src/delete_ennemy.c					\
		src/move_all_ennemy.c				\
		src/free_defender.c					\
		src/free_button_list.c				\
		src/free_utils.c					\
		src/free_utils_end.c				\
		src/free_construction_map.c			\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_defender

%.o:	%.c
	$(CC) -c -o $@ $< -I$(DEPS) 

all:	$(OBJ)
	gcc -g -o $(NAME) $(OBJ) -I${DEPS} $(FLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all