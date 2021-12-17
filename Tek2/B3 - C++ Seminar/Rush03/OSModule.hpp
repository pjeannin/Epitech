/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-kilian.mai
** File description:
** OSModule
*/

#ifndef OSMODULE_HPP_
#define OSMODULE_HPP_

#include <sys/utsname.h>
#include <string.h>
#include "IMonitorModule.hpp"
#include "SFML/Affichage/print.hpp"

class OSModule : public IMonitorModule {
    public:
        OSModule();
        ~OSModule();
        const std::string &getOsName() const;
        const std::string &getKernelVesion() const;
        bool getStatus() const;
        char getKey() const;
        void setStatus();
        void displayNcurses();
        void displaySFML(sf::RenderWindow *window);

    protected:
    private:
        std::string _osName;
        std::string _kernelVersion;
        char _key;
        bool _isActiv;
};

#endif /* !OSMODULE_HPP_ */
