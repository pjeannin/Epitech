#ifndef __AUDIO_DEVICE__
#define __AUDIO_DEVICE__

#include <raylib.h>

namespace raylib {
    class AudioDevice {
    public:
        explicit AudioDevice(bool lateInit = false) noexcept;
        ~AudioDevice() noexcept;
        AudioDevice &Init() noexcept;
        void Close() noexcept;
        bool IsReady() const noexcept;
        AudioDevice &SetVolume(float const volume) noexcept;
    };
}

#endif  /* __AUDIO_DEVICE__ */