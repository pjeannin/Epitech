//
// Created by Pierre Jeannin on 14/06/2021.
//

#ifndef BOMBERMAN_BOMBUP_HPP
#define BOMBERMAN_BOMBUP_HPP

#include "APowerUp.hpp"

class BombUp : public APowerUp {
    public:
        BombUp(Vector3 position, Model3D &model);
};


#endif //BOMBERMAN_BOMBUP_HPP
