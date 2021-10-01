#include "Game.hpp"
#include "../../components/boat/player/Player.hpp"
#include "../../components/boat/AI/AI.hpp"

#include <iostream>

Game::Game(Core &core, Config *config) noexcept :
    _map(new Map), _water(raylib::Model(raylib::Mesh::plane(30, 55, 5, 5))),
    _textureWater("resources/3D/water/water.png"), _textureWater2("resources/3D/water/water3.png"),
    isSceneRunning(true), _timerImg("resources/images/time.png", raylib::Vector2(845.5, -30.0)),
    _powerUpScreen("resources/images/powerUpScreen.png"), _black("resources/images/black.png", raylib::Vector2(0, 395)),
    _models {
        {ModelList::Barrel, std::make_pair(new raylib::Model("resources/3D/barrel/barrel.obj"), new raylib::Texture("resources/3D/barrel/barrel.png"))},
        {ModelList::Explosion, std::make_pair(new raylib::Model("resources/3D/explosion/explosion.obj"), new raylib::Texture("resources/3D/explosion/explosion.png"))},
        {ModelList::BoatBlue, std::make_pair(new raylib::Model("resources/3D/boat/boat1.obj"), new raylib::Texture("resources/3D/boat/boat_blue.png"))},
        {ModelList::BoatRed, std::make_pair(new raylib::Model("resources/3D/boat/boat1.obj"), new raylib::Texture("resources/3D/boat/boat_red.png"))},
        {ModelList::BoatGreen, std::make_pair(new raylib::Model("resources/3D/boat/boat1.obj"), new raylib::Texture("resources/3D/boat/boat_green.png"))},
        {ModelList::BoatYellow, std::make_pair(new raylib::Model("resources/3D/boat/boat1.obj"), new raylib::Texture("resources/3D/boat/boat_yellow.png"))},
        {ModelList::FireUp, std::make_pair(new raylib::Model("resources/3D/fireUp/fireUp.obj"), new raylib::Texture("resources/3D/fireUp/fireUp.png"))},
        {ModelList::HPUp, std::make_pair(new raylib::Model("resources/3D/wallPass/wallPass.obj"), new raylib::Texture("resources/3D/wallPass/wallPass.png"))},
        {ModelList::SpeedUp, std::make_pair(new raylib::Model("resources/3D/speedUp/speedUp.obj"), new raylib::Texture("resources/3D/speedUp/speedUp.png"))},
        {ModelList::BombUp, std::make_pair(new raylib::Model("resources/3D/bombUp/bombUp.obj"), new raylib::Texture("resources/3D/bombUp/bombUp.png"))},
    },
    _config(config),
    _pauseMenu(core, config->_gameType), _time1(std::chrono::steady_clock::now()),
    _time3(std::chrono::steady_clock::now()),
    _remainingTime(183000),
    beforeChange(0),
    _animWater(false)
{
    for (auto &model : _models)
        model.second.first->materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = *model.second.second;
    _water.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _textureWater;

    music = LoadMusicStream("resources/music/music_game.ogg");
    music.looping = true;
    ::SetMusicVolume(music, std::stof(core.musicVolVal) * 0.01);
}

Game::~Game() noexcept
{
    delete _config;
    for (auto model : _models) {
        delete model.second.first;
        delete model.second.second;
    }
    _models.clear();
    UnloadMusicStream(music);
}

void Game::drawBonuses() noexcept
{
    for (auto boat : _boats) {
        if (boat->getSpeed() > 1.0f)
            boat->drawPowerUpS();
        if (boat->getBombMax() > 1)
            boat->drawPowerUpB();
        if (boat->getBombRange() > 1)
            boat->drawPowerUpF();
    }
}

void Game::animWater() noexcept
{
    std::chrono::steady_clock::time_point _time4 = std::chrono::steady_clock::now();

    if (std::chrono::duration_cast<std::chrono::milliseconds>(_time4 - _time3).count() > 600) {
        if (_animWater) {
            _water.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _textureWater2;
            _animWater = false;
        } else {
            _water.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _textureWater;
            _animWater = true;
        }
        _time3 = _time4;
    }
}

void Game::loop(Core &core) noexcept
{
    if (_config->_gameLoad == GameLoad::New) {
        _boats.push_back(new Player(raylib::Vector3(0, 0, 0), Boat::BLUE_TEAM, 1, _models));
        if (_config->_gameType == Game::GameType::Singleplayer) {
            _boats.push_back(new AI(raylib::Vector3(0, 0, 12), Boat::RED_TEAM, 2, _models));
        } else {
            _boats.push_back(new Player(raylib::Vector3(0, 0, 12), Boat::RED_TEAM, 2, _models));
        }
        _boats.push_back(new AI(raylib::Vector3(12, 0, 12), Boat::GREEN_TEAM, 3, _models));
        _boats.push_back(new AI(raylib::Vector3(12, 0, 0), Boat::YELLOW_TEAM, 4, _models));
        _map->DFSGenerator();
    } else {
        loadFromFile("last.save");
    }
    raylib::Camera camera(Vector3{-3.0f, 10.0f, 6.6f}, Vector3{3.8f, 0.0f, 6.5f}, Vector3{10000.0f, 1.0f, 10.0f}, 60.0f, CAMERA_PERSPECTIVE);
    std::vector<Bomb *> bombs;
    std::vector<APowerUp *> bonus;
    PlayMusicStream(music);
    while (isSceneRunning) {
        if (!_pauseMenu.isActive() && _remainingTime < 180000 && _boats.size() != 1) {
            UpdateMusicStream(music);
            for (int i = 0; i < _boats.size(); ++i) {
                _boats[i]->update(bombs, _map, bonus);
                if (_boats[i]->getPosition().y < -2) {
                    _map->getGrid().at(roundPosition(_boats[i]->getPosition().x) + (13 * roundPosition(_boats[i]->getPosition().z)))->setType(' ');
                    _boats.erase(_boats.begin() + i);
                }
            }
        }
        core.beginDrawing();
        core.clearBackground(RAYWHITE);
        camera.beginMode();
        if (!_pauseMenu.isActive())
            animWater();
        _water.draw(raylib::Vector3 { 6.5f, 0.0f, 6.5f }, 1.0f, raylib::Color::White());
        _map->drawDecorations();
        _map->drawBorder();
        _map->drawMap();
        for (int i = 0; i < bombs.size(); ++i) {
            bombs[i]->draw(_map);
            if (bombs.at(i)->getRemainingTime() >= 0)
                bombs.at(i)->updateRemainingTime(_map, bonus);
            if (bombs.at(i)->getExploded())
                killBoats(_boats, *bombs[i], *_map);
            if (bombs.at(i)->getScale() >= 2)
                bombs.erase(bombs.begin() + i);
        }
        for (int i = 0; i < bonus.size(); ++i)
            bonus.at(i)->draw();
        for (int i = 0; i < _boats.size(); ++i)
            _boats[i]->draw();
        camera.update();
        camera.endMode();
        _timerImg.draw();
        _powerUpScreen.draw();
        drawBonuses();
        if (_boats.size() == 1) {
            if (beforeChange == 0)
                beforeChange = _remainingTime / 1000;
            if (beforeChange - _remainingTime / 1000 == 3)
                isSceneRunning = false;
            std::string str = "Player ";
            str.append(std::to_string(_boats.at(0)->getId()));
            str.append(" wins.");
            DrawText(str.c_str(), 500, 400, 150, YELLOW);
        }
        if (_remainingTime > 180000) {
            _black.draw();
            DrawText(getCountdown().c_str(), 914, 400, 150, YELLOW);
            DrawText("03:00", 914, 4, 40, YELLOW);
        } else {
            if (_remainingTime < 180000 && _remainingTime > 179000) {
                _black.draw();
                DrawText("GO !", 830, 400, 150, YELLOW);
            }
            DrawText((getCountdown()).c_str(), 914, 4, 40, YELLOW);
        }
        if (_remainingTime < 0) {
            isSceneRunning = false;
            std::string str = "Time's Up !";
            DrawText(str.c_str(), 500, 400, 150, YELLOW);
        }
        handlePause(core);
        core.endDrawing();
    }
    core.loadScene<Menu>();
}

std::string Game::getCountdown() noexcept
{
    int i = 0;
    std::string remaining = "";

    if (!_pauseMenu.isActive()) {
        std::chrono::steady_clock::time_point _time2 = std::chrono::steady_clock::now();
        _remainingTime -= std::chrono::duration_cast<std::chrono::milliseconds>(_time2 - _time1).count();
        _time1 = _time2;
    }
    for (; i * 60 <= (_remainingTime / 1000) - 60; ++i);
    remaining = '0' + std::to_string(i) + ':' + std::to_string((int)(_remainingTime / 1000) - (i * 60));
    if (i == 3)
        remaining += '0';
    if (_remainingTime > 180000)
        return (std::to_string((int)((_remainingTime - 180000) / 1000)));
    return (remaining);
}


static void updateBoat(Boats &_boats, std::string line, std::ifstream &save, ModelList3D &_models, Game::GameType game)
{
    int index = -1;

    while (getline(save, line)) {
        if (line.size() > 4 && line.substr(0, 4).compare("Boat") == 0) {
            index++;
            getline(save, line);
            auto x = std::stof(line.substr(0, line.find(" ")));
            line.erase(0, line.find(" ") + 1);
            auto y = std::stof(line.substr(0, line.find(" ")));
            line.erase(0, line.find(" ") + 1);
            auto z = std::stof(line.substr(0, line.find(" ")));
            raylib::Vector3 vect(x, y, z);
            getline(save, line);
            unsigned int team_number = stoi(line);
            Boat::Team team;
            getline(save, line);
            unsigned int id = stoi(line);
            switch (team_number) {
                case 0:
                    team = Boat::Team::BLUE_TEAM;
                    break;
                case 1:
                    team = Boat::Team::RED_TEAM;
                    break;
                case 2:
                    team = Boat::Team::GREEN_TEAM;
                    break;
                case 3:
                    team = Boat::Team::YELLOW_TEAM;
                    break;
            }
            if (id == 1)
                _boats.push_back(new Player(vect, team, id, _models));
            if (id == 2 && game == Game::GameType::Singleplayer)
                _boats.push_back(new AI(vect, team, id, _models));
            else if (id == 2 && game == Game::GameType::Multiplayer)
                _boats.push_back(new Player(vect, team, id, _models));
            if (id == 3 || id == 4)
                _boats.push_back(new AI(vect, team, id, _models));
            getline(save, line);
            _boats.at(index)->setBombMax(std::stoi(line));
            getline(save, line);
            _boats.at(index)->setBombRange(std::stoi(line));
            getline(save, line);
            _boats.at(index)->setSpeed(std::stoi(line));
            getline(save, line);
            _boats.at(index)->setIsAlive(std::stoi(line));
            getline(save, line);
            _boats.at(index)->setHP(std::stoi(line));
        }
    }
}

void Game::loadFromFile(const std::string &filename)
{
    std::ifstream save("saves/" + filename);
    std::string line;
    int size = 0;
    int gridIndex = 0;
    int index = -1;

    std::string gameType;
    getline(save, gameType);
    _config->_gameType = (gameType == "Singleplayer" ? GameType::Singleplayer : GameType::Multiplayer);
    getline(save, line);
    _map->reset();
    while (size < 13) {
        getline(save, line);
        for (int i = 1; i < 14; i++)
            _map->getGrid().at(gridIndex++)->setType(line.at(i));
        size++;
    }
    updateBoat(_boats, line, save, _models, _config->_gameType);
}

static void printBorder(std::ofstream &myFile)
{
    for (int i = 0; i < 15; ++i)
        myFile << '-';
    myFile << std::endl;
}

void Game::exportToFile(const std::string &filename)
{

    std::string path = "saves/" + filename;
    remove(path.c_str());
    std::ofstream myFile;

    myFile.open(path);
    myFile << (_config->_gameType == GameType::Singleplayer ? "Singleplayer" : "Multiplayer") << std::endl;
    printBorder(myFile);
    int line = 0;
    for (int i = 0; i < _map->getGrid().size(); ++i) {
        if (line == 0)
            myFile << '-';
        myFile << _map->getGrid().at(i)->getType();
        line++;
        if (line == 13) {
            myFile << '-' << std::endl;
            line = 0;
        }
    }
    printBorder(myFile);
    for (int i = 0; i < _boats.size(); ++i) {
        myFile << "Boat " << i << std::endl;
        myFile << _boats.at(i)->getPosition().x << " " << _boats.at(i)->getPosition().y << " " << _boats.at(i)->getPosition().z << std::endl;
        myFile << _boats.at(i)-> getTeam() << std::endl;
        myFile << _boats.at(i)-> getId() << std::endl;
        myFile << _boats.at(i)->getBombMax() << std::endl;
        myFile << _boats.at(i)->getBombRange() << std::endl;
        myFile << _boats.at(i)->getSpeed() << std::endl;
        myFile << _boats.at(i)-> isIsAlive() << std::endl;
        myFile << _boats.at(i)->getHP() << std::endl;
        myFile << std::endl;
    }
    myFile.close();
}

void Game::handlePause(Core &core) noexcept
{
    if (IsKeyPressed(KEY_P))
        _pauseMenu.set(true);
    if (!_pauseMenu.isActive())
        return;
    _pauseMenu.event(core, *this);
    _pauseMenu.draw(core);
}

void Game::PauseMenu::loadScene(Scene const scene) noexcept
{
    _loadScene = scene;
}

void Game::PauseMenu::switchScene() noexcept
{
    _currentScene = _loadScene;
    _loadScene = Scene::SC_NO_SCENE;

}

Game::Config::Config(GameType const gameType, GameLoad const gameLoad, std::string filepath) noexcept : _gameType(gameType), _gameLoad(gameLoad), _filepath(filepath)
{}

Game::Config &Game::Config::operator=(Config const &config) noexcept
{
    _gameLoad = config._gameLoad;
    _gameType = config._gameType;
    _filepath = config._filepath;
    return *this;
}
