/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by antonyftp
*/

#ifndef BOMBERMAN_BOMB_HPP
#define BOMBERMAN_BOMB_HPP

#include <chrono>
#include "raylib-cpp.hpp"
#include "../Map/Map.hpp"
#include "../Map/Cell.hpp"
#include "../PowerUp/APowerUp.hpp"
#include "../PowerUp/BombUp.hpp"
#include "../PowerUp/SpeedUp.hpp"
#include "../PowerUp/FireUp.hpp"
#include "../PowerUp/HPUp.hpp"
#include "../../../include/Include.hpp"

class Bomb {
    public:
        Bomb(const raylib::Vector3 &position, int const Range, unsigned int id, ModelList3D &models);
        ~Bomb() = default;
        void updateRemainingTime(Map *map, std::vector<APowerUp *> &bonus);
        long long getRemainingTime() const;
        void explodes(Map *map, std::vector<APowerUp *> &bonus);
        void draw(Map *Map);

        const raylib::Vector3 &getPosition() const;
        int getRange() const;
        bool getExploded() const;
        float getScale() const;
        void setExploded(const bool value);
        unsigned int getOwnerId() const;
        bool getDone() const;
        void setDone(bool done);
    protected:
    private:
        raylib::Vector3 _position;
        int _range;
        unsigned int _id;
        ModelList3D &_models;
        Model3D &_barrel, _explosion;
        bool exploded;
        long long _remainingTime;
        std::chrono::steady_clock::time_point _timePoint;
        std::vector<raylib::Vector3> _explosionAnim;
        float _explosionScale;
        raylib::Sound _fxExplosion;
        bool _done;
};

typedef std::vector<Bomb *>Bombs;

#endif //BOMBERMAN_BOMB_HPP
