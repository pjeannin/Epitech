/*
** EPITECH PROJECT, 2021
** asio
** File description:
** asio
*/


#ifndef __ASIO_COMMANDMANAGER_HPP__
#define __ASIO_COMMANDMANAGER_HPP__

#include "server/user/IUser.hpp"

#include <map>

namespace Babel {
    class CommandManager {
        public:
            class Exception : std::exception {
                public:
                    explicit Exception(std::string const &msg);

                    char const *what() const noexcept;

                private:
                    std::string const _msg;
            };

            explicit CommandManager() noexcept;

            void handle(IUser *user, Babel::Request const &r);

        private:
            std::map<char, void (IUser::*)(Babel::Request const &)> _fct;
    };
}
#endif //__ASIO_COMMANDMANAGER_HPP__
