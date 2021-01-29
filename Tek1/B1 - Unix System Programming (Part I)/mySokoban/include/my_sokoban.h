/*
** EPITECH PROJECT, 2019
** my_sokoban.h
** File description:
** my_sokoban
*/

#ifndef MY_SOKOBAN_H_
#define MY_SOKOBAN_H_

#define LARGE   "Need Larger Terminal"
#define RESTART "Press r to restart"
#define EXIT    "Press e to exit"
#define SPACE   "Press Space to select"

typedef struct map_s {
    char **map;
    char **initial_map;
    int posx;
    int posy;
    int init_posx;
    int init_posy;
    int nbr_line;
    int nbr_col;

} map_t;

int str_len(char *str);
char *char_from_int(int nbr);
void game(int *c, map_t *map, int *end, int *moves);
void end_game(map_t *map);
map_t *init_game(char *filepath);
void end_game_bonus(map_t *map);
map_t *init_game_bonus(char *filepath);
int my_sokoban_bonus(char *filepath);
void switch_choice(char *exit, int *highlight);
void choice_screen(int *highlight, char *exit, char **choices);
char end_screen(char exit, int move);
void gmae_screen(char **choices, int highlight, char exit, int move);
void restart(map_t *map);
char **readmap(char *filepath, map_t *maps);
char chek_nomove(map_t *map);
void move_left(map_t *map);
void move_right(map_t *map);
void move_up(map_t *map);
void move_down(map_t *map);
int usage(int ac, char **av);
int error_handling(int ac, char **av);
void move_P(map_t *map, int c, int *moves);
map_t *init_map(char *filepath);
char check_end(map_t *map, int *end);
void error_message(char *str);

#endif /* !MY_SOKOBAN_H_ */
