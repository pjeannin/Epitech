/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD08-pierre.jeannin
** File description:
** DroidMemory
*/

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

#include <iostream>
#include <stdlib.h>

class DroidMemory {
    public:
        DroidMemory();
        ~DroidMemory();
        void setFingerprint(size_t fingerprint);
        void setExp(size_t exp);
        size_t getFingerprint() const;
        size_t getExp() const;
        DroidMemory &operator<<(DroidMemory &droidMemory);
        DroidMemory &operator>>(DroidMemory &droidMemory);
        DroidMemory &operator+=(DroidMemory &droidMemory);
        DroidMemory &operator+=(size_t exp);
        DroidMemory &operator+(DroidMemory &roidMemory);
        DroidMemory &operator+(size_t exp);
        DroidMemory &operator=(DroidMemory &droidmemory);
        bool operator==(DroidMemory droidMemory) const;
        bool operator!=(DroidMemory droidMemory) const;
        bool operator<(DroidMemory droidMemory) const;
        bool operator>(DroidMemory droidMemory) const;
        bool operator<=(DroidMemory droidMemory) const;
        bool operator>=(DroidMemory droidMemory) const;
        bool operator<(size_t exp) const;
        bool operator>(size_t exp) const;
        bool operator<=(size_t exp) const;
        bool operator>=(size_t exp) const;

    protected:
    private:
        size_t _fingerprint;
        size_t _exp;
};

std::ostream &operator<<(std::ostream &stream, const DroidMemory &droidMemory);

#endif /* !DROIDMEMORY_HPP_ */
