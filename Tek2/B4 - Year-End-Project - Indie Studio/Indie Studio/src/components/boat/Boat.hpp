/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by antonyftp
*/

#ifndef BOMBERMAN_BOAT_HPP
#define BOMBERMAN_BOAT_HPP

#include "raylib-cpp.hpp"
#include "./IBoatController.hpp"
#include "../image/Image.hpp"
#include "../../../include/Include.hpp"
#include <map>
#include <chrono>

class Boat : public IBoatController {
    public:
        enum Team { BLUE_TEAM, RED_TEAM, GREEN_TEAM, YELLOW_TEAM };
        enum Direction { LEFT, RIGHT, UP, DOWN };

        explicit Boat(raylib::Vector3 const &position, Boat::Team const team, unsigned int id, ModelList3D &models);
        ~Boat() = default;

        Bomb *placeBomb(raylib::Vector3 const &position);
        bool notCollide(raylib::Vector3 position, Map *map, Bombs &bombs);
        void kill();
        void move(Direction direction, Map *map, std::vector<APowerUp *>&bonus, Bombs &bombs);
        void draw();
        void bombUp();
        void speedUp();
        void fireUp();
        void hpUp();
        void anim();

        void drawPowerUpS();
        void drawPowerUpW();
        void drawPowerUpB();
        void drawPowerUpF();
        int getBombMax() const;
        void setBombMax(const int bomb);
        int getBombRange() const;
        void setBombRange(const int bomb);
        float getSpeed() const;
        void setSpeed(const float speed);
        unsigned int getId() const;
        int getHP() const;
        void setHP(const int hp);
        bool isIsAlive() const;
        void setIsAlive(bool const isAlive);
        const raylib::Vector3 &getPosition() const;
        Team getTeam() const;
        void checkCollideBonus(std::vector<APowerUp *>&bonus);
        void giveBonus(APowerUp *powerUp);

    protected:
        int currentNumberOfBomb(Bombs &bombs) const;
        int _bombMax;
        int _bombRange;
        float _speed;
        int _hp;
        bool _isAlive;
        raylib::Vector3 _position;
        Team _team;
        unsigned int _id;
        int _direction;
        Bomberman::Image _powerUpS;
        Bomberman::Image _powerUpW;
        Bomberman::Image _powerUpF;
        Bomberman::Image _powerUpB;
        ModelList3D &_models;
        Model3D  &_boat;
        float _zAnim;
        bool _anim;
        raylib::Vector3 _tmp;
        std::chrono::steady_clock::time_point _time1;
        raylib::Sound _fxSelect;
        std::map<unsigned int, char> _idMap;
};

void killBoats(std::vector<Boat *> &boats, Bomb &bomb, Map &map);

using Boats = std::vector<Boat *>;

#endif //BOMBERMAN_BOAT_HPP
