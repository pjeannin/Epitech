/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** RTYPE
*/

#include "Requests.hpp"

#include <cstring>

static unsigned short getUint16FromInsCodes(RType::Network::InsCodes const &insCode)
{
    if (std::holds_alternative<RType::Network::Tcp::ActionCodes>(insCode))
        return std::get<RType::Network::Tcp::ActionCodes>(insCode);
    if (std::holds_alternative<RType::Network::Tcp::SuccessCodes>(insCode))
        return std::get<RType::Network::Tcp::SuccessCodes>(insCode);
    if (std::holds_alternative<RType::Network::Tcp::FailureCodes>(insCode))
        return std::get<RType::Network::Tcp::FailureCodes>(insCode);
    if (std::holds_alternative<RType::Network::Udp::ActionCodes>(insCode))
        return std::get<RType::Network::Udp::ActionCodes>(insCode);
    if (std::holds_alternative<RType::Network::Udp::SuccessCodes>(insCode))
        return std::get<RType::Network::Udp::SuccessCodes>(insCode);
    return 0;
}

RType::Network::Header::Header(InsCodes const &insCode) noexcept : magicCode(MAGIC_CODE), code(getUint16FromInsCodes(insCode)) {}

RType::Network::Header::Header(std::string const &buffer) noexcept
{
    std::memcpy(&magicCode, buffer.c_str(), sizeof(unsigned short));
    std::memcpy(&code, buffer.c_str() + sizeof(unsigned short), sizeof(unsigned short));
}

bool RType::Network::Header::isValid()
{
    return (magicCode == MAGIC_CODE && std::find(InsCodesVector.begin(),  InsCodesVector.end(), code) != InsCodesVector.end());
}



