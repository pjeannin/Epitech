/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-kilian.mai
** File description:
** NetworkModule
*/

#ifndef NETWORKMODULE_HPP_
#define NETWORKMODULE_HPP_

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include "IMonitorModule.hpp"
#include "SFML/GraphicalWindow.hpp"

class NetworkModule : public IMonitorModule {
    public:
        NetworkModule();
        virtual ~NetworkModule();
        void setStatus();
        bool getStatus() const;
        void updateNetwork();
        int getReceivedPackets() const;
        int getReceivedBytes() const;
        int getSentPackets() const;
        int getSentBytes() const;
        int getReceivedPacketsPerSecond() const;
        int getReceivedBytesPerSecond() const;
        int getSentPacketsPerSecond() const;
        int getSentBytesPerSecond() const;
        void displayNcurses();
        void displaySFML(sf::RenderWindow *window);
        char getKey() const;

    protected:
    private:
        int _receivedPackets;
        int _receivedBytes;
        int _sentPackets;
        int _sentBytes;
        int _receivedPacketsPerSecond;
        int _receivedBytesPerSecond;
        int _sentPacketsPerSecond;
        int _sentBytesPerSecond;
        bool _isActive;
        std::string _moduleName;
        char _key;
};

#endif