/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-pierre.jeannin
** File description:
** Nilbler
*/

#include "Nibbler.hpp"

Nibbler::Nibbler(): gameOver("GAME OVER")
{
    board.walls.size = Size((float)80, (float)80);
    board.walls.pos = Position(10, 10);
    board.walls.color = Color(Color::Blue());

    srand(1000);
    Rect head(Position(10 + 80 / 2, 10 + 80 / 2), Size(1, 1), Color(Color::Red()));
    Rect cell(Position(10 + 80 / 2 + 1, 10 + 80 / 2), Size(1, 1), Color(Color::Red()));
    snake.body.push_back(head);
    snake.body.push_back(cell);
    cell.pos.x += 1;
    snake.body.push_back(cell);
    cell.pos.x += 1;
    snake.body.push_back(cell);
    snake.dir = direction::nib_left;
    snake.alive = true;
    score = 0;
    gameOver.pos = Position(40, 50);
    gameOver.size = Size(40, 40);
    gameOver.color = Color(Color::Red());
    board.food.pos = Position(Position(rand() % (int)board.walls.size.x + board.walls.pos.x, rand() % (int)board.walls.size.y + board.walls.pos.y));
    board.food.size = Size(1, 1);
    board.food.color =  Color(Color::Green());
}

Nibbler::~Nibbler()
{
}

void Nibbler::update(int elapsedTime)
{
    _elapsedTime += elapsedTime;
    if (snake.alive == false || _elapsedTime < 75)
        return;

    _elapsedTime = 0;
    if (snake.body[0].pos == board.food.pos) {
        Rect n(Position(snake.body[snake.body.size() - 1].pos), Size(1, 1), Color::Red());

        if (snake.body[snake.body.size() - 1].pos.x - snake.body[snake.body.size() - 2].pos.x == 1)
            n.pos += Vector2f(0, 1);
        if (snake.body[snake.body.size() - 1].pos.x - snake.body[snake.body.size() - 2].pos.x == -1)
            n.pos += Vector2f(0, -1);
        if (snake.body[snake.body.size() - 1].pos.y - snake.body[snake.body.size() - 2].pos.y == 1)
            n.pos += Vector2f(-1, 0);
        if (snake.body[snake.body.size() - 1].pos.y - snake.body[snake.body.size() - 2].pos.y == -1)
            n.pos += Vector2f(11, 0);
        snake.body.push_back(n);
        score += 10;
        board.food.pos = Position(rand() % (int)board.walls.size.x + (int)board.walls.pos.x, rand() % (int)board.walls.size.y + (int)board.walls.pos.y);
    }

    for (unsigned int i = snake.body.size() - 1; i > 0; i--)
        snake.body[i].pos = snake.body[i - 1].pos;

    switch (snake.dir)
    {
        case direction::nib_up:
            snake.body[0].pos += Vector2f(0, -1);
            break;
        case direction::nib_down:
            snake.body[0].pos += Vector2f(0, 1);
            break;
        case direction::nib_left:
            snake.body[0].pos += Vector2f(-1, 0);
            break;
        case direction::nib_right:
            snake.body[0].pos += Vector2f(1, 0);
            break;
        default:
            snake.body[0].pos = snake.body[0].pos;
            break;
    }

    for (unsigned int i = 1; i < snake.body.size(); i++) {
        if (snake.body[0].pos == snake.body[i].pos)
            snake.alive = false;
    }

    for (int i = 0; i < board.walls.size.x; i++) {
        if (board.walls.pos.x + i == snake.body[0].pos.x && board.walls.pos.y == snake.body[0].pos.y)
            snake.alive = false;
        if (board.walls.pos.x + i == snake.body[0].pos.x && board.walls.pos.y + board.walls.size.y - 1 == snake.body[0].pos.y)
            snake.alive = false;
    }

    for (int i = 0; i < board.walls.size.y; i++) {
        if (board.walls.pos.x == snake.body[0].pos.x && board.walls.pos.y + i == snake.body[0].pos.y)
            snake.alive = false;
        if (board.walls.pos.x + board.walls.size.x - 1 == snake.body[0].pos.x && board.walls.pos.y + i == snake.body[0].pos.y)
            snake.alive = false;
    }
}

void Nibbler::event(Event const Event)
{
    switch (snake.dir)
    {
    case direction::nib_left:
        if (Event == Event::down)
            snake.dir = direction::nib_down;
        if (Event == Event::up)
            snake.dir = direction::nib_up;
        break;
    case direction::nib_right:
        if (Event == Event::down)
            snake.dir = direction::nib_down;
        if (Event == Event::up)
            snake.dir = direction::nib_up;
        break;
    case direction::nib_up:
        if (Event == Event::left)
            snake.dir = direction::nib_left;
        if (Event == Event::right)
            snake.dir = direction::nib_right;
        break;
    case direction::nib_down:
        if (Event == Event::left)
            snake.dir = direction::nib_left;
        if (Event == Event::right)
            snake.dir = direction::nib_right;
        break;
    default:
        return;
        break;
    }
}

void Nibbler::render(IGraphicRender &renderer) const
{
    renderer.drawRect(board.walls);

    if (snake.alive == false)
        renderer.drawText(gameOver);

    for (unsigned int i = 0; i < snake.body.size(); i++)
        renderer.drawRect(snake.body[i]);
    renderer.drawRect(board.food);
}

const std::string Nibbler::getScore() { return std::to_string(score); }

extern "C"
{
    Nibbler *entry()
    {
        return new Nibbler;
    }
}