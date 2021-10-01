/*
** EPITECH PROJECT, 2021
** Game
** File description:
** Game
*/

#ifndef __GAME__
#define __GAME__

#include "../IScene.hpp"
#include "../../../raylib-cpp/src/font/Font.hpp"
#include "../../../raylib-cpp/src/texture/Texture.hpp"
#include "../../../raylib-cpp/src/mesh/Mesh.hpp"
#include "../../core/Core.hpp"
#include "../../components/bomb/Bomb.hpp"
#include "../../components/boat/Boat.hpp"
#include "../../components/Map/Map.hpp"
#include "../../components/image/Image.hpp"
#include "../../components/button/Button.hpp"
#include"../../scene/menu/Menu.hpp"
#include "../../../include/Include.hpp"
#include "../../components/transition/fade/Fade.hpp"

#include <string>
#include <chrono>
#include <functional>
#include <map>

class Game : public IScene {
public:

    enum class GameType { Multiplayer, Singleplayer };
    enum class GameLoad { New, Load };

    struct Config {
        explicit Config(GameType const gameType, GameLoad const gameLoad, std::string filepath = "") noexcept;

        Config &operator=(Config const &) noexcept ;
        GameType _gameType;
        GameLoad _gameLoad;
        std::string &_filepath;
    };

    class PauseMenu {
    public:
        enum class ButtonsList { Save, Shutdown, Load, Settings, Resume, Return, En_l, Fr_l, Sp_l, De_l,MusicVolMore, MusicVolLess, EffectVolMore, EffectVolLess, ScreenSizeMore, ScreenSizeLess, Unkown };

        enum class Scene { SC_CHOOSE, SC_SETTINGS, SC_NO_SCENE };
        explicit PauseMenu(Core &core, GameType const gameType_) noexcept;
        ~PauseMenu() noexcept;

        bool isActive() const noexcept;
        void set(bool const val) noexcept;
        void changeLanguage(Language const language_, Core &core) noexcept;
        void event(Core &core, Game &game) noexcept;
        void draw(Core &core) noexcept;
        void loadScene(Scene const scene) noexcept;
        void switchScene() noexcept;
        void drawScChoose(Core &core) noexcept;
        void eventScChoose(Core &core, Game &game) noexcept;
        void drawScSettings(Core &core) noexcept;
        void eventScSettings(Core &core, Game &game) noexcept;
    private:
        bool _active;
        std::map<ButtonsList const, Bomberman::Button *> _buttons;
        raylib::Color _background;
        Scene _currentScene;
        Scene _loadScene;
        std::map<Scene const, void (Game::PauseMenu::*)(Core &core)> drawSc;
        std::map<Scene const, void (Game::PauseMenu::*)(Core &core, Game &game)> eventSc;
        Bomberman::Text screenSize;
        GameType const _gameType;
    };

    explicit Game(Core &core, Config *config) noexcept;
    ~Game() noexcept;

    void handlePause(Core &core) noexcept;
    void loop(Core &core) noexcept final;
    void exportToFile(const std::string &filename);
    void loadFromFile(const std::string &filename);
    std::string getCountdown() noexcept;
    void drawBonuses() noexcept;
    void animWater() noexcept;

private:
    Bombs _bombs;
    Boats _boats;
    Map *_map;
    raylib::Model _water;
    raylib::Texture _textureWater;
    raylib::Texture _textureWater2;
    bool isSceneRunning;
    ::Music music;
    Bomberman::Image _timerImg;
    Bomberman::Image _powerUpScreen;
    Bomberman::Image _black;
    std::chrono::steady_clock::time_point _time1;
    std::chrono::steady_clock::time_point _time3;
    bool _animWater;
    long long _remainingTime;

    Config *_config;
    PauseMenu _pauseMenu;
    int beforeChange;
    ModelList3D _models;
};

#endif /* __GAME__ */
