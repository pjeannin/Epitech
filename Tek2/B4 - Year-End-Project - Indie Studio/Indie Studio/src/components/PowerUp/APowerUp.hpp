//
// Created by Pierre Jeannin on 14/06/2021.
//

#ifndef BOMBERMAN_APOWERUP_HPP
#define BOMBERMAN_APOWERUP_HPP

#include "IPowerUp.hpp"
#include <string>
#include <chrono>

class APowerUp : public IPowerUp {
public:
    APowerUp(Type type, raylib::Vector3 position, Model3D &model);
    ~APowerUp() = default;
    Type getType() const;
    void draw();
    bool isTaken() const;
    raylib::Vector3 getPosition() const;
    void anim();
protected:
    bool _isTook;
    Type _type;
    Model3D &_model;
    raylib::Vector3 _position;
    std::chrono::steady_clock::time_point _time1;
    float _animVal;
private:
};

#endif //BOMBERMAN_APOWERUP_HPP
