/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD07A-pierre.jeannin
** File description:
** Phaser
*/

#include <iostream>
#include "Phaser.hpp"
#include "Sounds.hpp"

Phaser::Phaser(int maxAmmo, AmmoType type) : _type(type), _bullet(maxAmmo), _maxBullet(maxAmmo)
{
}

Phaser::~Phaser()
{
}

void Phaser::fire()
{
    if (_bullet == 0)
        std::cout << "Clip empty , please reload" << std::endl;
    else {
        Sounds s;

        switch (_type)
        {
        case 0:
            std::cout << s.Regular << std::endl;
            break;
        case 1:
            std::cout << s.Plasma << std::endl;
            break;
        case 2:
            std::cout << s.Rocket << std::endl;
            break;
        default:
            break;
        }
        --_bullet;
    }
}

void Phaser::ejectClip()
{
    _bullet = 0;
}

void Phaser::changeType(AmmoType type)
{
    _type = type;
}

void Phaser::reload()
{
    std::cout << "Reloading ..." << std::endl;
    _bullet = _maxBullet;
}