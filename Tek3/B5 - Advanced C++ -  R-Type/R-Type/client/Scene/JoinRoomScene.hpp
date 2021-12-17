/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_JOINROOMSCENE_HPP
#define RTYPE_JOINROOMSCENE_HPP

#include "AScene.hpp"
#include "client/Client.hpp"

namespace RType::Client {
    class Client;
    namespace Scene {
        class JoinRoomScene : public RType::ECS::Scene::AScene {
        public:
            explicit JoinRoomScene(std::shared_ptr<sf::RenderWindow> window, std::string myPseudo, RType::Client::Client *client) noexcept;
            ~JoinRoomScene() override = default;
            JoinRoomScene(const JoinRoomScene &other) noexcept = delete;
            explicit JoinRoomScene(JoinRoomScene &&other) noexcept = delete;
            JoinRoomScene &operator=(const JoinRoomScene &other) const noexcept = delete;
            JoinRoomScene &operator=(JoinRoomScene &&other) const noexcept = delete;
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

#endif //RTYPE_JOINROOMSCENE_HPP
