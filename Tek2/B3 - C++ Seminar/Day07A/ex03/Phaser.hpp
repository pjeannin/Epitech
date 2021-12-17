/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD07A-pierre.jeannin
** File description:
** Phaser
*/

#ifndef PHASER_HPP_
#define PHASER_HPP_

class Phaser {
    public:
        enum AmmoType { REGULAR , PLASMA , ROCKET };
        Phaser(int maxAmmo = 20, AmmoType type = REGULAR);
        ~Phaser();
        void fire();
        void ejectClip();
        void changeType(AmmoType newType);
        void reload();
        void addAmmo(AmmoType type);
        int getCurrentAmmos();

    protected:
    private:
        static const int Empty = 0;
        int _bullet;
        int _maxBullet;
        AmmoType _type;
};

#endif /* !PHASER_HPP_ */
