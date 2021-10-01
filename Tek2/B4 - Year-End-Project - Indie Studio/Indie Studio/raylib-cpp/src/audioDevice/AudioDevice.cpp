#include "AudioDevice.hpp"

raylib::AudioDevice::AudioDevice(bool lateInit) noexcept 
{
    if (!lateInit)
        Init();
}

raylib::AudioDevice::~AudioDevice() noexcept 
{
    Close();
}

raylib::AudioDevice &raylib::AudioDevice::Init() noexcept 
{
    ::InitAudioDevice();
    return *this;
}

void raylib::AudioDevice::Close() noexcept 
{
    ::CloseAudioDevice();
}

bool raylib::AudioDevice::IsReady() const noexcept 
{
    return ::IsAudioDeviceReady();
}

raylib::AudioDevice &raylib::AudioDevice::SetVolume(float const volume) noexcept 
{
    ::SetMasterVolume(volume);
    return *this;
}
