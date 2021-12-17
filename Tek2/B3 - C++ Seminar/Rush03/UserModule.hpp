/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-kilian.mai
** File description:
** UserModule
*/

#ifndef USERMODULE_HPP_
#define USERMODULE_HPP_

#include <unistd.h>
#include <string.h>
#include "IMonitorModule.hpp"
#include "SFML/Affichage/print.hpp"

class UserModule : public IMonitorModule {
    public:
        UserModule();
        ~UserModule() = default;
        const std::string &getHostName() const;
        const std::string &getUserName() const;
        bool getStatus() const;
        char getKey() const;
        void setStatus();
        void displayNcurses();
        void displaySFML(sf::RenderWindow *window);

    protected:
    private:
        std::string _hostName;
        std::string _userName;
        char _key;
        bool _isActiv;
};

#endif /* !USERMODULE_HPP_ */
