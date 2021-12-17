/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** Buy Airpods
*/

#ifndef BABEL_REQUESTS_HPP
#define BABEL_REQUESTS_HPP

#include <optional>
#include <variant>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <shared/utils/print.hpp>
#include <memory>

#define MAGIC_CODE (unsigned short)0xBABE

namespace RType::Network {
    struct IBody {};

    namespace Tcp {

        enum ActionCodes : unsigned short {
            CreateConnection = 100, CreateLobby = 101, ListPlayer = 102, JoinAGame = 103, ReadySignal = 104, StartSignal = 105, SomeoneJoinLobby = 106
        };

        enum SuccessCodes : unsigned short {
            SuccessfulConnection = 200, SuccessfulLobbyCreation = 201, SuccessfulListing = 202, SuccessfulJoining = 203, SuccessfulReadySignal = 204, SuccessfulStart = 205, SuccessfulSomeoneJoinLobby = 206
        };

        enum FailureCodes : unsigned short {
            FailedConnection = 400, FailedLobbyCreation = 401, FailedListing = 402, FailedJoining = 403, FailedReadySignal = 404, FailedStart = 405, FailedSomeoneJoinLobby = 406
        };

        using Username = char [32];
        using Lobbyname = char [32];

        struct OnlyUsernameBody : public IBody {
            explicit OnlyUsernameBody() noexcept {
                std::memset(username, 0, sizeof(Username));
            };
            explicit OnlyUsernameBody(const std::string &username) noexcept : username{0} { std::strncpy(this->username, username.c_str(), sizeof(Username)); };
            Username username;
        };

        struct LobbyRequest : public IBody {
            explicit LobbyRequest() noexcept {}
            explicit LobbyRequest(const std::string &username, const std::string &lobbyname) noexcept : username{0}, lobbyname{0} {
                std::strncpy(this->username, username.c_str(), sizeof(Username));
                std::strncpy(this->lobbyname, lobbyname.c_str(), sizeof(Lobbyname));
            }
            Username username;
            Lobbyname lobbyname;
        };

        struct ListPlayerRequest : public IBody {
            explicit ListPlayerRequest() noexcept {};
            explicit ListPlayerRequest(uint32_t id_, uint32_t playerId_, const std::string &lobbyname_, const std::vector<std::string> &usernameList) noexcept : id(id_), playerId(playerId_), lobbyname{0} {
                std::strncpy(this->lobbyname, lobbyname_.c_str(), sizeof(Lobbyname));
                for (unsigned int i = 0; i < usernameList.size(); ++i) {
                    std::strncpy(this->listPlayer[i], usernameList[i].c_str(), sizeof(Username));
                };
            }
            uint32_t id;
            uint32_t playerId;
            Lobbyname lobbyname;
            Username listPlayer[4]{};
        };

    }

    namespace Udp {
        enum ActionCodes : unsigned short {
            SendPing = 110, SendPlayerUpdate = 111, SendEnemyUpdate = 112, SendAmmoUpdate = 113, SendObjectUpdate = 114,
        };

        enum SuccessCodes : unsigned short {
            SuccessfulPing = 210, SuccessfulPlayerUpdate = 211, SuccessfulEnemyUpdate = 212, SuccessfulAmmoUpdate = 213, SuccessfulObjectUpdate = 214,
        };

        enum PlayerID : unsigned char {
            Player1 = 1, Player2 = 2, Player3 = 3, Player4 = 4,
        };

        enum EnemyType : unsigned char {
            Enemy1 = 1, Enemy2 = 2, Enemy3 = 3, Enemy4 = 4,
        };

        enum AmmoType : unsigned char {
            Ammo1 = 1, Ammo2 = 2,
        };

        enum ObjectType : unsigned char {
            Bonus1 = 1, Bonus2 = 2, Bonus3 = 3, Malus1 = 4, Malus2 = 5, Malus3 = 6,
        };

        struct PlayerUpdate : public IBody {
            explicit PlayerUpdate() noexcept {};
            explicit PlayerUpdate(std::pair<int, int> position, std::pair<int, int> acceleration, unsigned int health, unsigned int score, PlayerID id, uint32_t lobbyId) {
                this->position = position;
                this->acceleration = acceleration;
                this->health = health;
                this->score = score;
                this->id = id;
                this->lobbyId = lobbyId;
            }
            uint32_t lobbyId;
            std::pair<int, int> position;
            std::pair<int, int> acceleration;
            unsigned int health;
            unsigned int score;
            PlayerID id;
            unsigned char weaponType;
        };

        struct EnemyUpdate : public IBody {
            explicit EnemyUpdate() noexcept {};
            explicit EnemyUpdate(std::pair<int, int> position, std::pair<int, int> acceleration, EnemyType enemyType, unsigned char id, uint32_t lobbyId) {
                this->position = position;
                this->enemyType = enemyType;
                this->acceleration = acceleration;
                this->id = id;
                this->lobbyId = lobbyId;
            }
            uint32_t lobbyId;
            std::pair<int, int> position;
            std::pair<int, int> acceleration;
            unsigned char id;
            EnemyType enemyType;
        };

        struct AmmoUpdate : public IBody {
            explicit AmmoUpdate() noexcept {};
            explicit AmmoUpdate(std::pair<int, int> position, std::pair<int, int> acceleration, AmmoType AmmoType, unsigned char senderId, unsigned char id) {
                this->position = position;
                this->acceleration = acceleration;
                this->senderId = senderId;
                this->id = id;
                this->ammoType = AmmoType;
            }
            uint32_t lobbyId;
            std::pair<int, int> position;
            std::pair<int, int> acceleration;
            unsigned char senderId;
            unsigned char id;
            AmmoType ammoType;
        };

        struct ObjectUpdate : public IBody {
            explicit ObjectUpdate() noexcept {};
            explicit ObjectUpdate(std::pair<int, int> position, std::pair<int, int> acceleration, unsigned char id, ObjectType objectType, uint32_t lobbyId) {
                this->position = position;
                this->acceleration = acceleration;
                this->id = id;
                this->objectType = objectType;
                this->lobbyId = lobbyId;
            }
            uint32_t lobbyId;
            std::pair<int, int> position;
            std::pair<int, int> acceleration;
            unsigned char id;
            ObjectType objectType;
        };
    }

    using InsCodes = std::variant<Tcp::ActionCodes, Tcp::SuccessCodes, Tcp::FailureCodes, Udp::ActionCodes, Udp::SuccessCodes>;
    std::vector<unsigned short> const InsCodesVector {Tcp::CreateConnection, Tcp::CreateLobby, Tcp::ListPlayer, Tcp::JoinAGame, Tcp::ReadySignal, Tcp::StartSignal,
                                                       Tcp::SuccessfulConnection, Tcp::SuccessfulLobbyCreation, Tcp::SuccessfulListing, Tcp::SuccessfulJoining, Tcp::SuccessfulReadySignal, Tcp::SuccessfulStart,
                                                       Tcp::FailedConnection, Tcp::FailedLobbyCreation, Tcp::FailedListing, Tcp::FailedJoining, Tcp::FailedReadySignal, Tcp::FailedStart,
                                                       Udp::ActionCodes::SendPing, Udp::ActionCodes::SendAmmoUpdate, Udp::ActionCodes::SendEnemyUpdate, Udp::ActionCodes::SendObjectUpdate, Udp::ActionCodes::SendPlayerUpdate,
                                                       Udp::SuccessCodes::SuccessfulAmmoUpdate, Udp::SuccessCodes::SuccessfulEnemyUpdate, Udp::SuccessCodes::SuccessfulObjectUpdate, Udp::SuccessCodes::SuccessfulPing, Udp::SuccessCodes::SuccessfulPlayerUpdate};


    struct  Header {
        explicit Header(InsCodes const &insCode) noexcept;
        explicit Header(std::string const &buffer) noexcept;
        bool isValid();

        unsigned short magicCode;
        unsigned short code;
    };

    template<class T>
    concept C_Body = std::is_base_of<IBody, T>::value;

    struct EmptyBody : public IBody {
        explicit EmptyBody() noexcept = default;
    };

    struct OnlyIdRequest : public IBody {
        explicit OnlyIdRequest() noexcept = default;
        explicit OnlyIdRequest(uint32_t id_, uint32_t playerId_) noexcept : id(id_), playerId(playerId_) {}
        uint32_t id;
        uint32_t playerId;
    };

    struct ReceivedBody : public IBody {
        explicit ReceivedBody(std::string const &buffer) noexcept {
            if (!buffer.empty()) {
                //TODO use shared ptr
//                std::shared_ptr<char[]> body(new char[size_]);

                body = new char[buffer.size()];
                std::memcpy(body, buffer.c_str(), buffer.size());
            }
        }

        template<C_Body T>
        T getStructArgs() const {
            std::shared_ptr<T> data = std::make_shared<T>();
            std::memcpy(&(*data), body, sizeof(T));
            return *data;
        }

        void *body;
    };

    template<C_Body T_Body>
    struct Request : public Header, public T_Body {
        template<class ... T_args>
        explicit Request(InsCodes const insCode, T_args ... args) noexcept : Header(insCode), T_Body(args...) {}

        char *toBuffer() noexcept {
            std::shared_ptr<char[]> ptr(new char[sizeof(RType::Network::Request<T_Body>)]);
            std::memcpy(ptr.get(), this, sizeof(RType::Network::Request<T_Body>));
            return ptr.get();
        }
    };

    template<>
    struct Request<ReceivedBody> : public Header, public ReceivedBody {
        explicit Request(Header &header, std::string const &buffer) noexcept : Header(header), ReceivedBody(buffer) {}

        static std::optional<Request<ReceivedBody>> createFromBuffer(std::string const &buffer)
        {
            RType::Network::Header header(buffer);

            if (!header.isValid())
                return {};
            return Request<ReceivedBody>(header, (buffer.size() == sizeof(Header) ? "" : buffer.substr(sizeof(Header))));
        }
    };

    using RcvRequest = Request<ReceivedBody>;
}

#define HEADER_SIZE sizeof(RType::Network::Header)
#define BUFFER_SIZE 2048
#define TCP_PORT 4242
#define UDP_PORT 4242

#endif //BABEL_REQUESTS_HPP
