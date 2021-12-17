/*
** EPITECH PROJECT, 2021
** asio
** File description:
** asio
*/


#ifndef __ASIO_IUSER_HPP__
#define __ASIO_IUSER_HPP__

#include "../network/tcpClient/ITcpClient.hpp"

class IUser : public ITcpClient::SocketEvent {
    public:
        virtual ~IUser() {};
        virtual void initializeConnection(Babel::Request const &) = 0;
        virtual void signUp(Babel::Request const &) = 0;
        virtual void signIn(Babel::Request const &) = 0;
        virtual void sendFriendRequest(Babel::Request const &) = 0;
        virtual void handleFriendRequestResponse(Babel::Request const &) = 0;
        virtual void askFriendCalling(Babel::Request const &) = 0;
        virtual void terminateCall(Babel::Request const &) = 0;
        virtual void sendMessage(Babel::Request const &) = 0;
        virtual void askMessageHistory(Babel::Request const &) = 0;
        virtual void askFriendRequest(Babel::Request const &r) = 0;
        virtual void askFriendList(Babel::Request const &) = 0;
        virtual void handleCallResponse(Babel::Request const &) = 0;
        virtual std::size_t getId() const = 0;
        virtual void setId(std::size_t const id) = 0;
        virtual void send(unsigned char const ins, void *body = nullptr, std::size_t const bodySize = 0) = 0;
        virtual void sendToAnotherWithUsername(std::string const &username, unsigned char const ins, void *body = nullptr, std::size_t const bodySize = 0) = 0;
        virtual void sendToAnother(size_t const id, unsigned char const ins, void *body = nullptr, std::size_t const bodySize = 0) = 0;
        virtual std::string getIp() const = 0;
    private:
};

#endif //__ASIO_IUSER_HPP__
