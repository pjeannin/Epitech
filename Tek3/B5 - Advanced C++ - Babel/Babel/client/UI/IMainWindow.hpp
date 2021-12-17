/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** IMainWindow.hpp
*/

#ifndef IMAINWINDOW_H
#define IMAINWINDOW_H

#include <string>

class IMainWindow {
    public:
        virtual ~IMainWindow() = default;

        virtual void addContactToList(std::string &name) = 0;
        virtual void addMessageToCurrentList(std::string nv_message, std::string sender) = 0;
        virtual void clearMessagesList() = 0;
};

#endif // IMAINWINDOW_H