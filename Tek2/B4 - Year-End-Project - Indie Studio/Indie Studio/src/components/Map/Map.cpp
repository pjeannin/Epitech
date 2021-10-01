/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Map
*/

#include "Map.hpp"

Map::Map() : _undestructible1("resources/3D/rock 3/rock 3.obj"), _textureUndestructible1("resources/3D/rock 3/rock 3.png"),
_undestructible2("resources/3D/rock 1/rock 1.obj"), _textureUndestructible2("resources/3D/rock 1/rock 1.png"),
_undestructible3("resources/3D/rock 2/rock 2.obj"), _textureUndestructible3("resources/3D/rock 2/rock 2.png"),
_destructible("resources/3D/box/box.obj"), _textureDestructible("resources/3D/box/box.png"), _whale("resources/3D/whale/whale.obj"),
_textureWhale("resources/3D/whale/whale.png"), _boatPink("resources/3D/boat/boat.obj"), _textureBoatPink("resources/3D/boat/boat_green.png"),
_boatDark("resources/3D/boat/boat.obj"), _textureBoatDark("resources/3D/boat/boat_yellow.png"),
_undestructible4("resources/3D/rock 4/rock 4.obj"), _textureUndestructible4("resources/3D/rock 4/rock 4.png")
{
    _undestructible1.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _textureUndestructible1;
    _undestructible2.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _textureUndestructible2;
    _undestructible3.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _textureUndestructible3;
    _undestructible4.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _textureUndestructible4;
    _destructible.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _textureDestructible;
    _whale.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _textureWhale;
    _boatPink.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _textureBoatPink;
    _boatDark.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _textureBoatDark;
    for (int i = -1; i != 170; i++)
        _rockChoose.push_back(rand() % 3);
    for (int i = 0; i != 170; i++)
        _randRotation.push_back(static_cast <float> (rand()) / static_cast <float> (100));
    _zAnim = 0;
    _anim = true;
    _tmp = raylib::Vector3 {0, 0, 0};
    _time1 = std::chrono::steady_clock::now();
}

std::vector<Cell *> Map::getGrid() const {return Grid;}

static Cell *findCell(std::vector<Cell *>Grid, const int x, const int y)
{
    for (auto & i : Grid) {
        if (i->getX() == x && i->getY() == y)
            return i;
    }
    return (nullptr);
}

static std::vector<Cell *>findNextPath(std::vector<Cell *>Grid, Cell *cell)
{
    std::vector<Cell *>next;
    const int x = cell->getX();
    const int y = cell->getY();

    if (x - 2 > 0) {
        auto new1 = findCell(Grid, x - 2, y);
        if (!new1->getVisited())
            next.push_back(new1);
    }
    if (x + 2 < 13) {
        auto new2 = findCell(Grid, x + 2, y);
        if (!new2->getVisited())
            next.push_back(new2);
    }

    if (y - 2 > 0) {
        auto new3 = findCell(Grid, x, y - 2);
        if (!new3->getVisited())
            next.push_back(new3);
    }
    if (y + 2 < 13) {
        auto new4 = findCell(Grid, x, y + 2);
        if (!new4->getVisited())
            next.push_back(new4);
    }
    return (next);
}

static void Connect(std::vector<Cell *>&Grid, Cell *cell, std::vector<Cell *>next)
{
    for (auto & i : next) {
        auto temp = i;
        if (temp->getX() != cell->getX()) {
            int x1 = temp->getX();
            int x2 = cell->getX();
            if (x1 > x2) {
                for (auto & index : Grid) {
                    if (index->getX() == x2 + 1 && index->getY() == temp->getY()) {
                        index->setType(' ');
                        break;
                    }
                }
            }
            if (x1 < x2) {
                for (auto & index : Grid) {
                    if (index->getX() == x2 - 1 && index->getY() == temp->getY()) {
                        index->setType(' ');
                        break;
                    }
                }
            }
        } else if (temp->getY() != cell->getY()) {
            int y1 = temp->getY();
            int y2 = cell->getY();
            if (y1 > y2) {
                for (auto & index : Grid) {
                    if (index->getX() == temp->getX() && index->getY() == y2 + 1) {
                        index->setType(' ');
                        break;
                    }
                }
            }
            if (y1 < y2) {
                for (auto & index : Grid) {
                    if (index->getX() == temp->getX() && index->getY() == y2 - 1) {
                        index->setType(' ');
                        break;
                    }
                }
            }
        }
        for (auto & index : Grid) {
            if (index->getX() == i->getX() && index->getY() == i->getY()) {
                index->setType(' ');
                break;
            }
        }
    }

}

static void populate(std::vector<Cell *>&Grid, int nb, char type, std::mt19937 mt)
{

    while (nb != 0) {
        auto rand = mt() % Grid.size();
        if (rand != 1 && rand != 2 && rand != 3  &&
            rand != 13 && rand != 26 && rand != 39  &&
            rand != 12* 2 && rand != 12 * 3 && rand != 12 * 4 &&
            rand != 11 && rand != 10 && rand != 9 &&
            rand != 13 * 11 && rand!= 13 * 10 && rand != 13 * 9 &&
            rand != 13 * 12 + 1 && rand != 13 * 12 + 2 && rand != 13 * 12 + 3 &&
            rand != 13 * 12 + 12 && rand != 13 * 11 + 12 && rand != 13 * 10 + 12 &&
            rand != 13 * 13 - 2 && rand != 13 * 13 - 3 && rand != 13 * 13 - 3 &&
            Grid.at(rand)->getType() == ' ') {
                Grid.at(rand)->setType(type);
            nb--;
        }
    }
}

void Map::print()
{
    int line = 0;
    for (auto & i : Grid) {
        if (line == 0)
            std::cout << '-';
        std::cout << i->getType();
        line++;
        if (line == 13) {
            std::cout << '-' << std::endl;
            line = 0;
        }
    }
}

void Map::drawBorder()
{
    for (float i = -1; i < 14; ++i) {
        if (_rockChoose.at(i+1) == 0) {
            _undestructible1.draw(raylib::Vector3(i, 0, -1), 1.0f, raylib::Color::White());
            _undestructible1.draw(raylib::Vector3(i, 0, 13), 1.0f, raylib::Color::White());
            _undestructible1.draw(raylib::Vector3(-1, 0, i), 1.0f, raylib::Color::White());
            _undestructible1.draw(raylib::Vector3(13, 0, i), 1.0f, raylib::Color::White());
        } else if (_rockChoose.at(i+1) == 1) {
            _undestructible2.draw(raylib::Vector3(i, 0, -1), 1.0f, raylib::Color::White());
            _undestructible2.draw(raylib::Vector3(i, 0, 13), 1.0f, raylib::Color::White());
            _undestructible2.draw(raylib::Vector3(-1, 0, i), 1.0f, raylib::Color::White());
            _undestructible2.draw(raylib::Vector3(13, 0, i), 1.0f, raylib::Color::White());
        } else if (_rockChoose.at(i+1) == 2){
            _undestructible3.draw(raylib::Vector3(i, 0, -1), 1.0f, raylib::Color::White());
            _undestructible3.draw(raylib::Vector3(i, 0, 13), 1.0f, raylib::Color::White());
            _undestructible3.draw(raylib::Vector3(-1, 0, i), 1.0f, raylib::Color::White());
            _undestructible3.draw(raylib::Vector3(13, 0, i), 1.0f, raylib::Color::White());
        }
    }
}

void Map::anim()
{
    std::chrono::steady_clock::time_point _time2 = std::chrono::steady_clock::now();

    if (std::chrono::duration_cast<std::chrono::milliseconds>(_time2 - _time1).count() > 100) {
        if (_zAnim <= -0.05)
            _anim = false;
        if (_zAnim >= 0)
            _anim = true;
        if (_anim)
            _zAnim -= 0.007;
        if (!_anim)
            _zAnim += 0.007;
        _time1 = _time2;
    }
    _tmp.y = _zAnim;
}

void Map::randDestructible()
{
    for (auto & i : Grid)
        if (i->getType() == 'O')
            i->setVectorY((rand() % 1000) / 1000);
}

void Map::drawMap()
{
    for (int i = 0; i < Grid.size(); ++i) {
        if (Grid.at(i)->getType() == 'X') {
            if (_rockChoose.at(i+1) == 0)
                _undestructible1.draw(Grid.at(i)->getVector(), 1.0f, raylib::Color::White());
            else if (_rockChoose.at(i+1) == 1)
                _undestructible2.draw(Grid.at(i)->getVector(), 1.0f, raylib::Color::White());
            else if (_rockChoose.at(i+1) == 2)
                _undestructible3.draw(Grid.at(i)->getVector(), 1.0f, raylib::Color::White());
        }
        if (Grid.at(i)->getType() == 'O') {
            _tmp = Grid.at(i)->getVector();
            anim();
            _destructible.draw(_tmp, raylib::Vector3 { 1.0f, 1.0f, 1.0f }, _randRotation.at(i+1), raylib::Vector3 { 1.0f, 1.0f, 1.0f }, raylib::Color::White());
        }
    }
}

void Map::drawDecorations()
{
    _boatPink.draw(raylib::Vector3(4, 0, 16), raylib::Vector3 { 0.0f, 1.0f, 0.0f }, 45, raylib::Vector3 { 1.0f, 1.0f, 1.0f }, raylib::Color::White());
    _boatDark.draw(raylib::Vector3(14, 0, -5), raylib::Vector3 { 0.0f, 1.0f, 0.0f }, 27, raylib::Vector3 { 1.0f, 1.0f, 1.0f }, raylib::Color::White());
    _whale.draw(raylib::Vector3(4, 0, -3), 1.0f, raylib::Color::White());
    _whale.draw(raylib::Vector3(14, 0, 20), 1.0f, raylib::Color::White());
    _undestructible4.draw(raylib::Vector3(11, 0, 15), 1.0f, raylib::Color::White());
    _undestructible2.draw(raylib::Vector3(5, 0, -2), 1.0f, raylib::Color::White());
    _undestructible4.draw(raylib::Vector3(15, 0, -9), 1.0f, raylib::Color::White());
    _undestructible3.draw(raylib::Vector3(1, 0, -4), 1.0f, raylib::Color::White());
    _undestructible1.draw(raylib::Vector3(14, 0, 18), 1.0f, raylib::Color::White());
    _undestructible1.draw(raylib::Vector3(16, 0, 3), 1.0f, raylib::Color::White());
    _undestructible1.draw(raylib::Vector3(9, 0, -7), 1.0f, raylib::Color::White());
    _undestructible2.draw(raylib::Vector3(1, 0, 16), 1.0f, raylib::Color::White());
    _undestructible3.draw(raylib::Vector3(-2, 0, 6), 1.0f, raylib::Color::White());
    _undestructible2.draw(raylib::Vector3(11, 0, -4), 1.0f, raylib::Color::White());
    _undestructible3.draw(raylib::Vector3(8, 0, 16), 1.0f, raylib::Color::White());
}

void Map::reset()
{
    if (!Grid.empty())
        Grid.clear();
    for (int y = 0; y < 13; y++) {
        for (int x = 0; x < 13; x++)  {
            Grid.push_back(new Cell(x, y, 'X', raylib::Vector3((float)x, 0, (float)y)));
        }
    }
}

void Map::DFSGenerator()
{
    std::stack<Cell *>pathStack;
    std::mt19937 mt(time(nullptr));

    reset();
    Grid.at(0)->setVisited(true);
    Grid.at(0)->setType(' ');
    pathStack.push(Grid.at(0));

    while (!pathStack.empty()) {
        auto cell = pathStack.top();
        pathStack.pop();

        auto next = findNextPath(Grid, cell);
        if (!next.empty()) {
            auto rand = mt() % next.size();
            for (int i = 0; i < next.size(); i++) {
                next.at(i)->setVisited(true);
                if (i != rand)
                pathStack.push(next.at(i));
            }
            pathStack.push(next.at(rand));
        }
        Connect(Grid, cell, next);
    }
    Grid.at(0)->setType('P');
    Grid.at(12)->setType('Q');
    Grid.at(13 * 12)->setType('R');
    Grid.at(13 * 13 - 1)->setType('S');
    populate(Grid, 50, 'O', mt);
}
