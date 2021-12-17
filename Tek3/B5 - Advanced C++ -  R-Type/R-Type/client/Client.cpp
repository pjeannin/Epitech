/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "Client.hpp"
#include <utility>
#include <client/Scene/CreateRoomScene.hpp>
#include <client/Scene/JoinRoomScene.hpp>

RType::Client::Client::Client(std::string ipAddress) noexcept : _ipAddress(std::move(ipAddress)), _tcpHandler(std::make_shared<RType::Client::Network::SfmlTcpClient>()), _window(std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080), "R-type")),
                                                                _event(_window),
                                                                _backgroundMusic("../../assets/music/menu.ogg", _musicVolume),
                                                                _insCodeHandlers({{RType::Network::Tcp::SuccessCodes::SuccessfulConnection, &Client::successfulConnection},
                                                                                  {RType::Network::Tcp::SuccessCodes::SuccessfulLobbyCreation, &Client::successfulLobbyCreation},
                                                                                  {RType::Network::Tcp::SuccessCodes::SuccessfulJoining, &Client::successfulJoining},
                                                                                  {RType::Network::Tcp::SuccessCodes::SuccessfulReadySignal, &Client::successfulReadySignal},
                                                                                  {RType::Network::Tcp::SuccessCodes::SuccessfulStart, &Client::successfulStart},
                                                                                  {RType::Network::Tcp::FailureCodes::FailedConnection, &Client::failedConnection},
                                                                                  {RType::Network::Tcp::FailureCodes::FailedLobbyCreation, &Client::failedLobbyCreation},
                                                                                  {RType::Network::Tcp::FailureCodes::FailedListing, &Client::failedListing},
                                                                                  {RType::Network::Tcp::FailureCodes::FailedJoining, &Client::failedJoining},
                                                                                  {RType::Network::Tcp::FailureCodes::FailedReadySignal, &Client::failedReadySignal},
                                                                                  {RType::Network::Tcp::FailureCodes::FailedStart, &Client::failedStart},
                                                                                  {RType::Network::Tcp::ActionCodes::SomeoneJoinLobby, &Client::someoneJoinedTheLobby}}), _effectsVolume(100), _musicVolume(100),
                                                                                  _globalDrawable({{Drawable::Parallax1, std::make_shared<RType::ECS::SfmlDrawable>(_window, "../../assets/pictures/gameParallax/img1.png", std::make_pair<unsigned int, unsigned int>(3840, 1080), std::make_pair<unsigned int, unsigned int>(3840, 1080), std::make_pair<unsigned int, unsigned int>(0, 0), std::make_pair<float, float>(1, 1), 0)},
                                                                                                   {Drawable::Parallax2, std::make_shared<RType::ECS::SfmlDrawable>(_window, "../../assets/pictures/gameParallax/img4.png", std::make_pair<unsigned int, unsigned int>(3840, 1080), std::make_pair<unsigned int, unsigned int>(3840, 1080), std::make_pair<unsigned int, unsigned int>(0, 0), std::make_pair<float, float>(1, 1), 0)},
                                                                                                   {Drawable::Parallax3, std::make_shared<RType::ECS::SfmlDrawable>(_window, "../../assets/pictures/gameParallax/img2.png", std::make_pair<unsigned int, unsigned int>(3840, 1080), std::make_pair<unsigned int, unsigned int>(3840, 1080), std::make_pair<unsigned int, unsigned int>(0, 0), std::make_pair<float, float>(1, 1), 0)},
                                                                                                   {Drawable::Parallax4, std::make_shared<RType::ECS::SfmlDrawable>(_window, "../../assets/pictures/gameParallax/filter.png", std::make_pair<unsigned int, unsigned int>(3840, 1080), std::make_pair<unsigned int, unsigned int>(3840, 1080), std::make_pair<unsigned int, unsigned int>(0, 0), std::make_pair<float, float>(1, 1), 0)},
                                                                                                   {Drawable::Background, std::make_shared<RType::ECS::SfmlDrawable>(_window, "../../assets/pictures/main menu/background2.png", std::make_pair<unsigned int, unsigned int>(3840, 2160), std::make_pair<unsigned int, unsigned int>(3840, 2160), std::make_pair<unsigned int, unsigned int>(0, 0), std::make_pair<float, float>(0.5, 0.5))},
                                                                                                   {Drawable::GifTitle, std::make_shared<RType::ECS::SfmlDrawable>(_window, "../../assets/sprites/spritesheetTitle.png", std::make_pair<unsigned int, unsigned int>(800, 450), std::make_pair<unsigned int, unsigned int>(4800, 14400), std::make_pair<unsigned int, unsigned int>(0, 0), std::make_pair<float, float>(1, 1), 0)},
                                                                                                   {Drawable::GifWeapon, std::make_shared<RType::ECS::SfmlDrawable>(_window, "../../assets/sprites/spritesheet_gun.png", std::make_pair<unsigned int, unsigned int>(940, 580), std::make_pair<unsigned int, unsigned int>(4700, 13340), std::make_pair<unsigned int, unsigned int>(0, 0), std::make_pair<float, float>(0.7, 0.7), -60)}}),
                                                                                  _scene(std::make_shared<RType::Client::Scene::MainMenuScene>(_window, this))
{
    _backgroundMusic.play();
    if (!_tcpHandler->connect(_ipAddress, TCP_PORT)) {
        ERROR_PRINT("Connection failed");
        _window->close();
    }
    sendCreateConnection();
}

void RType::Client::Client::run() noexcept {
    while (_window->isOpen()) {
        std::optional<RType::Network::RcvRequest> request = _tcpHandler->tryReceive();
        if (request != std::nullopt) {
            if (_insCodeHandlers.find((*request).code) != _insCodeHandlers.end()) {
                (this->*_insCodeHandlers[(*request).code])(*request);
            } else
                ERROR_PRINT("Unknown instruction code");
        }
        _event.update();
        _window->clear();
        _scene->update(_event);
        _window->display();
        if (_scene->getNextScene())
            _scene = _scene->getNextScene();
    }
    _tcpHandler->disconnect();
}

void RType::Client::Client::sendCreateConnection() noexcept {
    RType::Network::Request<RType::Network::EmptyBody> request(RType::Network::Tcp::ActionCodes::CreateConnection);
    if (!_tcpHandler->send(&request, sizeof(request))) {
        DEBUG_PRINT("Fail to send CreateConnection");
    } else
        DEBUG_PRINT("CreateConnection sent");
}

void RType::Client::Client::sendCreateLobby(const std::string &lobbyName, const std::string &userName) noexcept {
    RType::Network::Request<RType::Network::Tcp::LobbyRequest> request(RType::Network::Tcp::ActionCodes::CreateLobby, userName, lobbyName);
    if (!_tcpHandler->send(&request, sizeof(request))) {
        DEBUG_PRINT("Fail to send CreateLobby");
    } else
        DEBUG_PRINT("CreateLobby sent");
}

void RType::Client::Client::sendJoinGame(const std::string &lobbyName, const std::string &userName) noexcept {
    RType::Network::Request<RType::Network::Tcp::LobbyRequest> request(RType::Network::Tcp::ActionCodes::JoinAGame, userName, lobbyName);
    if (!_tcpHandler->send(&request, sizeof(request))) {
        DEBUG_PRINT("Fail to send JoinGame");
    } else
        DEBUG_PRINT("JoinGame sent");
}

void RType::Client::Client::sendReadySignal() noexcept {
    RType::Network::Request<RType::Network::EmptyBody> request(RType::Network::Tcp::ActionCodes::ReadySignal);
    if (!_tcpHandler->send(&request, sizeof(request))) {
        DEBUG_PRINT("Fail to send ReadySignal");
    } else
        DEBUG_PRINT("ReadySignal sent");
}

void RType::Client::Client::sendStartSignal() noexcept {
    RType::Network::Request<RType::Network::EmptyBody> request(RType::Network::Tcp::ActionCodes::StartSignal);
    if (!_tcpHandler->send(&request, sizeof(request))) {
        DEBUG_PRINT("Fail to send StartSignal");
    } else
        DEBUG_PRINT("StartSignal sent");
}

void RType::Client::Client::successfulConnection(RType::Network::RcvRequest &) noexcept {
    DEBUG_PRINT("Connection successful");
}

void RType::Client::Client::successfulLobbyCreation(RType::Network::RcvRequest &request) noexcept {
    auto body = request.getStructArgs<RType::Network::OnlyIdRequest>();
    _lobbyId = body.id;
    id = body.playerId;
    DEBUG_PRINT("Lobby created");
}

void RType::Client::Client::successfulJoining(RType::Network::RcvRequest &request) noexcept {
    auto body = request.getStructArgs<RType::Network::Tcp::ListPlayerRequest>();
    DEBUG_PRINT("Successful joining");
    bool create = true;
    void *scene = dynamic_cast<RType::Client::Scene::CreateRoomScene *>(_scene.get());
    if (!scene) {
        create = false;
        scene = dynamic_cast<RType::Client::Scene::JoinRoomScene *>(_scene.get());
    }
    _lobbyId = body.id;
    id = body.playerId;
    for (auto &i : body.listPlayer) {
        if (*i && i != _username) {
            DEBUG_PRINT(std::string(i) + " in the game");
            (create ? ((RType::Client::Scene::CreateRoomScene *)scene)->addPlayer(i) : ((RType::Client::Scene::JoinRoomScene *)scene)->addPlayer(i));
        }
    }
    (create ? ((RType::Client::Scene::CreateRoomScene *)scene)->printPlayers(44) : ((RType::Client::Scene::JoinRoomScene *)scene)->printPlayers(44));
}

void RType::Client::Client::successfulReadySignal(RType::Network::RcvRequest &) noexcept {
    DEBUG_PRINT("Successful ReadySignal");
}

void RType::Client::Client::successfulStart(RType::Network::RcvRequest &) noexcept {
    DEBUG_PRINT("Successful Start");
    _scene->setNextScene(std::make_shared<RType::Client::Scene::GameScene>(_window, this, _ipAddress));
}

void RType::Client::Client::failedConnection(RType::Network::RcvRequest &) noexcept {
    DEBUG_PRINT("Connection failed");
}

void RType::Client::Client::failedLobbyCreation(RType::Network::RcvRequest &) noexcept {
    DEBUG_PRINT("Lobby creation failed");
}

void RType::Client::Client::failedListing(RType::Network::RcvRequest &) noexcept {
    DEBUG_PRINT("Listing failed");
}

void RType::Client::Client::failedJoining(RType::Network::RcvRequest &) noexcept {
    DEBUG_PRINT("Joining failed");
}

void RType::Client::Client::failedReadySignal(RType::Network::RcvRequest &) noexcept {
    DEBUG_PRINT("ReadySignal failed");
}

void RType::Client::Client::failedStart(RType::Network::RcvRequest &) noexcept {
    DEBUG_PRINT("Start failed");
}

void RType::Client::Client::setEffectVolume(float volume) noexcept { _effectsVolume = volume; }

void RType::Client::Client::setMusicVolume(float volume) noexcept {
    _musicVolume = volume;
    _backgroundMusic.setVolume(_musicVolume);
}

void RType::Client::Client::someoneJoinedTheLobby(RType::Network::RcvRequest &request) noexcept {
    auto body = request.getStructArgs<RType::Network::Tcp::OnlyUsernameBody>();
    DEBUG_PRINT(std::string(body.username) + " joined the lobby");
    bool create = true;
    void *scene = dynamic_cast<RType::Client::Scene::CreateRoomScene *>(_scene.get());
    if (!scene) {
        create = false;
        scene = dynamic_cast<RType::Client::Scene::JoinRoomScene *>(_scene.get());
    }
    (create ? ((RType::Client::Scene::CreateRoomScene *)scene)->addPlayer(body.username) : ((RType::Client::Scene::JoinRoomScene *)scene)->addPlayer(body.username));
    (create ? ((RType::Client::Scene::CreateRoomScene *)scene)->printPlayers(44) : ((RType::Client::Scene::JoinRoomScene *)scene)->printPlayers(44));
}

float RType::Client::Client::getEffectVolume() const noexcept { return _effectsVolume; }

float RType::Client::Client::getMusicVolume() const noexcept { return _musicVolume; }

const std::string &RType::Client::Client::getUsername() const noexcept { return _username; }

uint32_t RType::Client::Client::getLobbyId() const noexcept { return _lobbyId; }

uint16_t RType::Client::Client::getPort() const noexcept
{
    return _tcpHandler->getPort();
}

void RType::Client::Client::setUsername(const std::string &pseudo) noexcept { _username = pseudo; }

std::shared_ptr<RType::ECS::SfmlDrawable> RType::Client::Client::getDrawable(RType::Client::Client::Drawable drawable) noexcept {
    return _globalDrawable[drawable];
}
