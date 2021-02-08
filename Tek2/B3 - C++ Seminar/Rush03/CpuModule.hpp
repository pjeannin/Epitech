/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-kilian.mai
** File description:
** CpuModule
*/

#ifndef CPUMODULE_HPP_
#define CPUMODULE_HPP_

#include <string>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <iostream>
#include <thread>
#include "IMonitorModule.hpp"
#include "SFML/GraphicalWindow.hpp"

class CpuModule : public IMonitorModule {
    public:
        CpuModule();
        ~CpuModule();
        const std::string &getCpuModel() const;
        float getFrequency() const;
        int getNbCpu() const;
        int getNbCore() const;
        bool getStatus() const;
        void setStatus();
        char getKey() const;
        const std::vector<double> getActivity() const;
        void updateCpuActivity();
        void updateFerquency();
        void displayNcurses();
        void displaySFML(sf::RenderWindow *window);

    protected:
    private:
        std::string _moduleName;
        float _frequency;
        int _nbCore;
        int _nbCpu;
        bool _isActiv;
        std::string _cpuModel;
        std::vector<double> _firstReadtotal;
        std::vector<double> _firstReadval;
        double _secondReadTotal;
        double _secondReadVal;
        std::vector<double> _cpuActivity;
        void readFirstTime(int nbLines);
        void readSecondTime(int atLine);
        char _key;
};

#endif /* !CPUMODULE_HPP_ */
