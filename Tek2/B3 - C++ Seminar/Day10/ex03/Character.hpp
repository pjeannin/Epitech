/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
    public:
        Character(std::string const name);
        Character(Character &character);
        ~Character();
        const std::string &getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
        Character &operator=(Character &character);

    protected:
    private:
        std::string _name;
        AMateria *_inventory[4];
};

#endif /* !CHARACTER_HPP_ */
