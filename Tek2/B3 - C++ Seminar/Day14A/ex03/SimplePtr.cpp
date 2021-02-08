/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD14A-pierre.jeannin
** File description:
** SimplePtr
*/

#include "SimplePtr.hpp"

SimplePtr::SimplePtr(BaseComponent *rawPtr) : _rawPtr(rawPtr)
{
}

SimplePtr::SimplePtr(SimplePtr const &ptr)
{
    delete _rawPtr;
}

SimplePtr::~SimplePtr()
{
}

SimplePtr &SimplePtr::operator=(SimplePtr const &ptr ) { }

BaseComponent *SimplePtr::get() const { return (_rawPtr); }