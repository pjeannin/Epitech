/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** RTYPE
*/


#ifndef __RTYPE_IROOM_HPP__
#define __RTYPE_IROOM_HPP__

#include <shared/Network/Requests.hpp>

class IRoom {
    public:
        virtual void unimplemented(RType::Network::RcvRequest const &, std::shared_ptr<RType::Server::User>) noexcept = 0;
        virtual void sendPlayerUpdate(RType::Network::RcvRequest const &, std::shared_ptr<RType::Server::User>) noexcept = 0;
        virtual void sendAmmoUpdate(RType::Network::RcvRequest const &, std::shared_ptr<RType::Server::User>) noexcept = 0;
};

#endif //__RTYPE_IROOM_HPP__
