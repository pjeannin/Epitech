/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** IUdp.hpp
*/

#ifndef BABEL_IUDP_HPP
#define BABEL_IUDP_HPP

#include <QObject>

#include <string>

namespace Babel::Client::Network {
    class IUdp {
        public:
            struct Packet {
                int32_t magicCode;
                time_t timestamp;
                uint16_t datas[480];
            };
            struct Datas {
                QByteArray datas;
                std::string host;
                unsigned short port;
            };
            ~IUdp() = default;
            virtual void sendDatas(QByteArray buffer,  quint16 targetPort, const std::string& targetIP) = 0;
            virtual void readDatas() = 0;
            virtual Datas *getDatas() = 0;
    };
}

#endif //BABEL_UDP_HPP