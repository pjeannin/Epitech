/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_CLIENT_HPP
#define RTYPE_CLIENT_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "client/Scene/IScene.hpp"
#include "Network/SfmlTcpClient.hpp"
#include "shared/Event/SfmlEvent.hpp"
#include "client/ECS/SfmlMusic.hpp"
#include "client/Scene/MainMenuScene.hpp"
#include "client/Scene/GameScene.hpp"
#include "shared/utils/print.hpp"

namespace RType::Client {
    class Client {
        public:
            enum Drawable : unsigned char {
                Parallax1 = 0,
                Parallax2 = 1,
                Parallax3 = 2,
                Parallax4 = 3,
                Background = 4,
                GifTitle = 5,
                GifWeapon = 6
            };
            explicit Client(std::string ipAddress) noexcept;
            ~Client() noexcept = default;
            void run() noexcept;
            void setEffectVolume(float volume) noexcept;
            void setMusicVolume(float volume) noexcept;
            [[nodiscard]] float getEffectVolume() const noexcept;
            [[nodiscard]] float getMusicVolume() const noexcept;
            [[nodiscard]] const std::string &getUsername() const noexcept;
            void setUsername(const std::string &_pseudo) noexcept;
            [[nodiscard]] uint32_t getLobbyId() const noexcept;
            [[nodiscard]] std::shared_ptr<RType::ECS::SfmlDrawable> getDrawable(Drawable drawable) noexcept;
            void sendCreateLobby(const std::string &lobbyName, const std::string &userName) noexcept;
            void sendJoinGame(const std::string &lobbyName, const std::string &userName) noexcept;
            void sendReadySignal() noexcept;
            void sendStartSignal() noexcept;

            uint16_t getPort() const noexcept;
            uint32_t id;
        private:
            using serverFunctions = void (Client::*)(RType::Network::RcvRequest &);

            void sendCreateConnection() noexcept;

            void successfulConnection(RType::Network::RcvRequest &request) noexcept;
            void successfulLobbyCreation(RType::Network::RcvRequest &request) noexcept;
            void successfulJoining(RType::Network::RcvRequest &request) noexcept;
            void successfulReadySignal(RType::Network::RcvRequest &request) noexcept;
            void successfulStart(RType::Network::RcvRequest &request) noexcept;

            void failedConnection(RType::Network::RcvRequest &request) noexcept;
            void failedLobbyCreation(RType::Network::RcvRequest &request) noexcept;
            void failedListing(RType::Network::RcvRequest &request) noexcept;
            void failedJoining(RType::Network::RcvRequest &request) noexcept;
            void failedReadySignal(RType::Network::RcvRequest &request) noexcept;
            void failedStart(RType::Network::RcvRequest &request) noexcept;

            void someoneJoinedTheLobby(RType::Network::RcvRequest &request) noexcept;

            std::string _ipAddress;
            std::shared_ptr<RType::Client::Network::ITcp> _tcpHandler;
            std::shared_ptr<sf::RenderWindow> _window;
            RType::SfmlEvent _event;
            RType::ECS::SfmlMusic _backgroundMusic;
            std::map<unsigned short, serverFunctions> _insCodeHandlers;
            float _effectsVolume;
            float _musicVolume;
            std::string _username;
            uint32_t _lobbyId;
            std::map<Drawable, std::shared_ptr<RType::ECS::SfmlDrawable>> _globalDrawable;
            std::shared_ptr<RType::ECS::Scene::IScene> _scene;
    };
}

#endif //RTYPE_CLIENT_HPP
