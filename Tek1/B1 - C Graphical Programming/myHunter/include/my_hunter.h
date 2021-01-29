/*
** EPITECH PROJECT, 2019
** my_hunter.c
** File description:
** my_hunter
*/

#ifndef MY_HUNTER_H_
#define MY_HUNTER_H_

typedef struct picture {
    char *name;
    sfClock *clock;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect *size;
} picture_t;

typedef struct s_framebuffer {
    unsigned char *pixels;
    unsigned int width;
    unsigned int height;
} framebuffer_t;

typedef struct game {
    sfClock *clock;
    sfMusic *shoot;
    sfMusic *back_music;
    char size;
    int level;
    int screen;
    int score;
    int high_score;
    int tmp;
} game_t;

typedef struct target {
    picture_t *bird;
    picture_t *devil_bird;
} target_t;

sfRenderWindow *creat_window(unsigned int width, unsigned int height,
    char *window_name);
void case_bigscreen(sfRenderWindow *bigscreen, sfEvent event, game_t *game,
    target_t *target);
void init_game_struct(game_t *game, char size);
void show_viewfinder(sfRenderWindow *window, sfEvent event);
char *char_from_int(int nbr);
void free_image(picture_t *image);
picture_t *init_image(char *filepath, int size, int x, int y);
void pos_bird(picture_t *bird, game_t *game);
void move(picture_t *image, game_t *game);
sfText *set_text(char *str, int size, int x, int y);
void event_big_screen(sfRenderWindow *window, sfEvent event);
void screen_zero_event(sfRenderWindow *window, sfEvent event, game_t *game);
void screen_one_event(sfRenderWindow *winfow, sfEvent event, game_t *game);
void screen_two_event(sfRenderWindow *window, sfEvent event, game_t *game,
    target_t *target);
void screen_three_event(sfRenderWindow *window, sfEvent event, game_t *game,
    picture_t *bird);
void screen_four_event(sfRenderWindow *window, sfEvent event, game_t *game,
    picture_t *bird);
void screen_zero(sfRenderWindow *window, sfEvent event, game_t *game,
    picture_t *bird);
void screen_one(sfRenderWindow *window, sfEvent event, game_t *game);
void screen_two(sfRenderWindow *window, sfEvent event, game_t *game,
    target_t *target);
void screen_three(sfRenderWindow *window, sfEvent event, game_t *game,
    picture_t *bird);
void screen_four(sfRenderWindow *window, sfEvent event, game_t *game,
    picture_t *bird);
void screen_five(sfRenderWindow *window, sfEvent event, game_t *game,
    picture_t *bird);
void show_viewfinder(sfRenderWindow *window, sfEvent event);
picture_t *init_image(char *filepath, int size, int x, int y);
void free_image(picture_t *image);
void free_game(game_t *game);
void move(picture_t *image, game_t *game);
void init_game(picture_t *bird, game_t *game, int level,
        sfRenderWindow *window);
target_t *init_target(void);
void free_target(target_t *target);
#endif
