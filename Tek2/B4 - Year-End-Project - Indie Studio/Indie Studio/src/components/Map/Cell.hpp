/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Cell
*/

#ifndef CELL_HPP_
#define CELL_HPP_

#include "../../../raylib-cpp/src/vector/Vector.hpp"
#include "../../../raylib-cpp/src/color/Color.hpp"
#include "../../../raylib-cpp/src/texture/Texture.hpp"
#include "../../../raylib-cpp/src/mesh/Mesh.hpp"
#include "../../../raylib-cpp/src/model/Model.hpp"
#include "../../../raylib-cpp/src/image/Image.hpp"

#define CUBESIZE raylib::Vector3(1.0f, 1.0f, 1.0f)
#define BORDERCOLOR raylib::Color::Black()
#define WALLCOLOR raylib::Color::Red()
#define DESTRUCTIBLE raylib::Color::Yellow()

class Cell {
    public:
        Cell(int x, int y, char type, raylib::Vector3 vector);
        ~Cell() = default;
        int getX() const;
        int getY() const;
        char getType() const;
        void setX(const int x);
        void setY(const int y);
        void setType(const char type);
        bool getVisited() const;
        void setVisited(const bool value);
        raylib::Vector3 getVector();
        void setVectorY(const float);
    protected:
    private:
        int _x;
        int _y;
        char _floorType;
        bool isVisited;
        raylib::Vector3 _vector;
};

#endif /* !CELL_HPP_ */
