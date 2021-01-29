/*
** EPITECH PROJECT, 2020
** button.h
** File description:
** inculude for button in CSFML
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
#include <stdlib.h>
#include "image.h"

#ifndef BUTTON_H_
#define BUTTON_H_

typedef struct button_s {
    sfRectangleShape *button;
    sfVector2f size;
    sfVector2f position;
    sfText *text;
} button_t;

typedef struct button_sprite_s {
    picture_t *button;
    sfVector2f size;
    sfVector2f position;
    sfText *text;
} button_sprite_t;

typedef struct button_list_s {
    struct button_s *exit_button;
    sfText *exit_text;
    struct button_s *play_button;
    sfText *play_text;
    struct button_s *rules_button;
    sfText *rules_text;
    struct button_s *level1_button;
    sfText *level1_text;
    struct button_s *level2_button;
    sfText *level2_text;
    struct button_s *level3_button;
    sfText *level3_text;
    struct button_sprite_s *defense1;
    struct button_sprite_s *defense2;
    struct button_sprite_s *pause;
    struct button_s *menu_button;
    sfText *menu_text;
    struct button_s *play_again_button;
    sfText *play_again_text;
    struct button_s *resume_button;
    sfText *resume_text;
    struct button_s *restart_button;
    sfText *restart_text;
    struct button_s *main_menu_button;
    sfText *main_menu_text;
} button_list_t;

button_t *init_button(sfVector2f position, sfVector2f size, sfColor color);
void draw_button(button_t *button, sfRenderWindow *window);
int button_is_clic(sfEvent event, button_t *button);
int button_sprite_is_clic(sfEvent event, button_sprite_t *button);

#endif /* !BUTTON_H_ */