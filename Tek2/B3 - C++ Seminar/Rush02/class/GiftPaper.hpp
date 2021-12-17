/*
** EPITECH PROJECT, 2021
** CPP-RUSH2 [WSL: Ubuntu]
** File description:
** GiftPaper
*/

#ifndef GIFTPAPER_HPP_
#define GIFTPAPER_HPP_

#include "Wrap.hpp"
#include "Box.hpp"

class GiftPaper : public virtual Wrap {
    public:
        explicit GiftPaper();
        virtual ~GiftPaper();
        void closeMe();
        void wrapMeThat(Object *object);
    private:
};

#endif /* !GIFTPAPER_HPP_ */
