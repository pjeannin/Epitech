/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** RTYPE
*/


#ifndef __RTYPE_ASIOCLIENTSESSION_HPP__
#define __RTYPE_ASIOCLIENTSESSION_HPP__

#include "IClientSession.hpp"

#include <memory>
#include <asio.hpp>
#include <shared/Network/Requests.hpp>

namespace RType::Server::Network {
    class AsioClientSession : public RType::Server::Network::IClientSession {
        public:
            explicit AsioClientSession(asio::ip::tcp::socket &socket) noexcept;
            ~AsioClientSession() noexcept override;
            AsioClientSession(const AsioClientSession &other) noexcept = delete;
            AsioClientSession(AsioClientSession &&other) noexcept = delete;
            AsioClientSession &operator=(const AsioClientSession &other) noexcept = delete;
            AsioClientSession &operator=(AsioClientSession &&other) noexcept = delete;

            void close() noexcept;
            void setOnClose(std::function<void()> onClose_) noexcept final;
            void setHandleReceiveBufferCallback(handlerReceiveBufferCallbackT func) noexcept final;
            void send(void *data, uint32_t size) noexcept final;
            std::string const getIp() const noexcept final;
            EndPoint getEndpointInfos() const noexcept final;
        private:
            void startToReceive() noexcept;
            asio::ip::tcp::socket _tcpSocket;
            asio::ip::udp::endpoint _udpEndpoint;
            handlerReceiveBufferCallbackT  _handleReceiveBufferCallback;
            std::function<void()> _onClose;
    };
}

#endif //__RTYPE_ASIOCLIENTSESSION_HPP__
