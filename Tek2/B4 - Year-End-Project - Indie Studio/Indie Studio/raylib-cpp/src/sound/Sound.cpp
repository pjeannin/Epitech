#include "Sound.hpp"
#include "../utils/Utils.hpp"

raylib::Sound::Sound() noexcept : loaded(false)
{}

raylib::Sound::Sound(::Sound const &vec) noexcept : loaded(false)
{
    if (loaded)
        Unload();
    *this = vec;
    loaded = true;
}

raylib::Sound::Sound(std::string const &fileName) noexcept : loaded(false)
{
    if (loaded)
        Unload();
    *this = LoadSound(windowsPath(fileName).c_str());
    loaded = true;
}

raylib::Sound::Sound(::Wave const &wave) noexcept : loaded(false)
{
    if (loaded)
        Unload();
    *this = LoadSoundFromWave(wave);
    loaded = true;
}

raylib::Sound::~Sound() noexcept
{
    Unload();
}

raylib::Sound &raylib::Sound::operator=(::Sound const &sound) noexcept
{
    if (loaded)
        Unload();
    sampleCount = sound.sampleCount;
    stream = sound.stream;
    loaded = true;
    return *this;
}

raylib::Sound &raylib::Sound::Update(void const *data, int const sampleCount) noexcept
{
    ::UpdateSound(*this, data, sampleCount);
    return *this;
}

raylib::Sound &raylib::Sound::Update(void const *data) noexcept
{
    ::UpdateSound(*this, data, sampleCount);
    return *this;
}

void raylib::Sound::Unload() noexcept
{
    ::UnloadSound(*this);
    loaded = false;
}

raylib::Sound &raylib::Sound::Play() noexcept
{
    ::PlaySound(*this);
    return *this;
}

raylib::Sound &raylib::Sound::Stop() noexcept
{
    ::StopSound(*this);
    return *this;
}

raylib::Sound &raylib::Sound::Pause() noexcept
{
    ::PauseSound(*this);
    return *this;
}

raylib::Sound &raylib::Sound::Resume() noexcept
{
    ::ResumeSound(*this);
    return *this;
}

raylib::Sound &raylib::Sound::PlayMulti() noexcept
{
    ::PlaySoundMulti(*this);
    return *this;
}

raylib::Sound &raylib::Sound::StopMulti() noexcept
{
    ::StopSoundMulti();
    return *this;
}

bool raylib::Sound::IsPlaying() const noexcept
{
    return ::IsSoundPlaying(*this);
}

raylib::Sound &raylib::Sound::SetVolume(float const volume) noexcept
{
    ::SetSoundVolume(*this, volume);
    return *this;
}

raylib::Sound &raylib::Sound::SetPitch(float const pitch) noexcept
{
    ::SetSoundPitch(*this, pitch);
    return *this;
}