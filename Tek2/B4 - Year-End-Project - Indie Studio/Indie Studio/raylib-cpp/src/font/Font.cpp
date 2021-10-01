#include "Font.hpp"
#include "../utils/Utils.hpp"

raylib::Font::Font() noexcept
{
    *this = ::GetFontDefault();
}

raylib::Font::Font(::Font const &font) noexcept
{
    *this = font;
}

raylib::Font::Font(std::string const &fileName) noexcept
{
    *this = ::LoadFont(windowsPath(fileName).c_str());
}

raylib::Font::Font(std::string const &fileName, int const fontSize, int *fontChars, int const charCount)  noexcept
{
    *this = ::LoadFontEx(windowsPath(fileName).c_str(), fontSize, fontChars, charCount);
}

raylib::Font::Font(const ::Image& image, ::Color const &key, int const firstChar) noexcept
{
    *this = ::LoadFontFromImage(image, key, firstChar);
}

raylib::Font::Font(std::string const &fileType, const unsigned char *fileData, int const dataSize, 
int const fontSize, int *fontChars, int const charsCount)  noexcept
{
    *this = ::LoadFontFromMemory(windowsPath(fileType).c_str(), fileData, dataSize, fontSize, fontChars, charsCount);
}

raylib::Font::~Font() noexcept
{
    Unload();
}

void raylib::Font::Unload() noexcept
{
/*
    UnloadFont(*this);
*/
}

raylib::Font &raylib::Font::operator=(::Font const &font) noexcept
{
    baseSize = font.baseSize;
    charsCount = font.charsCount;
    charsPadding = font.charsPadding;
    texture = font.texture;
    recs = font.recs;
    chars = font.chars;
    return *this;
}

raylib::Font &raylib::Font::DrawText(std::string const &text, ::Vector2 const &position, float const fontSize, float const spacing, 
::Color const &tint) noexcept
{
    ::DrawTextEx(*this, text.c_str(), position,  fontSize,  spacing,  tint);
    return *this;
}

raylib::Font &raylib::Font::DrawText(std::string const &text, ::Rectangle rec, float const fontSize, float const spacing, 
bool const wordWrap, ::Color const &tint) noexcept
{
    ::DrawTextRec(*this, text.c_str(), rec,  fontSize,  spacing,  wordWrap,  tint);
    return *this;
}

raylib::Font &raylib::Font::DrawText(std::string const &text, ::Rectangle rec, float const fontSize, float const spacing, bool const wordWrap, 
::Color const &tint, int selectStart, int const selectLength, ::Color const &selectText, ::Color const &selectBack) noexcept
{
    ::DrawTextRecEx(*this, text.c_str(), rec, fontSize, spacing, wordWrap, tint,
        selectStart,  selectLength, selectText, selectBack);
    return *this;
}

raylib::Font &raylib::Font::DrawText(int const codepoint, ::Vector2 const &position,
float const fontSize, ::Color const &tint) noexcept
{
    ::DrawTextCodepoint(*this, codepoint, position, fontSize, tint);
    return *this;
}

Vector2 raylib::Font::MeasureText(std::string const &text, float const fontSize, float const spacing) const noexcept
{
    return ::MeasureTextEx(*this, text.c_str(), fontSize, spacing);
}

int raylib::Font::GetGlyphIndex(int const character) const noexcept
{
    return ::GetGlyphIndex(*this, character);
}

::Image raylib::Font::ImageText(std::string const &text, float const fontSize,
float const spacing, ::Color const &tint) const noexcept
{
    return ::ImageTextEx(*this, text.c_str(), fontSize, spacing, tint);
}
