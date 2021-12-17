/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** ITcp.hpp
*/

#ifndef BABEL_ITCP_HPP
#define BABEL_ITCP_HPP

#include <QtNetwork>

namespace Babel::Client::Network {
    class ITcp {
            public:
                virtual ~ITcp() = default;
                virtual void Connect() = 0;
                virtual void WriteBytes(QByteArray datas) const = 0;
                virtual char *ReadSomething() const = 0;
                virtual bool getStatus() const = 0;
                virtual QByteArray const &getData() const = 0;
    };
}

#endif //BABEL_ITCP_HPP