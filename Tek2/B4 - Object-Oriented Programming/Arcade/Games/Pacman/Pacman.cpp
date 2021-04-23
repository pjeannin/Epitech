/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-pierre.jeannin
** File description:
** Pacman
*/

#include "Pacman.hpp"


Drawables::Drawables() : title(Text("title")), gameOver(Text("Game Over !")), scoreText(Text("socre"))
{
}

Pacman::Pacman() : _gameOver(false), _ghostsOut(false), _elapsedTime(0), _map(""), _score(0), _time(0), _lastDirection(Event::unknown), _speedMultiplicator(1)
{
    readMap("assets/PacmanMap.txt");
    for (int i = 0; i < 4; i++)
        _ghosts.push_back(new Ghost);
    _ghosts[0]->setColor(Color(255, 128, 0, 255));
    _ghosts[1]->setColor(Color(15, 186, 216, 255));
    _ghosts[2]->setColor(Color(253, 145, 181, 255));
    _ghosts[3]->setColor(Color::Red());
    setPacmanDefaultPosition();
    _drawables.background = Rect(Position(0,0), Size(100, 100), Color(33, 75, 143, 255));
    _drawables.title = Text("Pacman", Position(30, 0), Size(70, 0), Color::Black());
    _drawables.mapBackgroud = Rect(Position(27.5, 17), Size(45, 80), Color::Blue());
    _drawables.gameOver = Text("Game Over !", Position(10, 40), Size(130, 0), Color::Black());
    _drawables.scoreText = Text("Score :", Position(77, 30), Size(30, 0), Color::Black());
    _drawables.pacman = Circle(_pacman.getPosition(), 1, Color(255, 255, 0, 255));
    _drawables.ghost1 = Circle(_ghosts[0]->getPosition(), 0.7, _ghosts[0]->getColor());
    _drawables.ghost2 = Circle(_ghosts[1]->getPosition(), 0.7, _ghosts[1]->getColor());
    _drawables.ghost3 = Circle(_ghosts[2]->getPosition(), 0.7, _ghosts[2]->getColor());
    _drawables.ghost4 = Circle(_ghosts[3]->getPosition(), 0.7, _ghosts[3]->getColor());
    srand(time(NULL));
}

Pacman::~Pacman()
{
}

void Pacman::setPacmanDefaultPosition()
{
    float xPos = 28;
    float yPos = 14;
    float baseXPos = 28;

    for (int i = 0; _map[i]; ++i) {
        if (_map[i] == '\n') {
            yPos += 4.1;
            xPos = baseXPos;
        } else {
            switch (_map[i])
            {
            case 'P':
                _pacman.setPosition(Position(xPos + 1.2, yPos + 2.1));
                break;
            case '1':
                _ghosts[0]->setPosition(Position(xPos + 1.2, yPos + 2.1));
                _ghosts[0]->setBasePosition(Position(xPos + 1.2, yPos + 2.1));
                break;
            case '2':
                _ghosts[1]->setPosition(Position(xPos + 1.2, yPos + 2.1));
                _ghosts[1]->setBasePosition(Position(xPos + 1.2, yPos + 2.1));
                break;
            case '3':
                _ghosts[2]->setPosition(Position(xPos + 1.2, yPos + 2.1));
                _ghosts[2]->setBasePosition(Position(xPos + 1.2, yPos + 2.1));
                break;
            case '4':
                _ghosts[3]->setPosition(Position(xPos + 1.2, yPos + 2.1));
                _ghosts[3]->setBasePosition(Position(xPos + 1.2, yPos + 2.1));
                break;
            default:
                break;
            }
            xPos += 2.3;
        }
    }
}

void Pacman::readMap(const std::string &filePath)
{
    std::ifstream file(filePath, std::ios::in);
    std::string line;

    while (getline(file, line))
        _map += "\n" + line;

    _baseMap = _map;
}

void Pacman::event(Event const event)
{
    if (event == Event::left || event == Event::right
    || event == Event::up || event == Event::down)
        _lastDirection = event;
}

char Pacman::findCell(Position pos)
{
    float xPos = 28;
    float yPos = 14;
    float baseXPos = 28;

    for (int i = 0; _map[i]; ++i) {
        if (_map[i] == '\n') {
            yPos += 4.1;
            xPos = baseXPos;
        } else {
            if (pos.x > xPos && pos.x <= xPos + 2.3 && pos.y > yPos && pos.y <= yPos + 4.1) {
                return _map[i];
            }
            xPos += 2.3;
        }
    }
    return (0);
}

bool Pacman::pacmanCanMove(Position &movement)
{
    if (movement.x == 0 && movement.y == 0)
        return false;
    if (findCell(Position(_pacman.getPosition().x + movement.x, _pacman.getPosition().y + movement.y)) == 'O') {
        _lastDirection = Event::unknown;
        return false;
    }
    return true;
}

bool Pacman::ghostCanMove(Ghost *ghost, Position &movement)
{
    if (movement.x == 0 && movement.y == 0)
        return false;
    if (findCell(Position(ghost->getPosition().x + movement.x, ghost->getPosition().y + movement.y)) == 'O') {
        ghost->setDirection(Ghost::Direction::unknown);
        return false;
    }
    return true;
}

void Pacman::moveGhost(int elapsedTime)
{
    for (unsigned int i = 0; i < _ghosts.size(); ++i) {
        Position movement(0, 0);
        if (_ghosts[i]->getElapsedTime() + elapsedTime > 1500) {
            _ghosts[i]->setElapsedTime(0);
            int direction = rand() % 4;
            switch (direction)
            {
            case 0:
                _ghosts[i]->setDirection(Ghost::Direction::up);
                break;
            case 1:
                _ghosts[i]->setDirection(Ghost::Direction::down);
                break;
            case 2:
                _ghosts[i]->setDirection(Ghost::Direction::left);
                break;
            case 3:
                _ghosts[i]->setDirection(Ghost::Direction::right);
                break;
            default:
                break;
            }
        }
        switch (_ghosts[i]->getDirection())
        {
        case Ghost::Direction::up:
            movement.y = (-elapsedTime) * 0.01 * (_pacman.isSuper() ? 0.5 : 1) * _speedMultiplicator;
            break;
        case Ghost::Direction::down:
            movement.y = elapsedTime * 0.01 * (_pacman.isSuper() ? 0.5 : 1) * _speedMultiplicator;
            break;
        case Ghost::Direction::left:
            movement.x = (-elapsedTime) * 0.006 * (_pacman.isSuper() ? 0.5 : 1) * _speedMultiplicator;
            break;
        case Ghost::Direction::right:
            movement.x = elapsedTime * 0.006 * (_pacman.isSuper() ? 0.5 : 1) * _speedMultiplicator;
            break;
        default:
            break;
        }
        if (ghostCanMove(_ghosts[i], movement))
            _ghosts[i]->move(movement);
        if (_ghosts[i]->getPosition().x < 28)
            _ghosts[i]->move(Position(43, 0));
        if (_ghosts[i]->getPosition().x > 71)
            _ghosts[i]->move(Position(-43, 0));
        _ghosts[i]->setElapsedTime(_ghosts[i]->getElapsedTime() + elapsedTime);
    }
}

int Pacman::pacmanCollidWithGhost()
{
    for (int i = 0; i < 4; ++i) {
        if (DISTANCE(_pacman.getPosition().x, _pacman.getPosition().y, _ghosts[i]->getPosition().x, _ghosts[i]->getPosition().y) < 1.5)
            return i;
    }
    return -1;
}

void Pacman::movePacman(int elapsedTime)
{
    Position movement(0, 0);

    switch (_lastDirection)
    {
    case Event::left:
        movement = Position((-elapsedTime) * 0.01, 0);
        break;
    case Event::right:
        movement = Position(elapsedTime * 0.01, 0);
        break;
    case Event::down:
        movement = Position(0, elapsedTime * 0.015);
        break;
    case Event::up:
        movement = Position(0, -elapsedTime * 0.015);
        break;
    default:
        break;
    }
    if (pacmanCanMove(movement))
        _pacman.move(movement);
    if (_pacman.getPosition().x < 28)
        _pacman.move(Position(43, 0));
    if (_pacman.getPosition().x > 71)
        _pacman.move(Position(-43, 0));
}

void Pacman::removeGum(Position pos)
{
    float xPos = 28;
    float yPos = 14;
    float baseXPos = 28;

    for (int i = 0; _map[i]; ++i) {
        if (_map[i] == '\n') {
            yPos += 4.1;
            xPos = baseXPos;
        } else {
            if (pos.x > xPos && pos.x <= xPos + 2.3 && pos.y > yPos && pos.y <= yPos + 4.1) {
                _map[i] = '-';
            }
            xPos += 2.3;
        }
    }
}

bool Pacman::noMorePacgums()
{
    for (int i = 0; _map[i]; ++i)
        if (_map[i] == 'g' || _map[i] == 'G')
            return false;
    return true;
}

void Pacman::update(int elapsedTime)
{
    int ghostIndex;

    moveGhost(elapsedTime);
    if (!_gameOver) {
        if (!_ghostsOut && _elapsedTime > 10000) {
            _ghostsOut = true;
            for (int i = 168; i < 168 + 5; ++i) {
                _map[i] = '-';
            }
        }
        _elapsedTime += elapsedTime;
        movePacman(elapsedTime);
        _drawables.pacman.pos = _pacman.getPosition();
        _drawables.ghost1.pos = _ghosts[0]->getPosition();
        _drawables.ghost2.pos = _ghosts[1]->getPosition();
        _drawables.ghost3.pos = _ghosts[2]->getPosition();
        _drawables.ghost4.pos = _ghosts[3]->getPosition();
        if ((ghostIndex = pacmanCollidWithGhost()) != -1) {
            if (_pacman.isSuper()) {
                _score += 100;
                _ghosts[ghostIndex]->reset();
            } else {
                _gameOver = true;
            }
        }
        if (findCell(_pacman.getPosition()) == 'g') {
            removeGum(_pacman.getPosition());
            _score += 10;
        } else if (findCell(_pacman.getPosition()) == 'G') {
            removeGum(_pacman.getPosition());
            _score += 50;
            _pacman.setSuper(true);
        }
        if (_pacman.isSuper()) {
            _pacman.addSuperTime(elapsedTime);
            _drawables.ghost1.color = Color(47, 52, 189, 255);
            _drawables.ghost2.color = Color(47, 52, 189, 255);
            _drawables.ghost3.color = Color(47, 52, 189, 255);
            _drawables.ghost4.color = Color(47, 52, 189, 255);
        } else {
            _drawables.ghost1.color = _ghosts[0]->getColor();
            _drawables.ghost2.color = _ghosts[1]->getColor();
            _drawables.ghost3.color = _ghosts[2]->getColor();
            _drawables.ghost4.color = _ghosts[3]->getColor();
        }
        if (noMorePacgums()) {
            _map = _baseMap;
            _ghostsOut = false;
            _elapsedTime = 0;
            _speedMultiplicator += 0.5;
        }
    }
}

void Pacman::render(IGraphicRender &renderer) const
{
    Text scoreValue(scoreToText(), Position(88, 30), Size(30, 0), Color::Black());

    renderer.drawRect(_drawables.background);
    renderer.drawRect(_drawables.mapBackgroud);
    renderer.drawText(_drawables.title);
    renderer.drawText(_drawables.scoreText);
    renderer.drawText(scoreValue);
    renderer.drawCircle(_drawables.ghost1);
    renderer.drawCircle(_drawables.ghost2);
    renderer.drawCircle(_drawables.ghost3);
    renderer.drawCircle(_drawables.ghost4);
    if (!_gameOver)
        renderer.drawCircle(_drawables.pacman);
    drawMap(renderer);
    if (_gameOver)
        renderer.drawText(_drawables.gameOver);
}

const std::string &Pacman::scoreToText() const
{
    std::string *text = (new std::string(std::to_string(_score)));

    while ((*text).length() < 5)
        *text = "0" + *text;

    return (*text);
}

void Pacman::drawMap(IGraphicRender &renderer) const
{
    float xPos = 28;
    float yPos = 14;
    float baseXPos = 28;

    for (int i = 0; _map[i]; ++i) {
        if (_map[i] == '\n') {
            yPos += 4.1;
            xPos = baseXPos;
        } else {
            if (_map[i] == 'O') {
                renderer.drawRect(Rect (Position(xPos, yPos), Size(2.4, 4.2), Color(1, 1, 140, 255)));
            } else if (_map[i] == 'g') {
                renderer.drawCircle(Circle (Position(xPos + 1.2, yPos + 2.1), 0.4, Color::Yellow()));
            } else if (_map[i] == 'G') {
                renderer.drawCircle(Circle (Position(xPos + 1.2, yPos + 2.1), 0.4, Color::Orange()));
            }
            xPos += 2.3;
        }
    }
}

const std::string Pacman::getScore()
{
    return (std::to_string(_score));
}

extern "C"
{
    Pacman *entry()
    {
        return new Pacman;
    }
}