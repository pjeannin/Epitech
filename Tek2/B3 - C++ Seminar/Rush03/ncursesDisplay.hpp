/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-kilian.mai
** File description:
** ncursesDisplay
*/

#ifndef NCURSESDISPLAY_HPP_
    #define NCURSESDISPLAY_HPP_

#include <vector>
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

class ncursesDisplay : public IMonitorDisplay
{
    public:
        ncursesDisplay();
        void displayModules();

        char checkKeyPressed(char c);
        void changeModuleStatus(char key);

    private:
        std::vector<IMonitorModule *> _modules;

};

#endif
