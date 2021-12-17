/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#ifndef RTYPE_SWARM_HPP
#define RTYPE_SWARM_HPP

#include "shared/ECS/IGameObject.hpp"
#include "server/GameObjects/Enemy1.hpp"
#include "server/GameObjects/Enemy2.hpp"
#include "server/GameObjects/Enemy3.hpp"
#include "server/GameObjects/Enemy4.hpp"
#include "server/GameObjects/Bonus1.hpp"
#include "server/GameObjects/Bonus2.hpp"
#include "server/GameObjects/Bonus3.hpp"
#include "server/GameObjects/Malus1.hpp"
#include "server/GameObjects/Malus2.hpp"
#include "server/GameObjects/Malus3.hpp"
#include "shared/ECS/State.hpp"
#include "shared/ECS/EffectHandler.hpp"
#include <vector>

namespace RType::ECS {
    class Swarm {
        public:
            explicit Swarm() noexcept;
            ~Swarm() = default;
            Swarm(const Swarm &other) noexcept = delete;
            explicit Swarm(Swarm &&other) noexcept = delete;
            Swarm &operator=(const Swarm &other) const noexcept = delete;
            Swarm &operator=(Swarm &&other) const noexcept = delete;
            std::vector<std::shared_ptr<RType::ECS::AEnemy>> genSwarm(int nb, int id);
            std::shared_ptr<RType::ECS::IGameObject> genBonuses(int posX, int posY, int id);
            std::shared_ptr<RType::ECS::IGameObject> genMaluses(int posX, int posY, int id);
        private:
            enum Ennemies {
                Enemy1 = 1,
                Enemy2 = 2,
                Enemy3 = 3,
                Enemy4 = 4,
                FINENNEMIES = 5
            };
            enum Bonuses {
                BONUS1 = 1,
                BONUS2 = 2,
                BONUS3 = 3,
                FINBONUSES = 4
            };
            enum Maluses {
                MALUS1 = 1,
                MALUS2 = 2,
                MALUS3 = 3,
                FINMALUSES = 4
            };
    };
}

#endif //RTYPE_SWARM_HPP
