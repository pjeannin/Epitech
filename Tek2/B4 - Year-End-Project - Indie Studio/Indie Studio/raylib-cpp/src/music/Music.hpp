#ifndef __MUSIC__
#define __MUSIC__

#include <string>
#include <raylib.h>

namespace raylib {
    class Music {
    public:
        explicit Music(::Music const &music) noexcept;
        explicit Music(std::string const &fileName) noexcept;
        explicit Music(std::string const &fileType, unsigned char *data, int const dataSize) noexcept;
        void load(::Music const &music) noexcept;
        void load(std::string const &fileName) noexcept;
        void load(std::string const &fileType, unsigned char *data, int const dataSize) noexcept;
        ~Music() noexcept;
        Music &operator=(::Music const &music) noexcept;
        void unload() noexcept;
        Music &play() noexcept;
        Music &update() noexcept;
        Music &stop() noexcept;
        Music &pause() noexcept;
        Music &resume() noexcept;
        bool isPlaying() const noexcept;
        Music &setVolume(float const volume) noexcept;
        Music &setPitch(float const pitch) noexcept;
        float getTimeLength() const noexcept;
        float getTimePlayed() const noexcept;

        float volume;
        bool loaded;
        ::Music val;
    };
}

#endif  /* __MUSIC__ */
