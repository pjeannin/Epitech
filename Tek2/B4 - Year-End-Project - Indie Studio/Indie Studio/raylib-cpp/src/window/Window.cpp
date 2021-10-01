#include "Window.hpp"

raylib::Window::Window(unsigned int const width, unsigned int const height, std::string const &title) noexcept {
    ::SetConfigFlags(FLAG_MSAA_4X_HINT);
    ::InitWindow(width, height, title.c_str());
    ::SetExitKey(0);
}
raylib::Window::~Window() noexcept
{
    if (isOpen())
        close();
}

bool raylib::Window::isOpen() const { return !::WindowShouldClose(); }

void raylib::Window::close() noexcept { ::CloseWindow(); }

bool raylib::Window::isCursorOnScreen() const noexcept { return ::IsCursorOnScreen(); }

bool raylib::Window::isReady() noexcept { return ::IsWindowReady(); }

bool raylib::Window::isFullscreen() const noexcept { return ::IsWindowFullscreen(); }

bool raylib::Window::isHidden() const noexcept { return ::IsWindowHidden(); }

bool raylib::Window::isMinimized() const noexcept { return ::IsWindowMinimized(); }

bool raylib::Window::isMaximized() const noexcept { return ::IsWindowMaximized(); }

bool raylib::Window::isFocused() const noexcept { return ::IsWindowFocused(); }

bool raylib::Window::isResized() const noexcept { return ::IsWindowResized(); }

bool raylib::Window::isState(unsigned int const flag) const noexcept { return ::IsWindowState(flag); }

raylib::Window &raylib::Window::setState(unsigned int const flag) noexcept { ::SetWindowState(flag); return *this; }

raylib::Window &raylib::Window::clearState(unsigned int const flag) noexcept { ::ClearWindowState(flag); return *this; }

raylib::Window &raylib::Window::clearBackground(::Color const &color) noexcept { ::ClearBackground(color); return *this; }

raylib::Window &raylib::Window::toggleFullscreen() noexcept { ::ToggleFullscreen(); return *this; }

raylib::Window &raylib::Window::setFullscreen(bool const fullscreen) noexcept {
    if (fullscreen) {
        if (!isFullscreen())
            toggleFullscreen();
    } else {
        if (isFullscreen())
            toggleFullscreen();
    }
    return *this;
}

raylib::Window &raylib::Window::maximize() noexcept { return (::MaximizeWindow(), *this); }

raylib::Window &raylib::Window::minimize() noexcept { return (::MinimizeWindow(), *this); }

raylib::Window &raylib::Window::restore() noexcept { return (::RestoreWindow(), *this); }

raylib::Window &raylib::Window::setIcon(::Image const &image) noexcept { return (::SetWindowIcon(image), *this); }

raylib::Window &raylib::Window::setTitle(std::string const &title) noexcept { return (::SetWindowTitle(title.c_str()), *this); }

raylib::Window &raylib::Window::setPosition(int const x, int const y) noexcept { return (::SetWindowPosition(x, y), *this); }

raylib::Window &raylib::Window::setPosition(::Vector2 const &position) noexcept { return setPosition(static_cast<int>(position.x), static_cast<int>(position.y)); }

raylib::Window &raylib::Window::setMonitor(int const monitor) noexcept { return (::SetWindowMonitor(monitor), *this); }

raylib::Window &raylib::Window::setMinSize(int const width, int const height) noexcept { return (::SetWindowMinSize(width, height), *this); }

raylib::Window &raylib::Window::setSize(int const width, int const height) noexcept { return (::SetWindowSize(width, height), *this);}

raylib::Window &raylib::Window::setSize(::Vector2 const &size) noexcept { return setSize(static_cast<int>(size.x), static_cast<int>(size.y));}

::Vector2 raylib::Window::getSize() noexcept { return {static_cast<float>(getWidth()), static_cast<float>(getHeight())}; }

void *raylib::Window::getHandle() const noexcept { return ::GetWindowHandle(); }

raylib::Window &raylib::Window::beginDrawing() noexcept { return (::BeginDrawing(), *this); }

raylib::Window &raylib::Window::endDrawing() noexcept { return (::EndDrawing(), *this); }

int raylib::Window::getWidth() const noexcept { return ::GetScreenWidth(); }

int raylib::Window::getHeight() const noexcept { return ::GetScreenHeight(); }

::Vector2 raylib::Window::getPosition() const noexcept { return ::GetWindowPosition(); }

::Vector2 raylib::Window::getScaleDPI() const noexcept { return ::GetWindowScaleDPI(); }

raylib::Window &raylib::Window::setTargetFPS(int const fps) noexcept { return (::SetTargetFPS(fps), *this); }

int raylib::Window::getFPS() const noexcept { return ::GetFPS(); }

float raylib::Window::getFrameTime() const noexcept { return ::GetFrameTime(); }

double raylib::Window::getTime() const noexcept { return ::GetTime(); }
