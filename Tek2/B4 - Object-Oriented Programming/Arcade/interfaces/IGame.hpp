/*
** EPITECH PROJECT, 2021
** IGame
** File description:
** IGame
*/
#ifndef __IGAME__
#define __IGAME__

#include "IGraphics.hpp"

#include <map>
#include <string>

class IGame {
    public:
        virtual ~IGame() = default;
        virtual void event(Event const Event) = 0;
        virtual void update(int elapsedTime) = 0;
        virtual void render(IGraphicRender &renderer) const = 0;
        virtual const std::string getScore() = 0;
};

#endif /* __IGAME__ */
