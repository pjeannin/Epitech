/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Maze
*/

#ifndef MAZE_HPP_
#define MAZE_HPP_

#include <vector>
#include <stack>
#include <random>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include "Cell.hpp"

#define TIME_SIZE 50
class Map {
    public:
        Map();
        ~Map() = default;
        void DFSGenerator();
        void print();
        void anim();
        void drawDecorations();
        void drawBorder();
        void drawMap();
        void randDestructible();
        void reset();
        std::vector<Cell *>getGrid() const;

    protected:
    private:
        std::vector<Cell *>Grid;
        std::vector<int> _rockChoose;
        std::vector<float> _randRotation;
        raylib::Model _undestructible1;
        raylib::Texture _textureUndestructible1;
        raylib::Model _undestructible2;
        raylib::Texture _textureUndestructible2;
        raylib::Model _undestructible3;
        raylib::Texture _textureUndestructible3;
        raylib::Model _undestructible4;
        raylib::Texture _textureUndestructible4;
        raylib::Model _destructible;
        raylib::Texture _textureDestructible;
        raylib::Model _boatPink;
        raylib::Texture _textureBoatPink;
        raylib::Model _boatDark;
        raylib::Texture _textureBoatDark;
        raylib::Model _whale;
        raylib::Texture _textureWhale;
        float _zAnim;
        bool _anim;
        raylib::Vector3 _tmp;
        std::chrono::steady_clock::time_point _time1;
};

#endif /* !MAZE_HPP_ */
