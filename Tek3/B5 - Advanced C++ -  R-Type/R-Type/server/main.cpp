/*
** EPITECH PROJECT, 2021
** B-CPP-501-STG-5-1-rtype-antony.fantapie
** File description:
** Project File
*/

#include "Server.hpp"

int main()
{
    auto server = std::make_shared<RType::Server::Server>();
    server->initializeTcpUdp();
    server->run();
    return (0);
}
