/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by antonyftp
*/

#ifndef BOMBERMAN_AI_HPP
#define BOMBERMAN_AI_HPP

#include "../Boat.hpp"
#include "../IBoatController.hpp"
#include "../../../../include/Include.hpp"

#include <cstdlib>
#include <ctime>

#define detectBoat(index) Cells[index]->getType() == 'P' || Cells[index]->getType() == 'Q' || Cells[index]->getType() == 'R' || Cells[index]->getType() == 'S'
#define detectDestructibleWall(index) Cells[index]->getType() == 'O'

class AI : public Boat {
    public:
        AI(raylib::Vector3 position, Boat::Team const team, unsigned int id, ModelList3D &models);
        ~AI() = default;
        void update(Bombs &bombs, Map *map, std::vector<APowerUp *>&bonus) override;
    protected:
    private:
        // Attributs
        bool _bombState;
        bool _first;
        Direction _direction;
        raylib::Vector3 _oldCell;
        std::mt19937 _mt;
        std::chrono::steady_clock::time_point _directionTimePoint;
        std::chrono::steady_clock::time_point _bombTimePoint;
        std::chrono::steady_clock::time_point _timePoint;
        long long _time;

        // Functions
        void updateDirection(std::vector<Cell *> &Cells, std::vector<Direction> *freeDirections, int boat);
        void updateBomb(std::vector<Cell *> &Cells, Bombs *bombs, int boat);
        int getBoat(std::vector<Cell *> &Cells);
        std::vector<Direction> *getFreeDirections(std::vector<Cell *> &Cells, int boat);
        bool detectCrossroad(std::vector<Direction> *freeDirections);
        bool dodgeBomb(Bombs &bombs, Map *map);
        void reverseDirection(Bombs &bombs, Map *map, std::vector<APowerUp *>&bonus);
        bool checkDirection(raylib::Vector3 &diff);
};

#endif //BOMBERMAN_AI_HPP
