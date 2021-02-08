/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-kilian.mai
** File description:
** NetworkModule
*/

#include <ncurses.h>
#include "NetworkModule.hpp"

NetworkModule::NetworkModule()
{
    _isActive = true;
    _moduleName = "Network Module";
    _key = 'n';
    updateNetwork();
}

NetworkModule::~NetworkModule()
{
}

void NetworkModule::displaySFML(sf::RenderWindow *window)
{
    updateNetwork();
    std::ostringstream tmp;
    std::ostringstream tmp_second;
    std::ostringstream tmp_third;
    std::ostringstream tmp_fourth;
    tmp << _sentPackets << " (" << _sentBytes << " Bytes) ";
    tmp_second << _receivedPackets << " (" << _receivedBytes << " Bytes) ";
    tmp_third << _sentPacketsPerSecond << " (" << _sentBytesPerSecond << " Bytes) ";
    tmp_fourth << _receivedPacketsPerSecond << " (" << _receivedBytesPerSecond << " Bytes) ";
    std::string string(tmp.str());
    std::string string_second(tmp_second.str());
    std::string string_third(tmp_third.str());
    std::string string_fourth(tmp_fourth.str());
    displayShape(window, 990, 600, 600, 250);
    displayTitle(window, "Network Module :", 1015, 550, 25);
    displayTitle(window, "Packages sent :", 1015, 630, 22);
    displayText(window, string, 1280, 630, 21);
    displayTitle(window, "Packages received :", 1015, 730, 22);
    displayText(window, string_second, 1330, 730, 21);
    displayTitle(window, "\\(per second) :", 1015, 680, 22);
    displayText(window, string_third, 1260, 680, 21);
    displayTitle(window, "\\(per second) :", 1015, 780, 22);
    displayText(window, string_fourth, 1260, 780, 21);
}

void NetworkModule::updateNetwork()
{
    std::ifstream file("/proc/net/dev");
    std::string line;
    std::string uselessString;
    int rp;
    int sp;
    int rb;
    int sb;

    size_t uselessInt;

    if (file.good()) {
        for (int i = 0; i < 3; ++i)
            std::getline(file, line);
        std::getline(file, line);
        std::istringstream os(line);
        os >> uselessString >> _receivedBytes >> _receivedPackets >> uselessInt >> uselessInt >> uselessInt >> uselessInt >> uselessInt >> uselessInt >> _sentBytes >> _sentPackets;
        file.close();
    }
    usleep(200000);
    std::ifstream file2("/proc/net/dev");
    if (file2.good()) {
        for (int i = 0; i < 3; ++i)
            std::getline(file2, line);
        std::getline(file2, line);
        std::istringstream os(line);
        os >> uselessString >> rb >> rp >> uselessInt >> uselessInt >> uselessInt >> uselessInt >> uselessInt >> uselessInt >> sb >> sp;
        file.close();
    }
    _receivedPacketsPerSecond = (rp - _receivedPackets) * 5;
    _receivedBytesPerSecond = (rb - _receivedBytes) * 5;
    _sentPacketsPerSecond = (sp - _sentPackets) * 5;
    _sentBytesPerSecond = (sb - _sentBytes) * 5;
}

void NetworkModule::displayNcurses()
{
    updateNetwork();
	attron(COLOR_PAIR(1));
    printw("\tNetwork\n\n");
    printw("\tPackages sent: ");
    attron(COLOR_PAIR(2));
    printw("%d (%dKB)\t", _sentPackets, (_sentBytes / 1024));
	attron(COLOR_PAIR(1));
    printw("\tPackages received: ");
    attron(COLOR_PAIR(2));
    printw("%d (%dMB)\n", _receivedPackets, (_receivedBytes / 1048576));
	attron(COLOR_PAIR(1));
    printw("\t\\(per second): ");
    attron(COLOR_PAIR(2));
    printw("%d (%d Bytes)\t", _sentPacketsPerSecond, _sentBytesPerSecond);
	attron(COLOR_PAIR(1));
    printw("\t\\(per second): ");
    attron(COLOR_PAIR(2));
    printw("%d (%d Bytes)\n", _receivedPacketsPerSecond,
        _receivedBytesPerSecond);
}

int NetworkModule::getReceivedPackets() const { return (_receivedPackets); }

int NetworkModule::getReceivedBytes() const { return (_receivedBytes); }

int NetworkModule::getSentPackets() const { return (_sentPackets); }

int NetworkModule::getSentBytes() const { return (_sentBytes); }

int NetworkModule::getReceivedPacketsPerSecond() const { return (_receivedPacketsPerSecond); }

int NetworkModule::getReceivedBytesPerSecond() const { return (_receivedBytesPerSecond); }

int NetworkModule::getSentPacketsPerSecond() const { return (_sentPacketsPerSecond); }

int NetworkModule::getSentBytesPerSecond() const { return (_sentBytesPerSecond); }

void NetworkModule::setStatus() { _isActive = !_isActive; }

bool NetworkModule::getStatus() const { return (_isActive); }

char NetworkModule::getKey() const { return (_key); }
