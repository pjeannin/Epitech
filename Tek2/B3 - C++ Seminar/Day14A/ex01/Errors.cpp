/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD14A-pierre.jeannin
** File description:
** Errors
*/

#include "Errors.hpp"


NasaError::NasaError(std::string const &message, std::string const &component) : _message(message), _component(component)
{
}

NasaError::~NasaError() throw()
{
}

std::string const &NasaError::getComponent() const { return (_component); }

const char *NasaError::what() const throw() { return (_message.c_str()); }

MissionCriticalError::MissionCriticalError(std::string const &message, std::string const &component) : NasaError(message, component)
{
}

MissionCriticalError::~MissionCriticalError() throw()
{
}

LifeCriticalError::LifeCriticalError(std::string const &message, std::string const &component) : NasaError(message, component)
{
}

LifeCriticalError::~LifeCriticalError() throw()
{
}

UserError::UserError(std::string const &message, std::string const &component) : NasaError(message, component)
{
}

UserError::~UserError() throw()
{
}

CommunicationError::CommunicationError(std::string const &message) : NasaError(message, "CommunicationDevice")
{
}

CommunicationError::~CommunicationError() throw()
{
}