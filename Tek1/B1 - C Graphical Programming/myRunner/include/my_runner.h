/*
** EPITECH PROJECT, 2019
** my_runner.h
** File description:
** my_runner
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Window/Event.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Audio.h>
#include <SFML/Window/Keyboard.h>

#ifndef MY_RUNNER_H_
#define MY_RUNNER_H_

typedef struct picture_s {
    char *name;
    sfClock *clock;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect *size;
} picture_t;

typedef struct background_s {
    picture_t *background;
    picture_t *middlebis;
    picture_t *middlebisbis;
    picture_t *middle;
    picture_t *foreground;
    picture_t *foregroundbis;
    picture_t *foregroundbisbis;
    picture_t *fg;
    picture_t *fgbis;
    picture_t *sol;
    picture_t *solbis;
    picture_t *montain;
    picture_t *big_montain;
    picture_t *mmontain;
    picture_t *bbig_montain;
    picture_t *mmmontain;
    picture_t *bbbig_montain;
} background_t;

typedef struct map_list_s {
    picture_t *element;
    struct map_list_s *next;
    struct map_list_s *prev;
} map_list_t;

typedef struct gamt_s {
    background_t *background;
    float timer;
    picture_t *mario;
    int up;
    int sol;
    int score;
    char *map_name;
    int end;
    map_list_t *map;
} game_t;

background_t *init_background(void);
void display_background(background_t *back, sfRenderWindow *window);
void move_background(game_t *game_struct);
void free_background(background_t *back);
char *char_from_int(int nbr);
int check_col(map_list_t *map, picture_t *mario);
int check_end(game_t *game, int *screen);
sfRenderWindow *creat_window(unsigned int width, unsigned int height,
    char *window_name);
int find_sol(game_t *game);
void event_game_over(sfRenderWindow *window, sfEvent event, int *screen,
game_t *game_struct);
void game_over(sfRenderWindow *window, sfEvent event, int *screen,
game_t *game_struct);
void event_game(sfRenderWindow *window, sfEvent event, int *screen,
game_t *game_struct);
void game(sfRenderWindow *window, sfEvent event, int *screen,
game_t *game_struct);
void free_image(picture_t *image);
void __init_image(picture_t *image, int size, char *filepath, sfIntRect *area);
picture_t *init_image(char *filepath, int size, int x, int y);
game_t *init_game_struct(void);
void jump(game_t *game);
void event_choose_level(sfRenderWindow *window, sfEvent event, int *screen,
game_t *game_struct);
void choose_level(sfRenderWindow *window, sfEvent event, int *screen,
game_t *game_struct);
void move_map(game_t *game);
void disp_map(sfRenderWindow *window, map_list_t *map);
void free_map(game_t *game);
void event_menu(sfRenderWindow *window, sfEvent event, int *screen);
void menu(sfRenderWindow *window, sfEvent event, int *screen);
map_list_t *move_beginning(map_list_t *list);
void move(picture_t *picture, float speed);
void run(game_t *game_struct);
int neg(int *pi, int count_neg, char const *str);
int my_getnbr(char const *str);
void str_rev(char *str);
int str_len(char const *str);
void exit_readmap(int fd, char *str);
void read_line(char *buf, int fd);
char **read_map(char *filepath, int *nb_line, int *nb_col);
void event_rules(sfRenderWindow *window, sfEvent event, int *screen);
void rules(sfRenderWindow *window, sfEvent event, int *screen);
map_list_t *initlist(void);
map_list_t *add_elem(int y, int x, map_list_t *list);
map_list_t *init_map_list(char *filepath, game_t *game);
sfText *set_text(char *str, int size, int x, int y);
void win(sfRenderWindow *window, sfEvent event, int *screen,
game_t *game_struct);
void screen_choice(sfRenderWindow *window, sfEvent event, int *screen,
game_t *game_struct);

#endif /* !MY_RUNNER_H_ */
