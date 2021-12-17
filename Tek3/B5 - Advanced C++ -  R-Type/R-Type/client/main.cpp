/*
** EPITECH PROJECT, 2021
** B-CPP-501-STG-5-1-rtype-antony.fantapie
** File description:
** Project File
*/

#include <iostream>
#include "Client.hpp"

bool usage(int ac, char **av)
{
    if (ac == 2 && std::string(av[1]) == "-h") {
        ERROR_PRINT("Usage: ./rtype-client <ip>");
        return (true);
    }
    return (false);
}

bool argsHandling(int ac, char **av) {
    if (ac == 2) {
        std::string ip = av[1];
        unsigned char nbDot = 0;
        if (ip.size() > 15) {
            ERROR_PRINT("Invalid ip");
            return (false);
        }
        for (size_t i = 0; i < ip.size(); ++i) {
            if (ip[i] < '0' || ip[i] > '9') {
                if (ip[i] == '.' && (i > 0 && ip[i - 1] != '.'))
                    ++nbDot;
                else {
                    ERROR_PRINT("Invalid ip");
                    return (false);
                }
            }
        }
        if (nbDot != 3 || ip[0] == '.' || ip[ip.size() - 1] == '.') {
            ERROR_PRINT("Invalid ip");
            return (false);
        }
        return (true);
    }
    ERROR_PRINT("Invalid args");
    return (false);
}

int main(int ac, char **av)
{
    if (usage(ac, av))
        return (0);
    else if (!argsHandling(ac, av))
        return (84);
    RType::Client::Client client(av[1]);
    client.run();
    return (0);
}