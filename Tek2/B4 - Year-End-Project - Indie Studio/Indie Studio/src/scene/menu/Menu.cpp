/*
** EPITECH PROJECT, 2021
** Menu
** File description:
** Menu
*/

#include "Menu.hpp"
#include "../../components/button/Button.hpp"
#include "../../../raylib-cpp/src/utils/Utils.hpp"

#include "../../../raylib-cpp/src/functions/Functions.hpp"

void Menu::changeLanguage(Language const language_, Core &core) noexcept
{
    core.changeLanguage(language_);
    _buttons[ButtonsList::Singleplayer]->loadTexture(core.textures["Singleplayer"], 3);
    _buttons[ButtonsList::Multiplayer]->loadTexture(core.textures["Multiplayer"], 3);
    _buttons[ButtonsList::Settings]->loadTexture(core.textures["Settings"], 3);
    _buttons[ButtonsList::Load]->loadTexture(core.textures["Load"], 3);
}

Menu::Menu(Core &core) noexcept :
    _currentScene(Scene::SC_START),
    _loadScene(Scene::SC_NO_SCENE),
    _buttons{{ButtonsList::Singleplayer, new Bomberman::Button()},
             {ButtonsList::Multiplayer, new Bomberman::Button()},
             {ButtonsList::Settings, new Bomberman::Button()},
             {ButtonsList::Load, new Bomberman::Button()},
             {ButtonsList::MusicVolMore, new Bomberman::Button(core.textures["RightArrow"])},
             {ButtonsList::MusicVolLess, new Bomberman::Button(core.textures["LeftArrow"])},
             {ButtonsList::EffectVolMore, new Bomberman::Button(core.textures["RightArrow"])},
             {ButtonsList::EffectVolLess, new Bomberman::Button(core.textures["LeftArrow"])},
             {ButtonsList::ScreenSizeMore, new Bomberman::Button(core.textures["RightArrow"])},
             {ButtonsList::ScreenSizeLess, new Bomberman::Button(core.textures["LeftArrow"])},
             {ButtonsList::Return, new Bomberman::Button(core.textures["Return"])},
             {ButtonsList::Enter, new Bomberman::Button(core.textures["Enter"])},
             {ButtonsList::Shutdown, new Bomberman::Button(core.textures["Shutdown"])},
             {ButtonsList::En_l, new Bomberman::Button(core.textures["En_l"])},
             {ButtonsList::Fr_l, new Bomberman::Button(core.textures["Fr_l"])},
             {ButtonsList::De_l, new Bomberman::Button(core.textures["De_l"])},
             {ButtonsList::Sp_l, new Bomberman::Button(core.textures["Sp_l"])}},
    _ellapsedTime(0),
    animBoat("resources/animations/anim boat.png", raylib::Vector2(660, 345), 13, 5, raylib::Vector2(15, 5)),
    animTitleStart("resources/animations/anim title start.png", raylib::Vector2(360, 40), 17, 5),
    animTitleLoop("resources/animations/anim title loop.png", raylib::Vector2(360, 40), 18, 5),
    drawSc{{Scene::SC_START, &Menu::drawScStart}, {Scene::SC_CHOOSE, &Menu::drawScChoose}, {Scene::SC_SINGLEPLAYER, &Menu::drawScSingleplayer}, {Scene::SC_MULTIPLAYER, &Menu::drawScMultiplayer}, {Scene::SC_SETTINGS, &Menu::drawScSettings}},
    eventSc{{Scene::SC_START, &Menu::eventScStart}, {Scene::SC_CHOOSE, &Menu::eventScChoose}, {Scene::SC_SINGLEPLAYER, &Menu::eventScSingleplayer}, {Scene::SC_MULTIPLAYER, &Menu::eventScMultiplayer}, {Scene::SC_SETTINGS, &Menu::eventScSettings}},
    screenSize(raylib::Vector2(1080, 758), &core.mainFont, 35, 2), isSceneRunning(true)
{
    fade.startTransition();
    changeLanguage(FRENCH, core);
    _bomb.load("resources/images/bomb.png", raylib::Vector2(-200, 160), -13, 1.5, raylib::Color::RayWhite());

    Bomberman::Button *button = nullptr;
    SET_BUTTONS_BOUNDS(Singleplayer, +500, -270);
    SET_BUTTONS_BOUNDS(Multiplayer, +500, -90);
    SET_BUTTONS_BOUNDS(Load, +500, +90);
    SET_BUTTONS_BOUNDS(Settings, +500, +270);
    SET_BUTTONS_BOUNDS(Return, -780, +460);
    SET_BUTTONS_BOUNDS(Enter, +880, +460);
    SET_BUTTONS_BOUNDS(Shutdown, -880, +460);
    SET_BUTTONS_BOUNDS(En_l, -248, -250);
    SET_BUTTONS_BOUNDS(Fr_l, -82, -250);
    SET_BUTTONS_BOUNDS(De_l, +82, -250);
    SET_BUTTONS_BOUNDS(Sp_l, +248, -250);
    SET_BUTTONS_BOUNDS(MusicVolMore, +370, -74);
    SET_BUTTONS_BOUNDS(MusicVolLess, +65, -74);
    SET_BUTTONS_BOUNDS(EffectVolMore, +370, +76);
    SET_BUTTONS_BOUNDS(EffectVolLess, +65, +76);
    SET_BUTTONS_BOUNDS(ScreenSizeMore, +370, +226);
    SET_BUTTONS_BOUNDS(ScreenSizeLess, +65, +226);

    for (char i = 6; i > 0; --i)
        _backgrounds.emplace_back(new Bomberman::Image(windowsPath("resources/background/" + std::to_string(i) + ".png"), raylib::Vector2(0, 0), 0, 2));

    core.fxSelect.SetVolume(std::stof(core.effectVolVal) * 0.01);
    core.fxHover.SetVolume(std::stof(core.effectVolVal) * 0.01);

    message = std::string("Click to continue ...");
    messageCounter = 0;
    startBlink = false;
    fadeValContinue = 1;
    blinkSwitch = true;


    music = LoadMusicStream("resources/music/menu start.mp3");
    music.looping = true;
    ::SetMusicVolume(music, std::stof(core.musicVolVal) * 0.01);

    saves = ::FileExists("saves/last.save");
}

Menu::~Menu() noexcept
{
    _buttons.clear();
    _backgrounds.clear();
    UnloadMusicStream(music);
}

void Menu::sceneChangeAnim(Core &core) noexcept
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && _currentScene == Scene::SC_START && !fade.isTransitionRunning()) {
        core.fxSelect.Play();
        loadScene(Scene::SC_CHOOSE);
        UnloadMusicStream(music);
        music = LoadMusicStream("resources/music/menu next.mp3");
        music.looping = true;
    }
    if (_ellapsedTime >= 6 && _currentScene == Scene::SC_START && _loadScene == Scene::SC_NO_SCENE)
        fade.stop();
    fade.update();
    if (_loadScene != Scene::SC_NO_SCENE && fade.isTransitionDone()) {
        switchScene();
        fade.stop();
    }
}

void Menu::switchScene() noexcept
{
    _currentScene = _loadScene;
    _loadScene = Scene::SC_NO_SCENE;

}

void Menu::loop(Core& core) noexcept {
    while (isSceneRunning) {
        if (_ellapsedTime >= 5.8)
            PlayMusicStream(music);
        UpdateMusicStream(music);

        _mousePos = raylib::Mouse::getPosition();
        if (_mousePos.x > 1920)
            _mousePos.x = 1920;
        else if (_mousePos.x < 0)
            _mousePos.x = 0;
        if (_mousePos.y > 1080)
            _mousePos.y = 1080;
        else if (_mousePos.y < 0)
            _mousePos.y = 0;
        event(core);
        sceneChangeAnim(core);
        draw(core);
    }
}
void Menu::loadScene(Scene const scene) noexcept
{
    _loadScene = scene;
    fade.startTransition(0);
}
