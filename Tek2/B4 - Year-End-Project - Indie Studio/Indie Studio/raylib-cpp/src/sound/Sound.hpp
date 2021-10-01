#ifndef __SOUND__
#define __SOUND__

#include <string>
#include <raylib.h>

namespace raylib {
/**
 * Wave/Sound management functions
 *
 * @code
 * raylib::Sound boom("boom.wav");
 * boom.Play();
 * @endcode
 */
    class Sound : public ::Sound {
        public:
            explicit Sound() noexcept;
            explicit Sound(::Sound const &vec) noexcept;
            explicit Sound(std::string const &fileName) noexcept;
            explicit Sound(::Wave const &wave) noexcept;
            ~Sound() noexcept;
            Sound &operator=(::Sound const &sound) noexcept;
            Sound &Update(void const *data, int const sampleCount) noexcept;
            Sound &Update(void const *data) noexcept;
            void Unload() noexcept;
            Sound &Play() noexcept;
            Sound &Stop() noexcept;
            Sound &Pause() noexcept;
            Sound &Resume() noexcept;
            Sound &PlayMulti() noexcept;
            Sound &StopMulti() noexcept;
            bool IsPlaying() const noexcept;
            Sound &SetVolume(float const volume) noexcept;
            Sound &SetPitch(float const pitch) noexcept;

            bool loaded;
    };
}

#endif  /* __SOUND__ */
