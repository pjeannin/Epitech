#ifndef __RENDER_TEXTURE__
#define __RENDER_TEXTURE__

#include <raylib.h>

namespace raylib {

    class RenderTexture : public ::RenderTexture {
    public:
        RenderTexture(::RenderTexture const &renderTexture) noexcept;
        explicit RenderTexture(unsigned int const Id) noexcept;
        explicit RenderTexture(int const width, int const height) noexcept;
        RenderTexture& operator=(::RenderTexture const &texture_) noexcept;
        ~RenderTexture() noexcept;
        void Unload() noexcept;
        RenderTexture& BeginMode() noexcept;
        RenderTexture& EndMode() noexcept;
    };
    typedef RenderTexture RenderTexture2D;
}

#endif  // __RENDER_TEXTURE__
