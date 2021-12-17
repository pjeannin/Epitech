/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_GAMESCENE_HPP
#define RTYPE_GAMESCENE_HPP

#include "client/Client.hpp"
#include "client/Network/SfmlUdpClient.hpp"
#include "AScene.hpp"
#include "shared/utils/print.hpp"
#include "client/GameObjects/GameParallax.hpp"
#include "client/GameObjects/Picture.hpp"
#include "client/GameObjects/GameScene/Player.hpp"
#include "client/GameObjects/GameScene/Enemy1.hpp"
#include "client/GameObjects/GameScene/Enemy2.hpp"
#include "client/GameObjects/GameScene/Enemy3.hpp"
#include "client/GameObjects/GameScene/Enemy4.hpp"
#include "client/GameObjects/GameScene/Bonus1.hpp"
#include "client/GameObjects/GameScene/Bonus2.hpp"
#include "client/GameObjects/GameScene/Bonus3.hpp"
#include "client/GameObjects/GameScene/Malus1.hpp"
#include "client/GameObjects/GameScene/Malus2.hpp"
#include "client/GameObjects/GameScene/Malus3.hpp"
#include "client/GameObjects/GameScene/Ammo1.hpp"
#include "client/GameObjects/GameScene/Ammo2.hpp"

namespace RType::Client {
    namespace GameObjects {
        class Player;
    }

    class Client;
    namespace Scene {
        class GameScene : public RType::ECS::Scene::AScene {
        public:
            explicit GameScene(const std::shared_ptr<sf::RenderWindow>& window, RType::Client::Client *client,
                               const std::string &ip) noexcept;
            ~GameScene() override = default;
            GameScene(const GameScene &other) noexcept = delete;
            explicit GameScene(GameScene &&other) noexcept = delete;
            GameScene &operator=(const GameScene &other) const noexcept = delete;
            GameScene &operator=(GameScene &&other) const noexcept = delete;
            void update(const AEvent &event) noexcept override;

            void sendPlayerUpdate(RType::Client::GameObjects::Player *player) noexcept;
            void sendAmmoUpdate(RType::ECS::IGameObject *gameObject) noexcept;

        private:
            void sendSuccessfulPing() noexcept;
            void sendSuccessfulPlayerUpdate() noexcept;
            void sendSuccessfulEnemyUpdate() noexcept;
            void sendSuccessfulAmmoUpdate() noexcept;
            void sendSuccessfulObjectUpdate() noexcept;

            void ping(RType::Network::RcvRequest &request) noexcept;
            void playerUpdate(RType::Network::RcvRequest &request) noexcept;
            void enemyUpdate(RType::Network::RcvRequest &request) noexcept;
            void AmmoUpdate(RType::Network::RcvRequest &request) noexcept;
            void objectUpdate(RType::Network::RcvRequest &request) noexcept;
            using serverFunctions = void (GameScene::*)(RType::Network::RcvRequest &);
            void updateServer() noexcept;

            RType::Client::Client *_client;
            std::shared_ptr<sf::RenderWindow> _window;
            std::shared_ptr<Network::IUdp> _socket;
            std::string _ip;
            std::map<unsigned short, serverFunctions> _insCodeHandlers;
            bool _isFirstPlayerUpdate;
            std::vector<std::shared_ptr<RType::Client::GameObjects::Player>> _players;
        };
    }
}

#endif //RTYPE_GAMESCENE_HPP
