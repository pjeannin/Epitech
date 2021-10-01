//
// Created by yann on 19/06/2021.
//

#ifndef BOMBERMAN_INCLUDE_HPP
#define BOMBERMAN_INCLUDE_HPP

#include "../raylib-cpp/src/model/Model.hpp"
#include "../raylib-cpp/src/texture/Texture.hpp"

#include <map>

enum class ModelList { Barrel, BoatBlue, BoatRed, BoatGreen, BoatYellow, Explosion, FireUp, BombUp, HPUp, SpeedUp };

using Model3D = std::pair<raylib::Model *, raylib::Texture *>;
using ModelList3D = std::map<ModelList const, Model3D>;

#endif //BOMBERMAN_INCLUDE_HPP
