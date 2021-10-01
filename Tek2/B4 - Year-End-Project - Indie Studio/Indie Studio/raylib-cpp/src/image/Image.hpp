#ifndef _IMAGE__
#define _IMAGE__

#include <string>
#include <raylib.h>

namespace raylib {
    class Image : public ::Image {
    public:
        Image(::Image const &image) noexcept;
        Image &operator=(::Image const &image) noexcept;
        explicit Image(std::string const &fileName) noexcept;
        explicit Image(std::string const &fileName, int const width, int const height, int const format, int const headerSize) noexcept;
        explicit Image(std::string const &fileName, int* frames) noexcept;
        explicit Image(std::string const &fileType, unsigned char const *fileData, int const dataSize) noexcept;
        explicit Image(::Texture2D const &texture) noexcept;
        explicit Image(int const width, int const height, ::Color const &color = {255, 255, 255, 255}) noexcept;
        explicit Image(::Font const &font, std::string const &text, float const fontSize, float const spacing, ::Color const &tint = {255, 255, 255, 255}) noexcept;
        explicit Image() noexcept;
        static ::Image Text(std::string const &text, int const fontSize, ::Color const &color = {255, 255, 255, 255}) noexcept;
        static ::Image Text(::Font const &font, std::string const &text, float const fontSize, float const spacing,
                ::Color const &tint = {255, 255, 255, 255}) noexcept;
        static ::Image GetScreenData() noexcept;
        static ::Image Color(int const width, int const height, ::Color const &color = {255, 255, 255, 255}) noexcept;
        static ::Image GradientV(int const width, int const height, ::Color const top, ::Color const bottom) noexcept;
        static ::Image GradientH(int const width, int const height, ::Color const &left, ::Color const &right) noexcept;
        static ::Image GradientRadial(int const width, int const height, float const density, ::Color const &inner, ::Color const &outer) noexcept;
        static ::Image Checked(int const width, int const height, int const checksX, int const checksY,
        ::Color const &col1 = {255, 255, 255, 255}, ::Color const &col2 = {0, 0, 0, 255}) noexcept;
        static ::Image WhiteNoise(int const width, int const height, float const factor) noexcept;
        static ::Image PerlinNoise(int const width, int const height, int const offsetX, int const offsetY, float const scale = 1.0f) noexcept;
        static ::Image Cellular(int const width, int const height, int const tileSize) noexcept;
        ~Image() noexcept;
        void Load(std::string const &fileName) noexcept;
        void LoadRaw(std::string const &fileName, int const width, int const height, int const format, int const headerSize) noexcept;
        void LoadAnim(std::string const &fileName, int *frames) noexcept;
        void LoadFromMemory(std::string const &fileType, unsigned char const *fileData, int const dataSize) noexcept;
        void unload() noexcept;
        bool Export(std::string const &fileName) noexcept;
        bool ExportAsCode(std::string const &fileName) noexcept;
        ::Vector2 GetSize() noexcept;
        ::Image Copy() noexcept;
        ::Image FromImage(::Rectangle const &rec) noexcept;
        Image &ToPOT(::Color const &fillColor) noexcept;
        Image &Format(int const newFormat) noexcept;
        Image &AlphaMask(::Image const &alphaMask) noexcept;
        Image &AlphaCrop(float const threshold) noexcept;
        Image &AlphaPremultiply() noexcept;
        Image &Crop(::Rectangle const &crop) noexcept;
        Image &Crop(::Vector2 const &size) noexcept;
        Image &Crop(int const offsetX, int const offsetY, int const newWidth, int const newHeight) noexcept;
        Image &Resize(int const newWidth, int const newHeight) noexcept;
        Image &ResizeNN(int const newWidth, int const newHeight) noexcept;
        Image &ResizeCanvas(int const newWidth, int const newHeight, int const offsetX, int const offsetY, ::Color const &color = {255, 255, 255, 255}) noexcept;
        Image &Mipmaps() noexcept;
        Image &Dither(int const rBpp, int const gBpp, int const bBpp, int const aBpp) noexcept;
        Image &FlipVertical() noexcept;
        Image &FlipHorizontal() noexcept;
        Image &RotateCW() noexcept;
        Image &RotateCCW() noexcept;
        Image &ColorTint(::Color const &color = {255, 255, 255, 255}) noexcept;
        Image &ColorInvert() noexcept;
        Image &ColorGrayscale() noexcept;
        Image &ColorContrast(float const contrast) noexcept;
        Image &ColorBrightness(int const brightness) noexcept;
        Image &ColorReplace(::Color const &color, ::Color const &replace) noexcept;
        Rectangle GetAlphaBorder(float const threshold) const;
        Image &ClearBackground(::Color const &color = {0, 0, 0, 255}) noexcept;
        Image &DrawPixel(int const posX, int const posY, ::Color const &color = {255, 255, 255, 255}) noexcept;
        Image &DrawPixel(::Vector2 const &position, ::Color const &color = {255, 255, 255, 255}) noexcept;
        Image &DrawLine(int const startPosX, int const startPosY, int const endPosX, int const endPosY,
                ::Color const &color = {255, 255, 255, 255}) noexcept;
        Image &DrawLine(::Vector2 const &start, ::Vector2 const &end, ::Color const &color = {255, 255, 255, 255}) noexcept;
        Image &DrawCircle(int const centerX, int const centerY, int const radius,
                ::Color const &color = {255, 255, 255, 255}) noexcept;
        Image &DrawCircle(::Vector2 center, int radius,
                ::Color const &color = {255, 255, 255, 255}) noexcept;
        Image &DrawRectangle(int const posX, int const posY, int const width, int const height,
                ::Color const &color = {255, 255, 255, 255}) noexcept;
        Image &DrawRectangle(Vector2 const &position, Vector2 const &size, ::Color const &color = {255, 255, 255, 255}) noexcept;
        Image &DrawRectangle(::Rectangle const &rec, ::Color const &color = {255, 255, 255, 255}) noexcept;
        Image &DrawRectangleLines(::Rectangle const &rec, int const thick = 1,
                ::Color const &color = {255, 255, 255, 255}) noexcept;
        Image &draw(::Image const &src, ::Rectangle const &srcRec, ::Rectangle const &dstRec, ::Color const &tint = {255, 255, 255, 255}) noexcept;
        Image &DrawText(std::string const &text, ::Vector2 const &position, int const fontSize, ::Color const &color = {255, 255, 255, 255}) noexcept;
        Image &DrawText(std::string const &text, int const x, int const y, int const fontSize,
                ::Color const &color = {255, 255, 255, 255}) noexcept;
        Image &DrawText(::Font const &font, std::string const &text, ::Vector2 const &position, float const fontSize, float const spacing, ::Color const &tint = {255, 255, 255, 255}) noexcept;
        ::Color *LoadColors() noexcept;
        ::Color *LoadPalette(int maxPaletteSize, int *colorsCount) noexcept;
        void unloadColors(::Color *colors) noexcept;
        void unloadPalette(::Color *colors) noexcept;
        ::Texture2D LoadTexture() noexcept;
        static int GetPixelDataSize(int const width, int const height, int const format = PIXELFORMAT_UNCOMPRESSED_R32G32B32A32) noexcept;
        int GetPixelDataSize() noexcept;

        bool loaded;
    };
}

#endif  /* _IMAGE__ */
