/*
** EPITECH PROJECT, 2021
** asio
** File description:
** asio
*/


#ifndef __ASIO_USER_HPP__
#define __ASIO_USER_HPP__

#include "IUser.hpp"
#include "../server/database/Database.hpp"
#include "commandManager/CommandManager.hpp"

#include <memory>

class User : public IUser {
    public:
        explicit User(ITcpClient *tcpClient_, std::shared_ptr<Babel::CommandManager> commandManager_, std::shared_ptr<Babel::Server::Database> database_, std::shared_ptr<ArraySharedPtrT<IUser>> users_);

        ~User() override;
        void handleRcvBuffer() final;
        void close() final;
        void initializeConnection(Babel::Request const &) final;
        void signUp(Babel::Request const &) final;
        void signIn(Babel::Request const &) final;
        void sendFriendRequest(Babel::Request const &) final;
        void handleFriendRequestResponse(Babel::Request const &) final;
        void askFriendCalling(Babel::Request const &) final;
        void handleCallResponse(Babel::Request const &) final;
        void terminateCall(Babel::Request const &) final;
        void sendMessage(Babel::Request const &) final;
        void askMessageHistory(Babel::Request const &) final;
        void askFriendRequest(Babel::Request const &r) final;
        void askFriendList(Babel::Request const &) final;
        void send(uint8_t const ins, void *body = nullptr, std::size_t const bodySize = 0);
        void sendToAnotherWithUsername(std::string const &username, unsigned char const ins, void *body = nullptr, std::size_t const bodySize = 0) final;
        void sendToAnother(size_t const id, unsigned char const ins, void *body = nullptr, std::size_t const bodySize = 0) final;
        std::size_t getId() const final;
        void setId(std::size_t const id) final;
        std::string getIp() const final;
    private:
        std::size_t _id;
        ITcpClient *_socket;
        std::shared_ptr<Babel::CommandManager> _commandManager;
        std::shared_ptr<Babel::Server::Database> _database;
        std::shared_ptr<ArraySharedPtrT<IUser>> _users;
};

#endif //__ASIO_USER_HPP__
