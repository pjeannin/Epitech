/*
** EPITECH PROJECT, 2024
** B-YEP-400-STG-4-1-indiestudio-antony.fantapie
** File description:
** Created by antonyftp
*/

#include "scene/menu/Menu.hpp"
#include "scene/game/Game.hpp"
#include "core/Core.hpp"

int main()
{
    Core core;
    core.loadScene<Menu>();
    core.loop();
    return 0;
}
