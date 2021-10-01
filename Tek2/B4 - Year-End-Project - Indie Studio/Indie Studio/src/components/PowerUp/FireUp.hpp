//
// Created by Pierre Jeannin on 14/06/2021.
//

#ifndef BOMBERMAN_FIREUP_HPP
#define BOMBERMAN_FIREUP_HPP

#include "APowerUp.hpp"

class FireUp : public APowerUp {
    public:
        FireUp(Vector3 position, Model3D &model);
};


#endif //BOMBERMAN_FIREUP_HPP
