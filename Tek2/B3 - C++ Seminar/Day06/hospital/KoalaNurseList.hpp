/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-pierre.jeannin
** File description:
** KoalaNurseList
*/

#ifndef KOALANURSELIST_HPP_
#define KOALANURSELIST_HPP_

#include "KoalaNurse.hpp"

class KoalaNurseList {
    public:
        KoalaNurseList(KoalaNurse *nurse);
        KoalaNurseList();
        ~KoalaNurseList();
        bool isEnd();
        void append(KoalaNurseList *new_node);
        KoalaNurse *getFromID(int id);
        KoalaNurseList *remove(KoalaNurseList *to_remove);
        KoalaNurseList *removeFromID(int to_remove);
        KoalaNurse *getContent();
        void dump();
        KoalaNurseList *getNext();

    protected:
    private:
        KoalaNurse *_nurse;
        KoalaNurseList *_next;
};

#endif /* !KOALANURSELIST_HPP_ */
