/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-kilian.mai
** File description:
** ncursesDisplay
*/

#include <ncurses.h>
#include "ncursesDisplay.hpp"
#include "UserModule.hpp"
#include "TimeModule.hpp"
#include "OSModule.hpp"
#include "RamModule.hpp"
#include "CpuModule.hpp"
#include "NetworkModule.hpp"

ncursesDisplay::ncursesDisplay() : IMonitorDisplay()
{
    ncursesDisplay::_modules.push_back(new UserModule);
    ncursesDisplay::_modules.push_back(new TimeModule);
    ncursesDisplay::_modules.push_back(new OSModule);
    ncursesDisplay::_modules.push_back(new RamModule);
    ncursesDisplay::_modules.push_back(new CpuModule);
    ncursesDisplay::_modules.push_back(new NetworkModule);
}

void ncursesDisplay::changeModuleStatus(char key)
{
    IMonitorModule *tmp = _modules[0];

    for (auto i = _modules.begin(); i != _modules.end(); i++) {
        tmp = *i;
        if (tmp->getKey() == key || tmp->getKey() == (key - 32)) {
            tmp->setStatus();
            break;
        }
    }
}

char ncursesDisplay::checkKeyPressed(char c)
{
    if (c == 'q')
        return (c);
    else
        changeModuleStatus(c);
    return ('z');
}

void ncursesDisplay::displayModules()
{
    IMonitorModule *tmp = _modules[0];

    initscr();
    timeout(500);
    start_color();
    noecho();
    curs_set(FALSE);
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    init_pair(6, COLOR_BLACK, COLOR_RED);
    init_pair(7, COLOR_BLACK, COLOR_GREEN);
    init_pair(8, COLOR_BLACK, COLOR_YELLOW);
    while (1) {
        clear();
        printw("\n\n");
        for (auto i = _modules.begin(); i != _modules.end(); i++) {
            tmp = *i;
            if (tmp->getStatus() == true) {
                tmp->displayNcurses();
                attron(COLOR_PAIR(1));
                printw("\n\t\t\t\t_____________________________________\n\n");
            }
        }
        refresh();
        if (checkKeyPressed(getch()) == 'q')
            break;
    }
    endwin();
}
