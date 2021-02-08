/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD07A-pierre.jeannin
** File description:
** KreogCom
*/

#ifndef KREOGCOM_HPP_
#define KREOGCOM_HPP_

#include <stdlib.h>

class KreogCom {
    public:
        KreogCom(int x, int y, int serial, KreogCom *next = NULL);
        ~KreogCom();
        void addCom(int x, int y, int serial);
        void removeCom();
        KreogCom *getCom();
        void ping() const;
        void locateSquad() const;
    protected:
    private:
        const int _serial;
        int _x;
        int _y;
        KreogCom *_next;
};

#endif /* !KREOGCOM_HPP_ */
