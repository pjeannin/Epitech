/*
** EPITECH PROJECT, 2021
** Core
** File description:
** Core
*/

#ifndef __CORE__
#define __CORE__

#include "../scene/IScene.hpp"
#include "../../raylib-cpp/src/window/Window.hpp"
#include "../components/mouse/Mouse.hpp"
#include "../components/image/Image.hpp"
#include "../components/text/Text.hpp"
#include "../../raylib-cpp/src/texture/Texture.hpp"
#include "../../raylib-cpp/src/vector/Vector.hpp"
#include "../../raylib-cpp/src/font/Font.hpp"
#include "../../raylib-cpp/src/audioDevice/AudioDevice.hpp"
#include "../../raylib-cpp/src/sound/Sound.hpp"

#include <map>

enum Language : int {
    ENGLISH = 0,
    FRENCH,
    GERMAN,
    SPANISH,
    UNKNOWN
};

static std::string const Languages[] = {"English", "Francais", "Deutsch",
    "Espanol", ""};

class Core : public raylib::Window {
public:

    explicit Core(unsigned int const width = 1920, unsigned int const height = 1080, std::string const &title = "Bomberman") noexcept;
    ~Core() noexcept;

    template<class SceneT, typename... Args>
    bool loadScene(Args ... args) noexcept
    {
        static_assert(std::is_base_of<IScene, SceneT>::value, "Core::loadScene must take an IScene in template");
        return !(nextScene = new SceneT(*this, args...));
    }

    void switchScene() noexcept
    {
        delete currentScene;
        currentScene = nextScene;
        nextScene = nullptr;
    }

    void changeLanguage(Language const language_) noexcept;
    void loop() noexcept;

    raylib::Vector2 screenSize;
    raylib::AudioDevice audioDevice;
    Mouse mouse;
    raylib::Font mainFont;
    raylib::Texture cursor;
    IScene *currentScene;
    IScene *nextScene;
    bool isRunning;

    raylib::Sound fxSelect;
    raylib::Sound fxHover;
    std::string musicVolVal;
    std::string effectVolVal;
    Language language;
    std::map<std::string const, raylib::Texture *> textures;
    Bomberman::Image _mainMenu, _singleplayerMenu, _multiplayerMenu, _settingsMenu, _musicVol, _effectVol, _screenSize;
};

#endif /* __CORE__ */
