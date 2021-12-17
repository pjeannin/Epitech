#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "../../interfaces/Drawables.hpp"
#include "../../interfaces/IGame.hpp"

class Ghost {
    public:
        Ghost();
        ~Ghost();
        const Position &getPosition() const;
        void setPosition(const Position &pos);
        void setBasePosition(const Position &pos);
        bool isAlive() const;
        void setAlive(bool isAlive);
        void setColor(Color color);
        Color getColor() const;
        void move(Position movement);
        enum Direction { unknown, left, right, up, down };
        int getElapsedTime() const;
        void setElapsedTime(int elapsedTime);
        Direction getDirection() const;
        void setDirection(Direction direction);
        void reset();
    private:
        int _elapsedTime;
        Direction _direction;
        Color _color;
        Position _pos;
        Position _basePos;
        bool _isAlive;
        bool _canGoOut;
};