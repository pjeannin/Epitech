/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** RTYPE
*/


#ifndef __RTYPE_IUSER_HPP__
#define __RTYPE_IUSER_HPP__

#include <shared/Network/Requests.hpp>

namespace RType::Server {
    class IUser {
        public:
            virtual void createConnection(RType::Network::RcvRequest const &r) noexcept = 0;
            virtual void createLobby(RType::Network::RcvRequest const &r) noexcept = 0;
            virtual void joinAGame(RType::Network::RcvRequest const &r) noexcept = 0;
            virtual void startSignal(RType::Network::RcvRequest const &r) noexcept = 0;
            virtual void readySignal(RType::Network::RcvRequest const &r) noexcept = 0;
            virtual void listPlayer(RType::Network::RcvRequest const &r) noexcept = 0;
   };
}
#endif //__RTYPE_IUSER_HPP__
