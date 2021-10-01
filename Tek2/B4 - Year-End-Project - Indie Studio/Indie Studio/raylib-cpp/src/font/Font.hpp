#ifndef __FONT__
#define __FONT__

#include <string>

#include <raylib.h>

namespace raylib {
    class Font : public ::Font {
    public:
        explicit Font() noexcept ;
        Font(::Font const &font) noexcept ;
        explicit Font(std::string const &fileName) noexcept ;
        explicit Font(std::string const &fileName, int const fontSize, int *fontChars, int const charCount) noexcept ;
        explicit Font(const ::Image& image, ::Color const &key, int const firstChar) noexcept ;
        explicit Font(std::string const &fileType, const unsigned char *fileData, int const dataSize, int const fontSize, 
        int *fontChars, int const charsCount) noexcept ;
        ~Font() noexcept ;
        void Unload() noexcept ;
        Font &operator=(::Font const &font) noexcept ;
        Font &DrawText(std::string const &text, ::Vector2 const &position, 
        float const fontSize, float const spacing, ::Color const &tint = WHITE) noexcept ;
        Font &DrawText(std::string const &text, ::Rectangle rec, float const fontSize, float const spacing, 
        bool const wordWrap = false, ::Color const &tint = WHITE) noexcept ;
        Font &DrawText(std::string const &text, ::Rectangle rec, float const fontSize, float const spacing, bool const wordWrap, 
        ::Color const &tint, int selectStart, int const selectLength, ::Color const &selectText, ::Color const &selectBack) noexcept ;
        Font &DrawText(int const codepoint, ::Vector2 const &position,
        float const fontSize, ::Color const &tint = { 255, 255, 255, 255 }) noexcept ;
        Vector2 MeasureText(std::string const &text, float const fontSize, float const spacing) const noexcept ;
        int GetGlyphIndex(int const character) const noexcept ;
        ::Image ImageText(std::string const &text, float const fontSize,
        float const spacing, ::Color const &tint) const noexcept ;
    };
}

#endif  /* __FONT__ */
