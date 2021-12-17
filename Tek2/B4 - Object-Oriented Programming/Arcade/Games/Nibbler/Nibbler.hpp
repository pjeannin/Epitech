#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "../../interfaces/Drawables.hpp"
#include "../../interfaces/IGame.hpp"

enum direction {nib_up, nib_down, nib_left, nib_right};
struct Snake {

    std::vector<Rect> body;
    direction dir;
    bool alive;

};

struct Board {

    Rect walls;
    Rect food;
};

class Nibbler : public IGame {
    public:
        Nibbler();
        ~Nibbler();
        void event(Event const Event);
        void update(int elapsedTime);
        void render(IGraphicRender &renderer) const;
        const std::string getScore();
    private:
        int score;
        Snake snake;
        Board board;
        Text gameOver;
        int _elapsedTime;
};