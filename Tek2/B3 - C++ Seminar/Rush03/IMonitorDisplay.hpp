/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-kilian.mai
** File description:
** IMonitorDisplay
*/

#ifndef IMONITORDISPLAY_HPP_
    #define IMONITORDISPLAY_HPP_

class IMonitorDisplay
{
    public:
        virtual void displayModules() = 0;
        virtual char checkKeyPressed(char c) = 0;
        virtual void changeModuleStatus(char key) = 0;
};

#endif
