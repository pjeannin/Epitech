/*
** EPITECH PROJECT, 2021
** asio
** File description:
** asio
*/


#ifndef __ASIO_TCPCLIENT_HPP__
#define __ASIO_TCPCLIENT_HPP__

#include "ITcpClient.hpp"
#include "include.hpp"

#include <asio.hpp>
#include <mutex>
#include <queue>

#define BUFFER_SIZE 1024

class TcpClient : public ITcpClient {
    public:
        explicit TcpClient(asio::ip::tcp::socket *socket_);
        ~TcpClient() override;

        void setSocketEvent(ITcpClient::SocketEvent *listener_) final;
        Babel::Request const &getRequest() final;
        void addToMessageQueue(Babel::Message const &msg) final;
        std::string const getIp() const final;
    private:
        void startToReceive();
        void close() noexcept;
        void sendMessageInQueue(std::error_code const &err, std::size_t const bytesTransfered);

        asio::ip::tcp::socket *_socket;
        Babel::Request _request;
        ITcpClient::SocketEvent *_listener;
        std::queue<Babel::Message> _msgs;
        std::mutex _m;
};

#endif //__ASIO_TCPCLIENT_HPP__
