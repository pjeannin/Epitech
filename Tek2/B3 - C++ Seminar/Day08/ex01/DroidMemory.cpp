/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD08-pierre.jeannin
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory() : _exp(0), _fingerprint(random())
{
}

DroidMemory::~DroidMemory()
{
}

void DroidMemory::setExp(size_t exp) { _exp = exp; }

void DroidMemory::setFingerprint(size_t fingerprint) { _fingerprint = fingerprint; }

size_t DroidMemory::getExp() const { return (_exp); };

size_t DroidMemory::getFingerprint() const { return (_fingerprint); }

DroidMemory &DroidMemory::operator<<(DroidMemory &memory)
{
    _exp += memory.getExp();
    _fingerprint = _fingerprint ^ memory.getFingerprint();

    return (*this);
}

DroidMemory &DroidMemory::operator>>(DroidMemory &memory)
{
    memory.setExp(_exp + memory.getExp());
    memory.setFingerprint(memory.getFingerprint() ^_fingerprint);

    return (*this);
}

DroidMemory &DroidMemory::operator+=(DroidMemory &memory)
{
    _exp += memory.getExp();
    _fingerprint = _fingerprint ^ memory.getFingerprint();

    return (*this);
}

DroidMemory &DroidMemory::operator+=(size_t exp)
{
    _exp += exp;
    _fingerprint = _fingerprint ^ exp;

    return (*this);
}

DroidMemory &DroidMemory::operator+(DroidMemory &droidMemory)
{
    DroidMemory *d = new DroidMemory;

    d->setExp(_exp + droidMemory.getExp());
    d->setFingerprint(_fingerprint ^ droidMemory.getFingerprint());

    return (*d);
}

DroidMemory &DroidMemory::operator+(size_t exp)
{
    DroidMemory *d = new DroidMemory;

    d->setExp(_exp + exp);
    d->setFingerprint(_fingerprint ^ exp);

    return (*d);
}

DroidMemory &DroidMemory::operator=(DroidMemory &droidmemory)
{
    _exp = droidmemory.getExp();
    _fingerprint = droidmemory.getFingerprint();

    return (*this);
}

std::ostream &operator<<(std::ostream &stream, const DroidMemory &droidMemory) { return (stream << "DroidMemory '" << droidMemory.getFingerprint() << "', " << droidMemory.getExp()); }