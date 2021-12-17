#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <math.h>
#include "../../interfaces/Drawables.hpp"
#include "../../interfaces/IGame.hpp"
#include "PacmanPlayer.hpp"
#include "Ghost.hpp"

#define DISTANCE(x1, y1, x2, y2) (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)))

struct Drawables {
    public:
        Drawables();
        Rect background;
        Text title;
        Text gameOver;
        Rect mapBackgroud;
        Text scoreText;
        Circle pacman;
        Circle ghost1;
        Circle ghost2;
        Circle ghost3;
        Circle ghost4;
};

class Pacman : public IGame {
    public:
        Pacman();
        ~Pacman();
        void event(Event const Event);
        void update(int elapsedTime);
        void render(IGraphicRender &renderer) const;
        const std::string getScore();
    private:
        void movePacman(int elapsedTime);
        void moveGhost(int elapsedTime);
        bool pacmanCanMove(Position &movement);
        bool ghostCanMove(Ghost *ghost, Position &movement);
        void drawMap(IGraphicRender &renderer) const;
        void readMap(const std::string &filePath);
        void setPacmanDefaultPosition();
        char findCell(Position pos);
        int pacmanCollidWithGhost();
        void removeGum(Position pos);
        const std::string &scoreToText() const;
        bool noMorePacgums();
        bool _gameOver;
        bool _ghostsOut;
        int _elapsedTime;
        std::string _map;
        std::string _baseMap;
        int _score;
        int _time;
        PacmanPlayer _pacman;
        Event _lastDirection;
        std::vector<Ghost *> _ghosts;
        Drawables _drawables;
        float _speedMultiplicator;
};