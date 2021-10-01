//
// Created by Pierre Jeannin on 14/06/2021.
//

#ifndef BOMBERMAN_IPOWERUP_HPP
#define BOMBERMAN_IPOWERUP_HPP

#include "../raylib-cpp/src/vector/Vector.hpp"
#include "../raylib-cpp/src/color/Color.hpp"
#include "../raylib-cpp/src/model/Model.hpp"
#include "../raylib-cpp/src/texture/Texture.hpp"
#include "../../../include/Include.hpp"

class IPowerUp {
    public:
        enum Type {
            BOMB_UP,
            SPEED_UP,
            FIRE_UP,
            HP_UP
        };
        virtual ~IPowerUp() = default;
        virtual Type getType() const = 0;
        virtual void draw() = 0;
        virtual bool isTaken() const = 0;

    protected:
    private:
};


#endif //BOMBERMAN_IPOWERUP_HPP
