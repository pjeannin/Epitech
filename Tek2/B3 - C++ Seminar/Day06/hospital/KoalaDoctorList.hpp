/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-pierre.jeannin
** File description:
** KoalaDoctorList
*/

#ifndef KOALADOCTORLIST_HPP_
#define KOALADOCTORLIST_HPP_

#include "KoalaDoctor.hpp"

class KoalaDoctorList {
    public:
        KoalaDoctorList(KoalaDoctor *doctor);
        KoalaDoctorList();
        ~KoalaDoctorList();
        bool isEnd();
        void append(KoalaDoctorList *new_node);
        KoalaDoctor *getFromName(std::string name);
        KoalaDoctorList *remove(KoalaDoctorList *to_remove);
        KoalaDoctorList *removeFromName(std::string to_remove);
        KoalaDoctor *getContent();
        KoalaDoctorList *getNext();
        void dump();

    protected:
    private:
        KoalaDoctor *_doctor;
        KoalaDoctorList *_next;
};

#endif /* !KOALADOCTORLIST_HPP_ */