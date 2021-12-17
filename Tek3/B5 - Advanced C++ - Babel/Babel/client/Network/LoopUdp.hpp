/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** LoopUdp.hpp
*/

#ifndef BABEL_LOOPUDP_HPP
#define BABEL_LOOPUDP_HPP

#include <QUdpSocket>
#include <QNetworkDatagram>
#include <string>
#include <vector>
#include <queue>
#include "IUdp.hpp"

namespace Babel::Client::Network {
    class LoopUdp : public QObject, public IUdp {
        Q_OBJECT
        public:

            explicit LoopUdp(qint16 port, QObject *parent = nullptr);
            ~LoopUdp() override;
            void sendDatas(QByteArray buffer, quint16 targetPort, const std::string &targetIP) override;
            void readDatas() override;
            void bind();
            IUdp::Datas *getDatas() override;
        private:
            QUdpSocket *_socket;
            qint16 _port;
            std::queue<QNetworkDatagram> _readedDatagrams;
    };
}


#endif //BABEL_LOOPUDP_HPP
