/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-pierre.jeannin
** File description:
** Sdl
*/

#include "Sdl.hpp"
#include <iostream>

Sdl::Sdl()
{
}

Sdl::~Sdl()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

bool Sdl::isOperational()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        return false;
    }
    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (_window == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        return false;
    }
    TTF_Init();
    if (!(_font = TTF_OpenFont("./assets/font.ttf", 250)))
        throw (Error("Can't load the font."));

    return true;
}

Event Sdl::handleEvent()
{
    while (SDL_PollEvent(&_events))
    {
        switch (_events.type)
        {
            case SDL_QUIT:
                return Event_e::quit;
                break;
            case SDL_KEYDOWN:
                switch (_events.key.keysym.sym)
                {
                case 8:
                    return _currentEvent = Event_e::quit;
                    break;
                case SDLK_LEFT:
                    return _currentEvent = Event_e::left;
                    break;
                case SDLK_RIGHT:
                    return _currentEvent = Event_e::right;
                    break;
                case SDLK_UP:
                    return _currentEvent = Event_e::up;
                    break;
                case SDLK_DOWN:
                    return _currentEvent = Event_e::down;
                    break;
                case SDLK_v:
                    return _currentEvent = Event_e::next_game;
                    break;
                case SDLK_c:
                    return _currentEvent = Event_e::prev_game;
                    break;
                case SDLK_x:
                    return _currentEvent = Event_e::next_graphic;
                    break;
                case SDLK_w:
                    return _currentEvent = Event_e::prev_graphic;
                    break;
                case SDLK_ESCAPE:
                    return _currentEvent = Event_e::menu;
                    break;
                case SDLK_r:
                    return _currentEvent = Event_e::restart;
                    break;
                case SDLK_RETURN:
                    return _currentEvent = Event_e::enter;
                    break;
                case SDLK_SPACE:
                    break;
                case SDLK_q:
                    return _currentEvent = Event_e::left;
                    break;
                case SDLK_d:
                    return _currentEvent = Event_e::right;
                    break;
                case SDLK_z:
                    return _currentEvent = Event_e::up;
                    break;
                case SDLK_s:
                    return _currentEvent = Event_e::down;
                    break;
                default:
                    break;
                }
            default:
                break;
        }
    }

    return Event_e::unknown;
}

bool Sdl::isKeyPressed()
{
    if (_currentEvent != -1)
        return true;
    return false;
}

void Sdl::drawRect(const Rect &rect)
{
    SDL_Rect rectangle{ (int)(rect.pos.x * WINDOW_WIDTH / 100), (int)(rect.pos.y * WINDOW_HEIGHT / 100), (int)(rect.size.x * WINDOW_WIDTH / 100), (int)(rect.size.y * WINDOW_HEIGHT / 100) };
    SDL_SetRenderDrawColor(_renderer, rect.color.red, rect.color.green, rect.color.blue, rect.color.alpha);
    SDL_RenderFillRect(_renderer, &rectangle);
}

void Sdl::drawCircle(const Circle &circle)
{
    Position pos { (circle.pos.x * WINDOW_WIDTH / 100), (circle.pos.y * WINDOW_HEIGHT / 100) };

    SDL_SetRenderDrawColor(_renderer, circle.color.red, circle.color.green, circle.color.blue, circle.color.alpha);
    for (int x = pos.x - circle.radius * WINDOW_WIDTH / 100; x < pos.x + circle.radius * WINDOW_WIDTH / 100; ++x) {
        for (int y = pos.y- circle.radius * WINDOW_WIDTH / 100; y < pos.y + circle.radius * WINDOW_WIDTH / 100; ++y) {
            if (DISTANCE(pos.x, pos.y, x, y) < circle.radius * WINDOW_WIDTH / 100)
                SDL_RenderDrawPoint(_renderer, x, y);
        }
    }
}

void Sdl::drawSprite(const Sprite &sprite)
{
    SDL_Surface *surface = IMG_Load(sprite.getTexturePath().c_str());
    SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dst { (int)(sprite.pos.x * WINDOW_WIDTH / 100), (int)(sprite.pos.y * WINDOW_HEIGHT / 100), (int)(sprite.size.x * WINDOW_WIDTH / 100), (int)(sprite.size.y * WINDOW_HEIGHT / 100) };
    SDL_RenderCopy(_renderer, texture, nullptr, &dst);
    SDL_DestroyTexture(texture);
}

void Sdl::drawText(const Text &text)
{
    SDL_Color color {text.color.red, text.color.green, text.color.blue, text.color.alpha};
    SDL_Surface *surface = TTF_RenderText_Solid(_font, text.getText().c_str(), color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);
    SDL_Rect rect { (int)(text.pos.x * WINDOW_WIDTH / 100), (int)(text.pos.y * WINDOW_HEIGHT / 100), (int)(text.size.x * text.getText().length()), (int)(text.size.x) * 2};
    SDL_RenderCopy(_renderer, texture, nullptr, &rect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void Sdl::refreshScreen()
{
    SDL_RenderPresent(_renderer);
}

void Sdl::clearScreen()
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 1);
    SDL_RenderClear(_renderer);
}

extern "C"
{
    Sdl *entry()
    {
        return new Sdl;
    }
}