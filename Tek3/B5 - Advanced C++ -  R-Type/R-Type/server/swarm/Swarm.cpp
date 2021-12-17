/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#include "Swarm.hpp"
#include <stdlib.h>
#include <time.h>

RType::ECS::Swarm::Swarm() noexcept
{

}

std::shared_ptr<RType::ECS::IGameObject> RType::ECS::Swarm::genMaluses(int posX, int posY, int id)
{
    srand(time(nullptr));
    switch (rand() % (FINMALUSES - 1) + 6) {
        case 1:
            return (std::make_shared<RType::Server::GameObjects::Malus1>(RType::ECS::ID(id), RType::ECS::Position(posX, posY), RType::ECS::Health(100), RType::ECS::HitBox(10, 10, std::make_pair(0, 0)), RType::ECS::State(), RType::ECS::EffectHandler()));
        case 2:
            return (std::make_shared<RType::Server::GameObjects::Malus2>(RType::ECS::ID(id), RType::ECS::Position(posX, posY), RType::ECS::Health(100), RType::ECS::HitBox(10, 10, std::make_pair(0, 0)), RType::ECS::State(), RType::ECS::EffectHandler()));
        case 3:
            return (std::make_shared<RType::Server::GameObjects::Malus3>(RType::ECS::ID(id), RType::ECS::Position(posX, posY), RType::ECS::Health(100), RType::ECS::HitBox(10, 10, std::make_pair(0, 0)), RType::ECS::State(), RType::ECS::EffectHandler()));
        default:
            return (nullptr);
    }
}

std::shared_ptr<RType::ECS::IGameObject> RType::ECS::Swarm::genBonuses(int posX, int posY, int id)
{
    srand(time(nullptr));
    switch (rand() % (FINBONUSES - 1) + 6) {
        case 1:
            return (std::make_shared<RType::Server::GameObjects::Bonus1>(RType::ECS::ID(id), RType::ECS::Position(posX, posY), RType::ECS::Health(100), RType::ECS::HitBox(10, 10, std::make_pair(0, 0)), RType::ECS::State(), RType::ECS::EffectHandler()));
        case 2:
            return (std::make_shared<RType::Server::GameObjects::Bonus2>(RType::ECS::ID(id), RType::ECS::Position(posX, posY), RType::ECS::Health(100), RType::ECS::HitBox(10, 10, std::make_pair(0, 0)), RType::ECS::State(), RType::ECS::EffectHandler()));
        case 3:
            return (std::make_shared<RType::Server::GameObjects::Bonus3>(RType::ECS::ID(id), RType::ECS::Position(posX, posY), RType::ECS::Health(100), RType::ECS::HitBox(10, 10, std::make_pair(0, 0)), RType::ECS::State(), RType::ECS::EffectHandler()));
        default:
            return (nullptr);
    }
}

std::vector<std::shared_ptr<RType::ECS::AEnemy>> RType::ECS::Swarm::genSwarm(int nb, int id)
{
    std::vector<std::shared_ptr<RType::ECS::AEnemy>> swarm;
    int posY = 0;

    srand(time(NULL));
    for (int i = 0; i != nb; ++i) {
        posY = rand() % 1081;
        switch (rand() % (FINENNEMIES - 1) + 1) {
            case 1:
                swarm.emplace_back(std::make_shared<RType::Server::GameObjects::Enemy1>(RType::ECS::ID(id), RType::ECS::Position(2200, posY), RType::ECS::Acceleration(0, 0), RType::ECS::Health(100), RType::ECS::HitBox(10, 10, std::make_pair(0, 0)), RType::ECS::WeaponHolder(), RType::ECS::State(), RType::ECS::EffectHandler()));
                break;
            case 2:
                swarm.emplace_back(std::make_shared<RType::Server::GameObjects::Enemy2>(RType::ECS::ID(id), RType::ECS::Position(2200, posY), RType::ECS::Acceleration(0, 0), RType::ECS::Health(100), RType::ECS::HitBox(10, 10, std::make_pair(0, 0)), RType::ECS::WeaponHolder(), RType::ECS::State(), RType::ECS::EffectHandler()));
                break;
            case 3:
                swarm.emplace_back(std::make_shared<RType::Server::GameObjects::Enemy3>(RType::ECS::ID(id), RType::ECS::Position(2200, posY), RType::ECS::Acceleration(0, 0), RType::ECS::Health(100), RType::ECS::HitBox(10, 10, std::make_pair(0, 0)), RType::ECS::WeaponHolder(), RType::ECS::State(), RType::ECS::EffectHandler()));
                break;
            case 4:
                swarm.emplace_back(std::make_shared<RType::Server::GameObjects::Enemy4>(RType::ECS::ID(id), RType::ECS::Position(2200, posY), RType::ECS::Acceleration(0, 0), RType::ECS::Health(100), RType::ECS::HitBox(10, 10, std::make_pair(0, 0)), RType::ECS::WeaponHolder(), RType::ECS::State(), RType::ECS::EffectHandler()));
                break;
        }
        ++id;
    }
    return (swarm);
}
