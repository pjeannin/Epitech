/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD07M-pierre.jeannin
** File description:
** Federation
*/

#include "Federation.hpp"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo) : _length(length), _width(width), _name(name), _maxWarp(maxWarp), _captain(NULL), _home(EARTH), _location(EARTH), _shield(100), _photonTorpedo(torpedo)
{
    std::cout << "The ship USS " << name <<  " has been finished." << std::endl
    << "It is " << length << " m in length and " << width << " m in width." << std::endl
    << "It can go to Warp " << maxWarp << "!" << std::endl;
    if (torpedo != 0)
        std::cout << "Weapons are set: " << torpedo << " torpedoes ready." << std::endl;
}

Federation::Starfleet::Ship::Ship() : _length(289), _width(132), _name("Entreprise"), _maxWarp(6), _captain(NULL), _home(EARTH), _location(EARTH), _shield(100), _photonTorpedo(0)
{
    std::cout << "The ship USS " << _name <<  " has been finished." << std::endl
    << "It is " << _length << " m in length and " << _width << " m in width." << std::endl
    << "It can go to Warp " << _maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    std::cout << "USS " << _name << ": The core is " << (_core->checkReactor()->isStable() ? "stable" : "unstable") << " at the time." << std::endl;
}

void Federation::Starfleet::Ship::promote(Captain *captain)
{
    _captain = captain;
    std::cout << captain->getName() << ": I'm glad to be the captain of the USS " << _name << "." << std::endl;
}

bool Federation::Starfleet::Ship::move()
{
    if (_location == _home || !_core->checkReactor()->isStable())
        return (false);
    _location = _home;

    return (true);
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    if (_location == d || !_core->checkReactor()->isStable())
        return (false);
    _location = d;

    return (true);
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (_location == d || !_core->checkReactor()->isStable() || !(warp < _maxWarp))
        return (false);
    _location = d;

    return (true);
}

bool Federation::Starfleet::Ship::move(int warp)
{
    if (_location == _home || !_core->checkReactor()->isStable() || !(warp < _maxWarp))
        return (false);
    _location = _home;

    return (true);
}

int Federation::Starfleet::Ship::getShield()
{
    return (_shield);
}

int Federation::Starfleet::Ship::getTorpedo()
{
    return (_photonTorpedo);
}

void Federation::Starfleet::Ship::setShield(int shield)
{
    _shield = shield;
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    _photonTorpedo = torpedo;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    if (_photonTorpedo == 0) {
        std::cout << _name << ": No enough torpedoes to fire, " << _captain->getName() << "!" << std::endl;
        return;
    }
    --_photonTorpedo;
    target->setShield(target->getShield() - 50);
    std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
    if(_photonTorpedo == 0)
        std::cout << _name << ": No more torpedo to fire, " << _captain->getName() << "!" << std::endl;
}

void Federation::Starfleet::Ship::fire(int torpedoes , Borg::Ship *target)
{
    if (_photonTorpedo == 0) {
        std::cout << _name << ": No enough torpedoes to fire, " << _captain->getName() << "!" << std::endl;
        return;
    }
    if (_photonTorpedo < torpedoes)
        torpedoes = _photonTorpedo;
    _photonTorpedo -= torpedoes;
    target->setShield(target->getShield() - 50 * torpedoes);
    std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
}

Federation::Starfleet::Ensign::Ensign(std::string name) : _name(name)
{
    std::cout << "Ensign " << name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{
}

Federation::Ship::Ship(int lenght, int width, std::string name) : _length(lenght), _width(width), _name(name), _maxWarp(1), _home(VULCAN), _location(VULCAN)
{
    std::cout << "The independent ship " << name <<  " just finished its construction." << std::endl
    << "It is " << lenght << " m in length and " << width << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << _name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
    std::cout << _name << ": The core is " << (_core->checkReactor()->isStable() ? "stable" : "unstable") << " at the time." << std::endl;
}

bool Federation::Ship::move()
{
    if (_location == _home || !_core->checkReactor()->isStable())
        return (false);
    _location = _home;

    return (true);
}

bool Federation::Ship::move(Destination d)
{
    if (_location == d || !_core->checkReactor()->isStable())
        return (false);
    _location = d;

    return (true);
}

bool Federation::Ship::move(int warp, Destination d)
{
    if (_location == d || !_core->checkReactor()->isStable() || !(warp < _maxWarp))
        return (false);
    _location = d;

    return (true);
}

bool Federation::Ship::move(int warp)
{
    if (_location == _home || !_core->checkReactor()->isStable() || !(warp < _maxWarp))
        return (false);
    _location = _home;

    return (true);
}

WarpSystem::Core *Federation::Ship::getCore()
{
    return (_core);
}

int Federation::Ship::getShield()
{
    return (_shield);
}

int Federation::Ship::getTorpedo()
{
    return (_photonTorpedo);
}

void Federation::Ship::setShield(int shield)
{
    _shield = shield;
}

void Federation::Ship::setTorpedo(int torpedo)
{
    _photonTorpedo = torpedo;
}

Federation::Starfleet::Captain::Captain(std::string name) : _name(name), _age(0)
{
}

Federation::Starfleet::Captain::~Captain()
{
}

std::string Federation::Starfleet::Captain::getName()
{
    return (_name);
}

int Federation::Starfleet::Captain::getAge()
{
    return (_age);
}

void Federation::Starfleet::Captain::setAge(int age)
{
    _age = age;
}