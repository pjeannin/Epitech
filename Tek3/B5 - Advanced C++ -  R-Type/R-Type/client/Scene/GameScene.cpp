/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "GameScene.hpp"
#include <utility>
#include <shared/ECS/Health.hpp>
#include <shared/ECS/Score.hpp>

RType::Client::Scene::GameScene::GameScene(const std::shared_ptr<sf::RenderWindow>& window, RType::Client::Client *client, const std::string &ip) noexcept : AScene((window)), _client(client), _window(window), _socket(std::make_shared<RType::Client::Network::SfmlUdpClient>(_client->getPort() + 1)),_ip(ip),
                                            _insCodeHandlers({{RType::Network::Udp::ActionCodes::SendPing, &GameScene::ping},
                                                              {RType::Network::Udp::ActionCodes::SendPlayerUpdate, &GameScene::playerUpdate},
                                                              {RType::Network::Udp::ActionCodes::SendEnemyUpdate, &GameScene::enemyUpdate},
                                                              {RType::Network::Udp::ActionCodes::SendAmmoUpdate, &GameScene::AmmoUpdate},
                                                              {RType::Network::Udp::ActionCodes::SendObjectUpdate, &GameScene::objectUpdate}}), _isFirstPlayerUpdate(true) {
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::GameParallax>(RType::ECS::ID(4), *_client->getDrawable(RType::Client::Client::Drawable::Parallax1), RType::ECS::Position(0, 0), RType::ECS::Acceleration(1, 0)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::GameParallax>(RType::ECS::ID(5),  *_client->getDrawable(RType::Client::Client::Drawable::Parallax2), RType::ECS::Position(0, 0), RType::ECS::Acceleration(2, 0)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::GameParallax>(RType::ECS::ID(6), *_client->getDrawable(RType::Client::Client::Drawable::Parallax3), RType::ECS::Position(0, 0), RType::ECS::Acceleration(4, 0)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::GameParallax>(RType::ECS::ID(7), *_client->getDrawable(RType::Client::Client::Drawable::Parallax4), RType::ECS::Position(0, 0), RType::ECS::Acceleration(0, 0)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Picture>(RType::ECS::ID(4), RType::ECS::SfmlDrawable(_window, "../../assets/pictures/infoFrame.png", std::make_pair(1920, 150), std::make_pair(1920, 150), std::make_pair(0, 0)), RType::ECS::Position(0, 0)));
    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Picture>(RType::ECS::ID(4), RType::ECS::SfmlDrawable(_window, "../../assets/pictures/infoFrame.png", std::make_pair(1920, 150), std::make_pair(1920, 150), std::make_pair(0, 0), std::make_pair(1, 1), 180), RType::ECS::Position(1920, 1080)));
//    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Bonus1>(RType::ECS::ID(5), RType::ECS::Position(0, 0), RType::ECS::SfmlDrawable(_window, "../../assets/sprites/health.png", std::make_pair(213, 217), std::make_pair(213, 217), std::make_pair(0, 0), std::make_pair(0.15, 0.15), 0)));
//    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Bonus2>(RType::ECS::ID(5), RType::ECS::Position(200, 0), RType::ECS::SfmlDrawable(_window, "../../assets/sprites/speed.png", std::make_pair(649, 223), std::make_pair(649, 223), std::make_pair(0, 0), std::make_pair(0.1, 0.1), 0)));
//    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Malus1>(RType::ECS::ID(5), RType::ECS::Position(400, 0), RType::ECS::SfmlDrawable(_window, "../../assets/sprites/slowdown.png", std::make_pair(204, 162), std::make_pair(204, 162), std::make_pair(0, 0), std::make_pair(0.2, 0.2), 0)));
//    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Enemy1>(RType::ECS::ID(5), RType::ECS::Position(0, 200), RType::ECS::Acceleration(2, 0), RType::ECS::SfmlDrawable(_window, "../../assets/sprites/ennemy1.png", std::make_pair(225, 285), std::make_pair(225, 285), std::make_pair(0, 0), std::make_pair(0.25, 0.25), 0)));
//    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Enemy2>(RType::ECS::ID(5), RType::ECS::Position(200, 200), RType::ECS::Acceleration(2, 0), RType::ECS::SfmlDrawable(_window, "../../assets/sprites/ennemy2.png", std::make_pair(283, 275), std::make_pair(283, 275), std::make_pair(0, 0), std::make_pair(0.285, 0.285), 0)));
//    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Enemy3>(RType::ECS::ID(5), RType::ECS::Position(400, 200), RType::ECS::Acceleration(2, 0), RType::ECS::SfmlDrawable(_window, "../../assets/sprites/ennemy3.png", std::make_pair(267, 237), std::make_pair(267, 237), std::make_pair(0, 0), std::make_pair(0.35, 0.35), 0)));
//    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Enemy4>(RType::ECS::ID(5), RType::ECS::Position(600, 200), RType::ECS::Acceleration(2, 0), RType::ECS::SfmlDrawable(_window, "../../assets/sprites/ennemy4.png", std::make_pair(220, 237), std::make_pair(220, 237), std::make_pair(0, 0), std::make_pair(0.35, 0.35), 0)));
//    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Player>(RType::ECS::ID(5), _window, RType::Network::Udp::PlayerID::Player1, RType::ECS::Position(0, 400), RType::ECS::Acceleration(0, 0), RType::ECS::Health(100), RType::ECS::Score(), RType::ECS::WeaponHolder(), false));
//    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Player>(RType::ECS::ID(5), _window, RType::Network::Udp::PlayerID::Player2, RType::ECS::Position(400, 400), RType::ECS::Acceleration(0, 0), RType::ECS::Health(100), RType::ECS::Score(), RType::ECS::WeaponHolder(), false));
//    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Player>(RType::ECS::ID(5), _window, RType::Network::Udp::PlayerID::Player3, RType::ECS::Position(800, 400), RType::ECS::Acceleration(0, 0), RType::ECS::Health(100), RType::ECS::Score(), RType::ECS::WeaponHolder(), false));
//    _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Player>(RType::ECS::ID(5), _window, RType::Network::Udp::PlayerID::Player4, RType::ECS::Position(1200, 400), RType::ECS::Acceleration(0, 0), RType::ECS::Health(100), RType::ECS::Score(), RType::ECS::WeaponHolder(), false));
}

void RType::Client::Scene::GameScene::updateServer() noexcept {
    std::optional<RType::Network::RcvRequest> rcvRequest = _socket->tryReceive();
    if (rcvRequest != std::nullopt) {
        if (_insCodeHandlers.find((*rcvRequest).code) != _insCodeHandlers.end())
            (this->*_insCodeHandlers[(*rcvRequest).code])(*rcvRequest);
        else
            DEBUG_PRINT("Invalid instruction code");
    }
}

void RType::Client::Scene::GameScene::update(const RType::AEvent &event) noexcept
{
    updateServer();
    ECS::Scene::AScene::update(event);
}

void RType::Client::Scene::GameScene::ping(RType::Network::RcvRequest &) noexcept {
    sendSuccessfulPing();
    DEBUG_PRINT("Ping received");
}

void RType::Client::Scene::GameScene::objectUpdate(RType::Network::RcvRequest &rcvRequest) noexcept {
    auto request = rcvRequest.getStructArgs<RType::Network::Udp::ObjectUpdate>();
    DEBUG_PRINT("Object update received");
    for (auto &gameObject: _gameObjects)
        if (dynamic_cast<RType::ECS::ID *>(gameObject.get())->getId() == request.id) {
            auto pos = dynamic_cast<RType::ECS::Position *>(gameObject.get());
            pos->setXPos(request.position.first);
            pos->setYPos(request.position.second);
            auto accel = dynamic_cast<RType::ECS::Acceleration *>(gameObject.get());
            accel->setXAcceleration(request.acceleration.first);
            accel->setYAcceleration(request.acceleration.second);
            return;
        }
    switch (request.objectType) {
        case RType::Network::Udp::ObjectType::Bonus1:
            _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Bonus1>(RType::ECS::ID(request.id), RType::ECS::Position(request.position.first, request.position.second), RType::ECS::SfmlDrawable(_window, "../../assets/sprites/speed.png", std::make_pair(649, 223), std::make_pair(649, 223), std::make_pair(0, 0), std::make_pair(1, 1), 0)));
            break;
        case RType::Network::Udp::ObjectType::Bonus2:
            _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Bonus2>(RType::ECS::ID(request.id), RType::ECS::Position(request.position.first, request.position.second), RType::ECS::SfmlDrawable(_window, "../../assets/sprites/health.png", std::make_pair(213, 217), std::make_pair(213, 217), std::make_pair(0, 0), std::make_pair(1, 1), 0)));
            break;
        case RType::Network::Udp::ObjectType::Bonus3:
            _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Bonus3>(RType::ECS::ID(request.id), RType::ECS::Position(request.position.first, request.position.second), RType::ECS::SfmlDrawable(_window, "../../assets/sprites/speed.png", std::make_pair(649, 223), std::make_pair(649, 223), std::make_pair(0, 0), std::make_pair(1, 1), 0)));
            break;
        case RType::Network::Udp::ObjectType::Malus1:
            _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Malus1>(RType::ECS::ID(request.id), RType::ECS::Position(request.position.first, request.position.second), RType::ECS::SfmlDrawable(_window, "../../assets/sprites/slowdown.png", std::make_pair(204, 162), std::make_pair(204, 162), std::make_pair(0, 0), std::make_pair(1, 1), 0)));
            break;
        case RType::Network::Udp::ObjectType::Malus2:
            _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Malus2>(RType::ECS::ID(request.id), RType::ECS::Position(request.position.first, request.position.second), RType::ECS::SfmlDrawable(_window, "../../assets/sprites/slowdown.png", std::make_pair(204, 162), std::make_pair(204, 162), std::make_pair(0, 0), std::make_pair(1, 1), 0)));
            break;
        case RType::Network::Udp::ObjectType::Malus3:
            _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Malus3>(RType::ECS::ID(request.id), RType::ECS::Position(request.position.first, request.position.second), RType::ECS::SfmlDrawable(_window, "../../assets/sprites/slowdown.png", std::make_pair(204, 162), std::make_pair(204, 162), std::make_pair(0, 0), std::make_pair(1, 1), 0)));
            break;
    }
    sendSuccessfulObjectUpdate();
}

void RType::Client::Scene::GameScene::playerUpdate(RType::Network::RcvRequest &rcvRequest) noexcept {
    auto request = rcvRequest.getStructArgs<RType::Network::Udp::PlayerUpdate>();
    std::shared_ptr<RType::Client::GameObjects::Player> player;
    for (auto &player_ : _players) {
        if (player_->getId() == request.id)
            player = player_;
    }
    if (player) {
        if (!player->isMe()) {
            player->setXPos(request.position.first);
            player->setYPos(request.position.second);
            DEBUG_PRINT("TA GRAND MERE LA PUTE  xpos " + std::to_string(request.position.first) + " ypos " + std::to_string(request.position.second));
            player->setXAcceleration(request.acceleration.first);
            player->setYAcceleration(request.acceleration.second);
        }
        player->setHealth(request.health);
        player->setScore(request.score);
    } else {
        if (_isFirstPlayerUpdate && _client->id == request.id) {
            player = std::make_shared<RType::Client::GameObjects::Player>(RType::ECS::ID(request.id), _window, request.id, RType::ECS::Position(request.position.first, request.position.second), RType::ECS::Acceleration(request.acceleration.first, request.acceleration.second), RType::ECS::Health(request.health), RType::ECS::Score(request.score), RType::ECS::WeaponHolder(), true);
            _isFirstPlayerUpdate = false;
        } else
            player = std::make_shared<RType::Client::GameObjects::Player>(RType::ECS::ID(request.id), _window, request.id, RType::ECS::Position(request.position.first, request.position.second), RType::ECS::Acceleration(request.acceleration.first, request.acceleration.second), RType::ECS::Health(request.health), RType::ECS::Score(request.score), RType::ECS::WeaponHolder(), false);
        _players.emplace_back(player);
        _gameObjects.emplace_back(player);

        _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Picture>(RType::ECS::ID(5), RType::ECS::SfmlDrawable(_window, "../../assets/pictures/heart.png", std::make_pair(200, 200), std::make_pair(200, 200), std::make_pair(0, 0), std::make_pair(0.2, 0.2)), RType::ECS::Position(120 * request.id * 2.5, 20)));
        _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Picture>(RType::ECS::ID(5), RType::ECS::SfmlDrawable(_window, "../../assets/pictures/heart.png", std::make_pair(200, 200), std::make_pair(200, 200), std::make_pair(0, 0), std::make_pair(0.2, 0.2)), RType::ECS::Position(120 * request.id * 2.5 + (50), 20)));
        _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Picture>(RType::ECS::ID(5), RType::ECS::SfmlDrawable(_window, "../../assets/pictures/heart.png", std::make_pair(200, 200), std::make_pair(200, 200), std::make_pair(0, 0), std::make_pair(0.2, 0.2)), RType::ECS::Position(120 * request.id * 2.5 + (100), 20)));
    }
    sendSuccessfulPlayerUpdate();
}

void RType::Client::Scene::GameScene::enemyUpdate(RType::Network::RcvRequest &rcvRequest) noexcept {
    auto request = rcvRequest.getStructArgs<RType::Network::Udp::EnemyUpdate>();
    DEBUG_PRINT("Enemy update received");
    for (int i = 0; i < _gameObjects.size(); ++i)
        if (dynamic_cast<RType::ECS::ID *>(_gameObjects[i].get())->getId() == request.id) {
            auto pos = dynamic_cast<RType::ECS::Position *>(_gameObjects[i].get());
            pos->setXPos(request.position.first);
            pos->setYPos(request.position.second);
            auto accel = dynamic_cast<RType::ECS::Acceleration *>(_gameObjects[i].get());
            accel->setXAcceleration(request.acceleration.first);
            accel->setYAcceleration(request.acceleration.second);
            if (pos->getXPos() <= -180)
                _gameObjects.erase(_gameObjects.begin() + i);
            return;
        }
    switch (request.enemyType) {
        case RType::Network::Udp::EnemyType::Enemy1:
            _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Enemy1>(RType::ECS::ID(request.id), RType::ECS::Position(request.position.first, request.position.second), RType::ECS::Acceleration(request.acceleration.first, request.acceleration.second), RType::ECS::SfmlDrawable(_window, "../../assets/sprites/ennemy1.png", std::make_pair(225, 285), std::make_pair(225, 285), std::make_pair(0, 0), std::make_pair(0.25, 0.25), 0)));
            break;
        case RType::Network::Udp::EnemyType::Enemy2:
            _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Enemy2>(RType::ECS::ID(request.id), RType::ECS::Position(request.position.first, request.position.second), RType::ECS::Acceleration(request.acceleration.first, request.acceleration.second), RType::ECS::SfmlDrawable(_window, "../../assets/sprites/ennemy2.png", std::make_pair(283, 275), std::make_pair(283, 275), std::make_pair(0, 0), std::make_pair(0.285, 0.285), 0)));
            break;
        case RType::Network::Udp::EnemyType::Enemy3:
            _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Enemy3>(RType::ECS::ID(request.id), RType::ECS::Position(request.position.first, request.position.second), RType::ECS::Acceleration(request.acceleration.first, request.acceleration.second), RType::ECS::SfmlDrawable(_window, "../../assets/sprites/ennemy3.png", std::make_pair(267, 237), std::make_pair(267, 237), std::make_pair(0, 0), std::make_pair(0.35, 0.35), 0)));
            break;
        case RType::Network::Udp::EnemyType::Enemy4:
            _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Enemy4>(RType::ECS::ID(request.id), RType::ECS::Position(request.position.first, request.position.second), RType::ECS::Acceleration(request.acceleration.first, request.acceleration.second), RType::ECS::SfmlDrawable(_window, "../../assets/sprites/ennemy4.png", std::make_pair(220, 237), std::make_pair(220, 237), std::make_pair(0, 0), std::make_pair(0.35, 0.35), 0)));
            break;
    }
    sendSuccessfulEnemyUpdate();
}

void RType::Client::Scene::GameScene::AmmoUpdate(RType::Network::RcvRequest &rcvRequest) noexcept {
    auto request = rcvRequest.getStructArgs<RType::Network::Udp::AmmoUpdate>();
    DEBUG_PRINT("Ammo update received");
    for (auto &gameObject: _gameObjects)
        if (dynamic_cast<RType::ECS::ID *>(gameObject.get())->getId() == request.id) {
            auto pos = dynamic_cast<RType::ECS::Position *>(gameObject.get());
            pos->setXPos(request.position.first);
            pos->setYPos(request.position.second);
            auto accel = dynamic_cast<RType::ECS::Acceleration *>(gameObject.get());
            accel->setXAcceleration(request.acceleration.first);
            accel->setYAcceleration(request.acceleration.second);
            return;
        }
    switch (request.ammoType) {
        case RType::Network::Udp::AmmoType::Ammo1:
            _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Ammo1>(RType::ECS::ID(request.id), RType::ECS::Position(request.position.first, request.position.second), RType::ECS::Acceleration(request.acceleration.first, request.acceleration.second), RType::ECS::SfmlDrawable(_window, "../../assets/sprites/r-typesheet1.gif", std::make_pair(26, 26), std::make_pair(532, 372), std::make_pair(156, 0), std::make_pair(1, 1), 0)));
            break;
        case RType::Network::Udp::AmmoType::Ammo2:
            _gameObjects.emplace_back(std::make_shared<RType::Client::GameObjects::Ammo2>(RType::ECS::ID(request.id), RType::ECS::Position(request.position.first, request.position.second), RType::ECS::Acceleration(request.acceleration.first, request.acceleration.second), RType::ECS::SfmlDrawable(_window, "../../assets/sprites/r-typesheet30a.gif", std::make_pair(34, 34), std::make_pair(102, 34), std::make_pair(0, 0), std::make_pair(1, 1), 0)));
            break;
    }
    sendSuccessfulAmmoUpdate();
}

void RType::Client::Scene::GameScene::sendSuccessfulPing() noexcept {
    RType::Network::Request<RType::Network::EmptyBody> request(RType::Network::Udp::SuccessCodes::SuccessfulPing);
    if (!_socket->send(&request, sizeof(request), _ip, UDP_PORT)) {
        DEBUG_PRINT("Fail to send SuccessfulPing");
    } else
        DEBUG_PRINT("SuccessfulPing sent");
}

void RType::Client::Scene::GameScene::sendSuccessfulPlayerUpdate() noexcept {
    RType::Network::Request<RType::Network::EmptyBody> request(RType::Network::Udp::SuccessCodes::SuccessfulPlayerUpdate);
    if (!_socket->send(&request, sizeof(request), _ip, UDP_PORT)) {
        DEBUG_PRINT("Fail to send SuccessfulPlayerUpdate");
    } else
        DEBUG_PRINT("SuccessfulPing sent");
}

void RType::Client::Scene::GameScene::sendSuccessfulEnemyUpdate() noexcept {
    RType::Network::Request<RType::Network::EmptyBody> request(RType::Network::Udp::SuccessCodes::SuccessfulEnemyUpdate);
    if (!_socket->send(&request, sizeof(request), _ip, UDP_PORT)) {
        DEBUG_PRINT("Fail to send SuccessfulEnemyUpdate");
    } else
        DEBUG_PRINT("SuccessfulEnemyUpdate sent");
}

void RType::Client::Scene::GameScene::sendSuccessfulAmmoUpdate() noexcept {
    RType::Network::Request<RType::Network::EmptyBody> request(RType::Network::Udp::SuccessCodes::SuccessfulAmmoUpdate);
    if (!_socket->send(&request, sizeof(request), _ip, UDP_PORT)) {
        DEBUG_PRINT("Fail to send SuccessfulAmmoUpdate");
    } else
        DEBUG_PRINT("SuccessfulAmmoUpdate sent");
}

void RType::Client::Scene::GameScene::sendSuccessfulObjectUpdate() noexcept {
    RType::Network::Request<RType::Network::EmptyBody> request(RType::Network::Udp::SuccessCodes::SuccessfulObjectUpdate);
    if (!_socket->send(&request, sizeof(request), _ip, UDP_PORT)) {
        DEBUG_PRINT("Fail to send SuccessfulObjectUpdate");
    } else
        DEBUG_PRINT("SuccessfulObjectUpdate sent");
}

void RType::Client::Scene::GameScene::sendPlayerUpdate(RType::Client::GameObjects::Player *player) noexcept {
    DEBUG_PRINT("xpos " + std::to_string(player->getXPos()) + " ypos " + std::to_string(player->getYPos()));
    RType::Network::Udp::PlayerUpdate playerUpdate(std::make_pair(player->getXPos(), player->getYPos()),
                                                   std::make_pair(player->getXAcceleration(), player->getYAcceleration()),
                                                   player->getHealth(), player->getScore(), static_cast<RType::Network::Udp::PlayerID>(player->getId()),
                                                   _client->getLobbyId());
    RType::Network::Request<RType::Network::Udp::PlayerUpdate> request(RType::Network::Udp::ActionCodes::SendPlayerUpdate, playerUpdate);
    if (!_socket->send(&request, sizeof(request), _ip, UDP_PORT)) {
//        DEBUG_PRINT("Fail to send PlayerUpdate");
    } else {}
//        DEBUG_PRINT("PlayerUpdate sent");
}

void RType::Client::Scene::GameScene::sendAmmoUpdate(RType::ECS::IGameObject *) noexcept {
    //TODO : implement ammo update
}
