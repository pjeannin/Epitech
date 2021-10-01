#include "Image.hpp"
#include "../utils/Utils.hpp"

raylib::Image::Image() noexcept : loaded(false)
{}

raylib::Image::Image(::Image const &image) noexcept : loaded(false)
{
    *this = image;
}

raylib::Image &raylib::Image::operator=(::Image const &image) noexcept
{
    loaded = false;
    data = image.data;
    format = image.format;
    height = image.height;
    mipmaps = image.mipmaps;
    width = image.width;
    return *this;
}

raylib::Image::Image(std::string const &fileName) noexcept : loaded(false)
{
    Load(windowsPath(fileName));
}

raylib::Image::Image(std::string const &fileName, int const width, int const height, int const format, int const headerSize) noexcept : loaded(false)
{
    LoadRaw(windowsPath(fileName), width, height, format, headerSize);
}

raylib::Image::Image(std::string const &fileName, int* frames) noexcept : loaded(false)
{
    LoadAnim(windowsPath(fileName), frames);
}

raylib::Image::Image(std::string const &fileType, unsigned char const *fileData, int const dataSize) noexcept : loaded(false)
{
    LoadFromMemory(windowsPath(fileType), fileData, dataSize);
}

raylib::Image::Image(::Texture2D const &texture) noexcept : loaded(false)
{
    *this = ::GetTextureData(texture);
}

raylib::Image::Image(int const width, int const height, ::Color const &color) noexcept : loaded(false)
{
    *this = ::GenImageColor(width, height, color);
}

raylib::Image::Image(::Font const &font, std::string const &text, float const fontSize, float const spacing, ::Color const &tint) noexcept : loaded(false)
{
    *this = ::ImageTextEx(font, text.c_str(), fontSize, spacing, tint);
}

::Image raylib::Image::Text(std::string const &text, int const fontSize, ::Color const &color) noexcept {
    return ::ImageText(text.c_str(), fontSize, color);
}

::Image raylib::Image::Text(::Font const &font, std::string const &text, float const fontSize, float const spacing,
        ::Color const &tint) noexcept {
    return ::ImageTextEx(font, text.c_str(), fontSize, spacing, tint);
}

::Image raylib::Image::GetScreenData() noexcept {
    return ::GetScreenData();
}

::Image raylib::Image::Color(int const width, int const height, ::Color const &color) noexcept {
    return ::GenImageColor(width, height, color);
}

::Image raylib::Image::GradientV(int const width, int const height, ::Color const top, ::Color const bottom) noexcept {
    return ::GenImageGradientV(width, height, top, bottom);
}

::Image raylib::Image::GradientH(int const width, int const height, ::Color const &left, ::Color const &right) noexcept {
    return ::GenImageGradientH(width, height, left, right);
}

::Image raylib::Image::GradientRadial(int const width, int const height, float const density, ::Color const &inner, ::Color const &outer) noexcept {
    return ::GenImageGradientRadial(width, height, density, inner, outer);
}

::Image raylib::Image::Checked(int const width, int const height, int const checksX, int const checksY, ::Color const &col1, ::Color const &col2) noexcept {
    return ::GenImageChecked(width, height, checksX, checksY, col1, col2);
}

::Image raylib::Image::WhiteNoise(int const width, int const height, float const factor) noexcept {
    return ::GenImageWhiteNoise(width, height, factor);
}

::Image raylib::Image::PerlinNoise(int const width, int const height, int const offsetX, int const offsetY, float const scale) noexcept {
    return ::GenImagePerlinNoise(width, height, offsetX, offsetY, scale);
}

::Image raylib::Image::Cellular(int const width, int const height, int const tileSize) noexcept {
    return ::GenImageCellular(width, height, tileSize);
}

raylib::Image::~Image() noexcept {
    unload();
}

void raylib::Image::LoadRaw(std::string const &fileName, int const width, int const height, int const format, int const headerSize) noexcept {
    *this = ::LoadImageRaw(fileName.c_str(), width, height, format, headerSize);
}

void raylib::Image::LoadAnim(std::string const &fileName, int *frames) noexcept {
    *this = ::LoadImageAnim(fileName.c_str(), frames);
}

void raylib::Image::LoadFromMemory(std::string const &fileType, unsigned char const *fileData, int const dataSize) noexcept {
    *this = ::LoadImageFromMemory(fileType.c_str(), fileData, dataSize);
}

void raylib::Image::Load(std::string const &fileName) noexcept
{
    unload();
    *this =::LoadImage(fileName.c_str());
    loaded = true;
}

void raylib::Image::unload() noexcept {
    if (loaded && (data != NULL)) {
        ::UnloadImage(*this);
        data = NULL;
    }
}

bool raylib::Image::Export(std::string const &fileName) noexcept {
    return ::ExportImage(*this, fileName.c_str());
}

bool raylib::Image::ExportAsCode(std::string const &fileName) noexcept {
    return ::ExportImageAsCode(*this, fileName.c_str());
}

::Vector2 raylib::Image::GetSize() noexcept {
    return {static_cast<float>(width), static_cast<float>(height)};
}

::Image raylib::Image::Copy() noexcept {
    return ::ImageCopy(*this);
}

::Image raylib::Image::FromImage(::Rectangle const &rec) noexcept {
    return ::ImageFromImage(*this, rec);
}

raylib::Image &raylib::Image::ToPOT(::Color const &fillColor) noexcept {
    ::ImageToPOT(this, fillColor);
    return *this;
}

raylib::Image &raylib::Image::Format(int const newFormat) noexcept {
    ::ImageFormat(this, newFormat);
    return *this;
}

raylib::Image &raylib::Image::AlphaMask(::Image const &alphaMask) noexcept {
    ::ImageAlphaMask(this, alphaMask);
    return *this;
}

raylib::Image &raylib::Image::AlphaCrop(float const threshold) noexcept {
    ::ImageAlphaCrop(this, threshold);
    return *this;
}

raylib::Image &raylib::Image::AlphaPremultiply() noexcept {
    ::ImageAlphaPremultiply(this);
    return *this;
}

raylib::Image &raylib::Image::Crop(::Rectangle const &crop) noexcept {
    ::ImageCrop(this, crop);
    return *this;
}

raylib::Image &raylib::Image::Crop(::Vector2 const &size) noexcept {
    return Crop(0, 0, static_cast<int>(size.x), static_cast<int>(size.y));
}

raylib::Image &raylib::Image::Crop(int const offsetX, int const offsetY, int const newWidth, int const newHeight) noexcept {
    ::Rectangle rect{
        static_cast<float>(offsetX),
        static_cast<float>(offsetY),
        static_cast<float>(newWidth),
        static_cast<float>(newHeight)
    };
    ::ImageCrop(this, rect);
    return *this;
}

raylib::Image &raylib::Image::Resize(int const newWidth, int const newHeight) noexcept {
    ::ImageResize(this, newWidth, newHeight);
    return *this;
}

raylib::Image &raylib::Image::ResizeNN(int const newWidth, int const newHeight) noexcept {
    ::ImageResizeNN(this, newWidth, newHeight);
    return *this;
}

raylib::Image &raylib::Image::ResizeCanvas(int const newWidth, int const newHeight, int const offsetX, int const offsetY,
        ::Color const &color) noexcept {
    ::ImageResizeCanvas(this, newWidth, newHeight, offsetX, offsetY, color);
    return *this;
}

raylib::Image &raylib::Image::Mipmaps() noexcept {
    ::ImageMipmaps(this);
    return *this;
}

raylib::Image &raylib::Image::Dither(int const rBpp, int const gBpp, int const bBpp, int const aBpp) noexcept {
    ::ImageDither(this, rBpp, gBpp, bBpp, aBpp);
    return *this;
}

raylib::Image &raylib::Image::FlipVertical() noexcept {
    ::ImageFlipVertical(this);
    return *this;
}

raylib::Image &raylib::Image::FlipHorizontal() noexcept {
    ::ImageFlipHorizontal(this);
    return *this;
}

raylib::Image &raylib::Image::RotateCW() noexcept {
    ::ImageRotateCW(this);
    return *this;
}

raylib::Image &raylib::Image::RotateCCW() noexcept {
    ::ImageRotateCCW(this);
    return *this;
}

raylib::Image &raylib::Image::ColorTint(::Color const &color) noexcept {
    ::ImageColorTint(this, color);
    return *this;
}

raylib::Image &raylib::Image::ColorInvert() noexcept {
    ::ImageColorInvert(this);
    return *this;
}

raylib::Image &raylib::Image::ColorGrayscale() noexcept {
    ::ImageColorGrayscale(this);
    return *this;
}

raylib::Image &raylib::Image::ColorContrast(float contrast) noexcept {
    ::ImageColorContrast(this, contrast);
    return *this;
}

raylib::Image &raylib::Image::ColorBrightness(int brightness) noexcept {
    ::ImageColorBrightness(this, brightness);
    return *this;
}

raylib::Image &raylib::Image::ColorReplace(::Color const &color, ::Color const &replace) noexcept {
    ::ImageColorReplace(this, color, replace);
    return *this;
}

Rectangle raylib::Image::GetAlphaBorder(float const threshold) const {
    return ::GetImageAlphaBorder(*this, threshold);
}

raylib::Image &raylib::Image::ClearBackground(::Color const &color) noexcept {
    ::ImageClearBackground(this, color);
    return *this;
}

raylib::Image &raylib::Image::DrawPixel(int const posX, int const posY, ::Color const &color) noexcept {
    ::ImageDrawPixel(this, posX, posY, color);
    return *this;
}

raylib::Image &raylib::Image::DrawPixel(::Vector2 const &position, ::Color const &color) noexcept {
    ::ImageDrawPixelV(this, position, color);
    return *this;
}

raylib::Image &raylib::Image::DrawLine(int startPosX, int startPosY, int endPosX, int endPosY,
        ::Color const &color) noexcept {
    ::ImageDrawLine(this, startPosX, startPosY, endPosX, endPosY, color);
    return *this;
}

raylib::Image &raylib::Image::DrawLine(::Vector2 const &start, ::Vector2 const &end, ::Color const &color) noexcept {
    ::ImageDrawLineV(this, start, end, color);
    return *this;
}

raylib::Image &raylib::Image::DrawCircle(int centerX, int centerY, int radius,
        ::Color const &color) noexcept {
    ::ImageDrawCircle(this, centerX, centerY, radius, color);
    return *this;
}

raylib::Image &raylib::Image::DrawCircle(::Vector2 center, int radius,
        ::Color const &color) noexcept {
    ::ImageDrawCircleV(this, center, radius, color);
    return *this;
}

raylib::Image &raylib::Image::DrawRectangle(int const posX, int const posY, int const width, int const height,
        ::Color const &color) noexcept {
    ::ImageDrawRectangle(this, posX, posY, width, height, color);
    return *this;
}

raylib::Image &raylib::Image::DrawRectangle(Vector2 const &position, Vector2 const &size, ::Color const &color) noexcept {
    ::ImageDrawRectangleV(this, position, size, color);
    return *this;
}

raylib::Image &raylib::Image::DrawRectangle(::Rectangle const &rec, ::Color const &color) noexcept {
    ::ImageDrawRectangleRec(this, rec, color);
    return *this;
}

raylib::Image &raylib::Image::DrawRectangleLines(::Rectangle const &rec, int const thick, ::Color const &color) noexcept {
    ::ImageDrawRectangleLines(this, rec, thick, color);
    return *this;
}

raylib::Image &raylib::Image::draw(::Image const &src, ::Rectangle const &srcRec, ::Rectangle const &dstRec, ::Color const &tint) noexcept {
    ::ImageDraw(this, src, srcRec, dstRec, tint);
    return *this;
}

raylib::Image &raylib::Image::DrawText(std::string const &text, ::Vector2 const &position, int const fontSize, ::Color const &color) noexcept {
    ::ImageDrawText(this,
        text.c_str(),
        static_cast<int>(position.x),
        static_cast<int>(position.y),
        fontSize,
        color);
    return *this;
}

raylib::Image &raylib::Image::DrawText(std::string const &text, int const x, int const y, int const fontSize,
        ::Color const &color) noexcept {
    ::ImageDrawText(this, text.c_str(), x, y, fontSize, color);
    return *this;
}

raylib::Image &raylib::Image::DrawText(::Font const &font, std::string const &text, ::Vector2 const &position, float const fontSize, float const spacing, ::Color const &tint) noexcept {
    ::ImageDrawTextEx(this, font, text.c_str(), position, fontSize, spacing, tint);
    return *this;
}

::Color *raylib::Image::LoadColors() noexcept {
    return ::LoadImageColors(*this);
}

::Color *raylib::Image::LoadPalette(int maxPaletteSize, int *colorsCount) noexcept {
    return ::LoadImagePalette(*this, maxPaletteSize, colorsCount);
}

void raylib::Image::unloadColors(::Color *colors) noexcept {
    ::UnloadImageColors(colors);
}

void raylib::Image::unloadPalette(::Color *colors) noexcept {
    ::UnloadImagePalette(colors);
}

::Texture2D raylib::Image::LoadTexture() noexcept {
    return ::LoadTextureFromImage(*this);
}

int raylib::Image::GetPixelDataSize(int const width, int const height, int const format) noexcept {
    return ::GetPixelDataSize(width, height, format);
}

int raylib::Image::GetPixelDataSize() noexcept {
    return ::GetPixelDataSize(width, height, format);
}
