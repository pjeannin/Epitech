/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include "Error.hpp"
#include "Loader.hpp"
#include "../interfaces/IGraphics.hpp"
#include "../interfaces/IGame.hpp"

class Core {
    public:
        Core();
        ~Core();

        int run(std::string graphicPath);
        void createMenu(std::vector<std::filesystem::path>::iterator &currentGraphIt);
        void gameLoop(std::vector<std::filesystem::path>::iterator itGraph, std::vector<std::filesystem::path>::iterator itGame, std::ofstream &scoreFile);
        void loadGraphic(std::vector<std::filesystem::path>::iterator it);


    protected:
    private:
        std::vector<std::filesystem::path> _game;
        std::vector<std::filesystem::path> _graphic;
        Loader<IGraphic>_current_graphic;
        Loader<IGame>_current_game;
        std::string _name;
        Event event;

};

#endif /* !CORE_HPP_ */
