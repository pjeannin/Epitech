#ifndef __SHADER__
#define __SHADER__

#include <string>
#include <raylib.h>

namespace raylib {
    class Shader : public ::Shader {
    public:
        Shader(::Shader const &shader) noexcept;
        explicit Shader(unsigned int const id_, int *locs_) noexcept;
        explicit Shader(std::string const &vsFileName, std::string const &fsFileName) noexcept;
        static ::Shader Load(std::string const &vsFileName, std::string const &fsFileName) noexcept;
        static ::Shader LoadFromMemory(std::string const &vsCode, std::string const &fsCode) noexcept;
        Shader &operator=(::Shader const &shader) noexcept;
        ~Shader() noexcept;
        void Unload() noexcept;
        Shader &BeginMode() noexcept;
        Shader &EndMode() noexcept;
        int GetLocation(std::string const &uniformName) const noexcept;
        int GetLocationAttrib(std::string const &attribName) const noexcept;
        Shader &SetValue(int const uniformLoc, std::string const &value, int const uniformType) noexcept;
        Shader &SetValue(int const uniformLoc, std::string const &value, int const uniformType, int const count) noexcept;
        Shader &SetValue(int const uniformLoc, ::Matrix const &mat) noexcept;
        Shader &SetValue(int const uniformLoc, const ::Texture2D& texture) noexcept;
    };
}

#endif  /* __SHADER__ */
