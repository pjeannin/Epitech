/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-pierre.jeannin
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include "../../interfaces/IGraphics.hpp"
#include <ncurses.h>
#include <curses.h>
#include <unistd.h>
#include <vector>
#include <math.h>

class GraphicNcurses: public IGraphic {
    public:
        GraphicNcurses();
        ~GraphicNcurses();
        void drawRect(const Rect &rect);
        void rectangle(int y1, int x1, int y2, int x2);
        void drawCircle(const Circle &circle);
        void drawSprite(const Sprite &sprite);
        void drawText(const Text &text);
        void refreshScreen();
        void clearScreen();
        bool isOperational();
        Event handleEvent();
    protected:
    private:
        int RGB(int r, int g, int b);
        int key;

};

#endif