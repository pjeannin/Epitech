/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-kilian.mai
** File description:
** CpuModule
*/

#include <ncurses.h>
#include <iomanip>
#include "CpuModule.hpp"

CpuModule::CpuModule()
{
    std::ifstream fileStream("/proc/cpuinfo");
    std::string currentLine;

    if (fileStream.is_open()) {
        while (fileStream.good()) {
            getline(fileStream, currentLine);
            if (currentLine.find("model name") == 0) {
                currentLine = currentLine.substr(13, currentLine.size() - 13);
                _cpuModel = currentLine;
            } else if (currentLine.find("cpu MHz") == 0) {
                currentLine = currentLine.substr(11, currentLine.size() - 11);
                _frequency = atof(currentLine.c_str());
                }
        }
        fileStream.close();
    }
    _nbCore = std::thread::hardware_concurrency();
    std::ifstream fileStream2;
    int i = -1;
    fileStream2.open("/proc/stat");
    if (fileStream2.is_open()) {
        while (getline(fileStream2, currentLine))
            if (currentLine.find("cpu") == 0)
                ++i;
        fileStream2.close();
    }
    _nbCpu = i;
    for (int j = 0; j < _nbCpu + 1; ++j) {
        _firstReadtotal.push_back(0);
        _firstReadval.push_back(0);
        _cpuActivity.push_back(0);
    }
    updateCpuActivity();
    _moduleName = "CPU Module";
    _isActiv = true;
    _key = 'c';
}

CpuModule::~CpuModule()
{
}

void CpuModule::updateFerquency()
{
    std::ifstream fileStream("/proc/cpuinfo");
    std::string currentLine;

    if (fileStream.is_open()) {
        while (fileStream.good()) {
            getline(fileStream, currentLine);
            if (currentLine.find("cpu MHz") == 0) {
                currentLine = currentLine.substr(11, currentLine.size() - 11);
                _frequency = atof(currentLine.c_str());
                }
        }
        fileStream.close();
    }
}

void CpuModule::displaySFML(sf::RenderWindow *window)
{
    updateFerquency();
    int i;
    int a = 450;
    int b = 370;
    int c = 555;
    std::ostringstream tmp;
    std::ostringstream tmp_second;
    std::ostringstream tmp_third;
    std::ostringstream tmp4;
    tmp <<  _cpuModel.c_str();
    tmp_second << _frequency << "MHz";
    tmp_third << _nbCore;

    std::string str_third(tmp_third.str());
    std::string str_second(tmp_second.str());
    std::string str(tmp.str());
    updateCpuActivity();
    displayShape(window, 320, 275, 1270, 250);
    displayTitle(window, "CPU module :", 350, 225, 25);
    displayText(window, str, 615, 225, 23);
    for (i = 1 ; i < getNbCpu(); ++i) {
        tmp4.str("");
        tmp4 << std::setprecision(3) << _cpuActivity[i];
        std::string str4(tmp4.str() + "%");
        displayTitle(window, "CPU " + std::to_string(i) + " :", a, b, 21);
        displayText(window, str4, c, b, 21);
        a += 250;
        if (i % 4 == 0) {
            a -= 1000;
            b += 70;
        }
        c = a + 115;
    }
    displayTitle(window, "Frequency :", 370, 285, 23);
    displayText(window, str_second, 590, 285, 23);
    displayTitle(window, "Number of core :", 800, 920, 23);
    displayText(window, str_third, 1085, 920, 23);
}


const std::string &CpuModule::getCpuModel() const { return (_cpuModel); }

int CpuModule::getNbCore() const { return (_nbCore); }

int CpuModule::getNbCpu() const { return (_nbCpu + 1); }

float CpuModule::getFrequency() const { return (_frequency); }

bool CpuModule::getStatus() const { return (_isActiv); }

char CpuModule::getKey() const { return (_key); }

const std::vector<double> CpuModule::getActivity() const { return (_cpuActivity); }

void CpuModule::setStatus()
{
    if (_isActiv == true)
        _isActiv = false;
    else
        _isActiv = true;
}

void CpuModule::readFirstTime(int nbLine)
{
    std::ifstream fileStream;
    std::string currentLine;
    int i = 0;
    int j = 0;

    fileStream.open("/proc/stat");
    if (fileStream.is_open()) {
        while (i <= nbLine) {
            getline(fileStream, currentLine);
            currentLine = currentLine.substr(5, currentLine.size() - 5);
            _firstReadtotal[i] = (double)atol(currentLine.substr(0, currentLine.find(" ")).c_str());
            currentLine = currentLine.substr(currentLine.find(" ") + 1, currentLine.size());
            _firstReadtotal[i] += (double)atol(currentLine.substr(0, currentLine.find(" ")).c_str());
            currentLine = currentLine.substr(currentLine.find(" ") + 1, currentLine.size());
            _firstReadtotal[i] += (double)atol(currentLine.substr(0, currentLine.find(" ")).c_str());
            currentLine = currentLine.substr(currentLine.find(" ") + 1, currentLine.size());
            _firstReadval[i] = (double)atol(currentLine.substr(0, currentLine.find(" ")).c_str());
            currentLine = currentLine.substr(currentLine.find(" ") + 1, currentLine.size());
            _firstReadval[i] += (double)atol(currentLine.substr(0, currentLine.find(" ")).c_str());
            _firstReadtotal[i] += _firstReadval[i];
            j = 0;
            while (j < 3) {
                currentLine = currentLine.substr(currentLine.find(" ") + 1, currentLine.size());
                _firstReadtotal[i] += (double)atol(currentLine.substr(0, currentLine.find(" ")).c_str());
                ++j;
            }
            _firstReadval[i] = _firstReadtotal[i] - _firstReadval[i];
            ++i;
        }
        fileStream.close();
    }
}

void CpuModule::readSecondTime(int atLine)
{
    std::ifstream fileStream;
    std::string currentLine;
    int i = 0;

    fileStream.open("/proc/stat");
    if (fileStream.is_open()) {
        while (i <= atLine) {
            getline(fileStream, currentLine);
            ++i;
        }
        currentLine = currentLine.substr(5, currentLine.size() - 5);
        _secondReadTotal = (double)atol(currentLine.substr(0, currentLine.find(" ")).c_str());
        currentLine = currentLine.substr(currentLine.find(" ") + 1, currentLine.size());
        _secondReadTotal += (double)atol(currentLine.substr(0, currentLine.find(" ")).c_str());
        currentLine = currentLine.substr(currentLine.find(" ") + 1, currentLine.size());
        _secondReadTotal += (double)atol(currentLine.substr(0, currentLine.find(" ")).c_str());
        _secondReadVal = (double)atol(currentLine.substr(0, currentLine.find(" ")).c_str());
        currentLine = currentLine.substr(currentLine.find(" ") + 1, currentLine.size());
        _secondReadVal += (double)atol(currentLine.substr(0, currentLine.find(" ")).c_str());
        _secondReadTotal += _secondReadVal;
        i = 0;
        while (i < 3) {
            currentLine = currentLine.substr(currentLine.find(" ") + 1, currentLine.size());
            _secondReadTotal += (double)atol(currentLine.substr(0, currentLine.find(" ")).c_str());
            ++i;
        }
        _secondReadVal = _secondReadTotal - _secondReadVal;
        fileStream.close();
    }
}

void CpuModule::updateCpuActivity()
{
    readFirstTime(_nbCpu);
    usleep(200000);
    for (int i = 0; i < getNbCpu(); ++i) {
        readSecondTime(i);
        if((_secondReadTotal == _firstReadtotal[i]) || (_secondReadVal == _firstReadval[i]))
            _cpuActivity[i] = 0;
        else
            _cpuActivity[i] = ((_secondReadVal - _firstReadval[i]) / (_secondReadTotal - _firstReadtotal[i])) * 100;
    }
}

void CpuModule::displayNcurses()
{
    updateFerquency();
    updateCpuActivity();
	attron(COLOR_PAIR(1));
    printw("\tCPU: ");
	attron(COLOR_PAIR(5));
    if (_cpuActivity[0] > 80)
        attron(COLOR_PAIR(3));
    else if (_cpuActivity[0] < 20)
        attron(COLOR_PAIR(4));
    printw("%.2f%% ", _cpuActivity[0]);
	attron(COLOR_PAIR(2));
    printw("(%s) \n", _cpuModel.c_str());
	attron(COLOR_PAIR(1));
    printw("\t|");
	attron(COLOR_PAIR(8));
    if (_cpuActivity[0] > 80)
        attron(COLOR_PAIR(6));
    else if (_cpuActivity[0] < 20)
        attron(COLOR_PAIR(7));
    for (int i = 0;  i < _cpuActivity[0] / 5; i++) {
        printw(" ");
    }
	attron(COLOR_PAIR(1));
    for (int i = 0; i < (20 - _cpuActivity[0] / 5); i++) {
        printw("-");
    }
    attron(COLOR_PAIR(1));
    printw("|\n\n");
	attron(COLOR_PAIR(1));
    printw("\tFrequency: ");
	attron(COLOR_PAIR(2));
    printw("%.2fMHz\n", _frequency);
	attron(COLOR_PAIR(1));
    printw("\tCores: ");
	attron(COLOR_PAIR(2));
    printw("%d\n\n", _nbCore);
    for (int i = 1; i < getNbCpu(); i++) {
        attron(COLOR_PAIR(1));
        printw("\tCPU%d: ", i);
    	attron(COLOR_PAIR(5));
        if (_cpuActivity[i] > 80)
            attron(COLOR_PAIR(3));
        else if (_cpuActivity[i] < 20)
            attron(COLOR_PAIR(4));
        printw("%.2f%%\t", _cpuActivity[i]);
        if (i % 4 == 0)
            printw("\n");
    }
}
