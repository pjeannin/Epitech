/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD14M-pierre.jeannin
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size) : _size(size), _nbInside(0), _headNode(nullptr)
{
}

FruitBox::~FruitBox()
{
}

int FruitBox::nbFruits() const { return (_nbInside); }

bool FruitBox::putFruit(Fruit *fruit)
{
    FruitNode *tmp = _headNode;

    if (_nbInside == _size)
        return (false);
    if (_headNode == nullptr) {
        _headNode = new FruitNode(fruit);
        ++_nbInside;
        return (true);
    }
    while (tmp->next) {
        if (tmp->_content == fruit)
            return (false);
        tmp = tmp->next;
    }
    tmp->next = new FruitNode(fruit);
    ++_nbInside;

    return (true);
}

Fruit *FruitBox::pickFruit()
{
    Fruit *tmp;
    FruitNode *nodeTmp = _headNode;

    if (_nbInside == 0)
        return (nullptr);
    tmp = _headNode->_content;
    _headNode = _headNode->next;
    delete nodeTmp;
    --_nbInside;

    return (tmp);
}

FruitNode *FruitBox::head() { return (_headNode); }

FruitNode::FruitNode(Fruit *content) : _content(content), next(nullptr)
{
}

FruitNode::~FruitNode()
{
}
