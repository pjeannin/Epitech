/*
** EPITECH PROJECT, 2021
** Menu
** File description:
** Menu
*/

#ifndef __MENU__
#define __MENU__

#include "../IScene.hpp"
#include "../../../raylib-cpp/src/font/Font.hpp"
#include "../../../raylib-cpp/src/texture/Texture.hpp"
#include "../../../raylib-cpp/src/music/Music.hpp"
#include "../../../raylib-cpp/src/vector/Vector.hpp"
#include "../../../raylib-cpp/src/color/Color.hpp"
#include "../../../raylib-cpp/src/rectangle/Rectangle.hpp"
#include "../../../raylib-cpp/src/sound/Sound.hpp"
#include "../../core/Core.hpp"
#include "../../components/image/Image.hpp"
#include "../../components/text/Text.hpp"
#include "../../components/animation/Animation.hpp"
#include "../../components/button/Button.hpp"
#include "../../components/transition/fade/Fade.hpp"

#include <functional>
#include <string>
#include <vector>

class Menu : public IScene {
public:
    enum class Scene {
        SC_START,
        SC_CHOOSE,
        SC_SINGLEPLAYER,
        SC_MULTIPLAYER,
        SC_SETTINGS,
        SC_NEXT,
        SC_NO_SCENE,
    };

    enum class ButtonsList {
        Singleplayer, Multiplayer, Settings, Return, Enter, Shutdown, En_l, Fr_l, Sp_l, De_l, MusicVolMore, MusicVolLess, EffectVolMore,
        EffectVolLess, ScreenSizeMore, ScreenSizeLess, Load, Unkown
    };

    explicit Menu(Core &core) noexcept;
    ~Menu() noexcept;

    void drawBackground() noexcept;
    void loop(Core &core) noexcept final override;
    void event(Core &core) noexcept;
    void eventMenuScStart() noexcept;
    void changeLanguage(Language const language, Core &core) noexcept;
    void draw(Core &core) noexcept;
    void drawScStart(Core &core) noexcept;
    void drawScChoose(Core &core) noexcept;
    void drawScSingleplayer(Core &core) noexcept;
    void drawScMultiplayer(Core &core) noexcept;
    void drawScSettings(Core &core) noexcept;
    void eventScStart(Core &core) noexcept;
    void eventScChoose(Core &core) noexcept;
    void eventScSingleplayer(Core &core) noexcept;
    void eventScMultiplayer(Core &core) noexcept;
    void eventScSettings(Core &core) noexcept;
    void eventBtnCollision(Core &core) noexcept;
    void sceneChangeAnim(Core &core) noexcept;
    void loadScene(Scene const scene) noexcept;
    void switchScene() noexcept;
private:

    std::vector<Bomberman::Image *> _backgrounds;
    Scene _currentScene;
    Scene _loadScene;

    std::map<ButtonsList const, Bomberman::Button *> _buttons;
    double _ellapsedTime;
    raylib::Vector2 _mousePos;

    Bomberman::Animation animBoat;
    Bomberman::Animation animTitleStart;
    Bomberman::Animation animTitleLoop;

    std::string message;
    int messageCounter;
    bool startBlink;
    float fadeValContinue;
    bool blinkSwitch;

    std::map<Scene const, void (Menu::*)(Core &core)> drawSc;
    std::map<Scene const, void (Menu::*)(Core &core)> eventSc;

    bool isSceneRunning;
    Bomberman::Text screenSize;
    Bomberman::Transition::Fade fade;
    Bomberman::Image _bomb;

    ::Music music;

    bool saves;
};

#endif /* __MENU__ */
