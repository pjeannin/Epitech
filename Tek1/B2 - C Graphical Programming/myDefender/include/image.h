/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** image
*/

#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef IMAGE_H_
#define IMAGE_H_

typedef struct picture_s {
    char *name;
    sfClock *clock;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect *size;
} picture_t;

typedef struct sprite_list_s {
    picture_t *sprite;
    struct sprite_list_s *next;
    struct sprite_list_s *prev;
} sprite_list_t;

sprite_list_t *move_end(sprite_list_t *list);
sprite_list_t *move_beginning(sprite_list_t *list);
picture_t *init_image(char *filepath, int size, int x, int y);
sprite_list_t *init_sprite_list(void);
sprite_list_t *add_sprite_to_sprite_list(sprite_list_t *sprite_list, char *filepath, int i, int j);
void free_picture(picture_t *pic);

#endif /* !IMAGE_H_ */
