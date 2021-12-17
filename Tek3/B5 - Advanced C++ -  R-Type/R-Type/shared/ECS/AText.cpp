/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "AText.hpp"

RType::ECS::AText::AText(std::string text, unsigned short size) noexcept :
    _text(std::move(text)), _size(size)
{
}

RType::ECS::AText::AText(const RType::ECS::AText &other) noexcept : _text(other.getText()), _size(other.getSize()) { }

const std::string &RType::ECS::AText::getText() const noexcept { return _text; }

void RType::ECS::AText::setText(const std::string& newText) noexcept { _text = newText; }

unsigned short RType::ECS::AText::getSize() const noexcept { return _size; }
