/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_CREATEROOMSCENE_HPP
#define RTYPE_CREATEROOMSCENE_HPP

#include "AScene.hpp"

namespace RType::Client {
    class Client;
    namespace Scene {
        class CreateRoomScene : public RType::ECS::Scene::AScene {
        public:
            explicit CreateRoomScene(std::shared_ptr<sf::RenderWindow> window, std::string myPseudo, RType::Client::Client *client) noexcept;
            ~CreateRoomScene() override = default;
            CreateRoomScene(const CreateRoomScene &other) noexcept = delete;
            explicit CreateRoomScene(CreateRoomScene &&other) noexcept = delete;
            CreateRoomScene &operator=(const CreateRoomScene &other) const noexcept = delete;
            CreateRoomScene &operator=(CreateRoomScene &&other) const noexcept = delete;
            void update(const AEvent &event) noexcept override;
            void addPlayer(std::string);
            void printPlayers(int startId);

        private:
            sf::Font _font;
            std::vector<std::string> _players;
            RType::Client::Client *_client;
        };
    }
}

#endif //RTYPE_CREATEROOMSCENE_HPP
