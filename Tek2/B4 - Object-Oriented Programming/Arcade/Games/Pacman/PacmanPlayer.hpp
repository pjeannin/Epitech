#include "../../interfaces/Drawables.hpp"

class PacmanPlayer {
    public:
        PacmanPlayer();
        ~PacmanPlayer();
        const Position &getPosition() const;
        void setPosition(const Position &pos);
        bool isSuper() const;
        void setSuper(bool isSuper);
        void move(Position movement);
        void addSuperTime(int elapsedTime);
    private:
        Position _pos;
        bool _isSuper;
        int _superTime;
};