/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** RTYPE
*/


#ifndef __RTYPE_ICLIENTSESSION_HPP__
#define __RTYPE_ICLIENTSESSION_HPP__

#include <functional>
#include <string>

namespace RType::Server::Network {
    using handlerReceiveBufferCallbackT = std::function<void(std::string const)>;
    using EndPoint = std::tuple<std::string const, uint16_t>;
    enum EndPointI : unsigned char { Ip = 0, Port = 1 };
    class IClientSession {
        public:
            virtual ~IClientSession() noexcept = default;
            virtual void setHandleReceiveBufferCallback(handlerReceiveBufferCallbackT func) noexcept = 0;
            virtual void setOnClose(std::function<void()> onClose_) noexcept = 0;
            virtual void send(void *data, uint32_t size) noexcept = 0;
            virtual std::string const getIp() const noexcept = 0;
            virtual EndPoint getEndpointInfos() const noexcept = 0;
        private:
    };
}

#endif //__RTYPE_ICLIENTSESSION_HPP__
