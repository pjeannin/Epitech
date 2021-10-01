#include "Music.hpp"
#include "../utils/Utils.hpp"

raylib::Music::Music(::Music const &music) noexcept : volume(100), loaded(false)
{
    load(music);
}

raylib::Music::Music(std::string const &fileName) noexcept : volume(100), loaded(false)
{
    load(fileName);
}

raylib::Music::Music(std::string const &fileType, unsigned char *data, int const dataSize) noexcept : volume(100), loaded(false)
{
    load(fileType, data, dataSize);
}

void raylib::Music::load(::Music const &music) noexcept
{
    if (loaded)
        unload();
    val = music;
    setVolume(volume);
    loaded = true;
}

void raylib::Music::load(std::string const &fileName) noexcept
{
    if (loaded)
        unload();
    val = ::LoadMusicStream(windowsPath(fileName).c_str());
    setVolume(volume);
    loaded = true;
}

void raylib::Music::load(std::string const &fileType, unsigned char *data, int const dataSize) noexcept
{
    if (loaded)
        unload();
    val = ::LoadMusicStreamFromMemory(windowsPath(fileType).c_str(), data, dataSize);
    setVolume(volume);
    loaded = true;
}

raylib::Music::~Music() noexcept 
{
    if (loaded)
        unload();
    loaded = false;
}

raylib::Music &raylib::Music::operator=(::Music const &music) noexcept 
{
    val.ctxType = music.ctxType;
    val.ctxData = music.ctxData;
    val.looping = music.looping;
    val.sampleCount = music.sampleCount;
    val.stream = music.stream;
    setVolume(50);
    return *this;
}

void raylib::Music::unload() noexcept 
{
    ::UnloadMusicStream(val);
}

raylib::Music &raylib::Music::play() noexcept 
{
    ::PlayMusicStream(val);
    return *this;
}

raylib::Music &raylib::Music::update() noexcept 
{
    ::UpdateMusicStream(val);
    return *this;
}

raylib::Music &raylib::Music::stop() noexcept 
{
    ::StopMusicStream(val);
    return *this;
}

raylib::Music &raylib::Music::pause() noexcept 
{
    ::PauseMusicStream(val);
    return *this;
}

raylib::Music &raylib::Music::resume() noexcept 
{
    ::ResumeMusicStream(val);
    return *this;
}

//bool raylib::Music::isPlaying() const noexcept 
//{
//    return ::IsMusicStreamPlaying(*this);
//}

raylib::Music &raylib::Music::setVolume(float const volume_) noexcept 
{
    ::SetMusicVolume(val, volume);
    volume = volume_;
    return *this;
}

raylib::Music &raylib::Music::setPitch(float const pitch) noexcept 
{
    ::SetMusicPitch(val, pitch);
    return *this;
}

float raylib::Music::getTimeLength() const noexcept 
{
    return ::GetMusicTimeLength(val);
}

float raylib::Music::getTimePlayed() const noexcept 
{
    return ::GetMusicTimePlayed(val);
}
