/*
** EPITECH PROJECT, 2021
** server
** File description:
** server
*/

#include "network/tcpServer/TcpServer.hpp"
#include "server/Server.hpp"

int main(int const argc, char const * const *argv)
{
    try {
        Server server(3001);
        server.run();
    } catch (std::exception const &e) {
        std::cout << e.what() << std::endl;
    }
}
