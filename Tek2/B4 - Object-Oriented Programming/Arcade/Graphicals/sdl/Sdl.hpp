/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-pierre.jeannin
** File description:
** Sdl
*/

#ifndef SDL_HPP_
#define SDL_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <math.h>
#include "../../Core/Error.hpp"
#include "../../interfaces/IGraphics.hpp"

#define WINDOW_WIDTH    1920
#define WINDOW_HEIGHT   1080

class Sdl : public IGraphic {
    public:
        Sdl();
        ~Sdl();
        bool isOperational();
        Event handleEvent();
        bool isKeyPressed();

        void drawRect(const Rect &rect);
        void drawCircle(const Circle &circle);
        void drawSprite(const Sprite &sprite);
        void drawText(const Text &text);
        void refreshScreen();
        void clearScreen();

    protected:
    private:
        SDL_Window *_window;
        SDL_Renderer * _renderer;
        SDL_Event _events;
        Event _currentEvent;
        TTF_Font *_font;
};

#define DISTANCE(x1, y1, x2, y2) (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)))

#endif /* !SDL_HPP_ */
