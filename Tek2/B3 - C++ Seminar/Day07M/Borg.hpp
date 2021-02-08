/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD07M-pierre.jeannin
** File description:
** Borg
*/

#ifndef BORG_HPP_
#define BORG_HPP_

#include <iostream>
#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Borg
{
    class Ship
    {
        public:
            Ship(int weaponFrequency = 20, short repair = 3);
            ~Ship();
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            int getShield();
            void setShield(int shield);
            int getWeaponFrequency();
            void setWeaponFrequency(int frequency);
            short getRepair();
            void setRepair(short repair);
            //void fire(Federation::Starfleet::Ship *target);
            //void fire(Federation::Ship *target);
            void repair();
        protected:
        private:
            int _side;
            int _maxWarp;
            WarpSystem::Core *_core;
            Destination _location;
            Destination _home;
            int _shield;
            int _weaponFrequency;
            short _repair;
    };
}

#endif /* !BORG_HPP_ */
