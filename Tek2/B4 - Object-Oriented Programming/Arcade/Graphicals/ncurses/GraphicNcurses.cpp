/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-pierre.jeannin
** File description:
** GraphicNcurses
*/

#include "GraphicNcurses.hpp"

GraphicNcurses::GraphicNcurses()
{
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, true);
    start_color();
    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, RGB(0, 0, 0), RGB(0, 0, 0));
    init_pair(2, RGB(255, 0, 0), RGB(255, 0, 0));
    init_pair(3, RGB(0, 255, 0), RGB(0, 255, 0));
    init_pair(4, RGB(255, 255, 0), RGB(255, 255, 0));
    init_pair(5, RGB(0, 0, 255), RGB(0, 0, 255));
    init_pair(6, RGB(255, 0, 255), RGB(255, 0, 255));
    init_pair(7, RGB(0, 255, 255), RGB(0, 255, 255));
    init_pair(8, RGB(255, 255, 255), RGB(255, 255, 255));
}

GraphicNcurses::~GraphicNcurses()
{
    endwin();
}

void GraphicNcurses::refreshScreen()
{
    wrefresh(stdscr);
}

void GraphicNcurses::clearScreen()
{
    usleep(5000);
    wclear(stdscr);
}

void GraphicNcurses::drawRect(const Rect &rect)
{
    int max_y;
    int max_x;

    getmaxyx(stdscr, max_y, max_x);
    Size size {((float)(int)((float)rect.size.y / 100 * max_y)) == 0 ? 1 : ((float)(int)((float)rect.size.y / 100 * max_y)), ((float)(int)((float)rect.size.x / 100 * max_x)) == 0 ? 1 : ((float)(int)((float)rect.size.x / 100 * max_x))};
    Position position {((float)(int)((float)rect.pos.y / 100 * max_y)) == 0 ? 1 : ((float)(int)((float)rect.pos.y / 100 * max_y)), ((float)(int)((float)rect.pos.x / 100 * max_x)) == 0 ? 1 : ((float)(int)((float)rect.pos.x / 100 * max_x))};
    attron(COLOR_PAIR(RGB(rect.color.red, rect.color.green, rect.color.blue) + 1));
    for (int i = 0; i < size.x; i++) {
        for (int j = 0; j < size.y; j++)
            mvaddch(i + position.x, j + position.y, 'o');
    }
}

void GraphicNcurses::drawSprite(const Sprite &sprite)
{
    (void)sprite.pos;
}

void GraphicNcurses::drawCircle(const Circle &circle)
{
    int maxX;
    int maxY;
    int size = circle.radius;

    init_pair(1, RGB(circle.color.red, circle.color.green, circle.color.blue), RGB(circle.color.red, circle.color.green, circle.color.blue));
    attron(COLOR_PAIR(1));
    getmaxyx(stdscr, maxY, maxX);
    for (int i = 0; i < maxX; i++) {
        for (int j = 0; j < maxY; j++) {
            if ((int)(pow(i - circle.pos.y, 2)) + (int)(pow(j - circle.pos.x, 2)) <= (int)(pow(size, 2)))
                mvaddch(i + circle.pos.y - size, j + circle.pos.y - size, 'o');
        }
    }
}

int GraphicNcurses::RGB(int r, int g, int b)
{
    int res = 0;
    int res_temp = 1000;
    int temp = 0;
    int color[][3] = {{0, 0, 0}, {255, 0, 0}, {0, 255, 0}, {255, 255, 0}, {0, 0, 255}, {255, 0, 255}, {0, 255, 255}, {255, 255, 255}};

    for (int i = 0; i < 8; i++) {
        temp = 0;
        temp += abs(r - color[i][0]);
        temp += abs(g - color[i][1]);
        temp += abs(b - color[i][2]);
        if (temp < res_temp) {
            res_temp = temp;
            res = i;
        }
    }
    return (res);
}

void GraphicNcurses::drawText(const Text &text)
{
    int max_y;
    int max_x;

    getmaxyx(stdscr, max_y, max_x);
    init_pair(9, RGB(text.color.red, text.color.green, text.color.blue), COLOR_BLACK);
    attron(COLOR_PAIR(9));
    mvprintw(((int)((float)text.pos.y / 100 * max_y)) == 0 ? 1 : ((int)((float)text.pos.y / 100 * max_y)), ((int)((float)text.pos.x / 100 * max_x)) == 0 ? 1 : ((int)((float)text.pos.x / 100 * max_x)), text.getText().c_str());
}

bool GraphicNcurses::isOperational()
{
    if (!has_colors())
        return (false);
    return (true);
}

Event GraphicNcurses::handleEvent()
{
    switch (getch()) {
        case KEY_UP:
            return Event::up;
            break;
        case KEY_DOWN:
            return Event::down;
            break;
        case KEY_LEFT:
            return Event::left;
            break;
        case KEY_RIGHT:
            return Event::right;
            break;
        case 27:
            return Event::menu;
            break;
        case 10:
            return Event::enter;
            break;
        case 'c':
            return Event::prev_game;
            break;
        case 'v':
            return Event::next_game;
            break;
        case 'w':
            return Event::prev_graphic;
            break;
        case 'x':
            return Event::next_graphic;
            break;
        case 'r':
            return Event::restart;
            break;
        default:
            return Event::unknown;
            break;
    }
}

extern "C"
{
    GraphicNcurses *entry()
    {
        return new GraphicNcurses;
    }
}