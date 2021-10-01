#ifndef __WINDOW__
#define __WINDOW__

#include <string>
#include <raylib.h>

namespace raylib {
    class Window {
    public:
        explicit Window(unsigned int const width = 800, unsigned int const height = 450, std::string const &title = "raylib") noexcept;
        ~Window() noexcept;
        bool isOpen() const;
        void close() noexcept;
        bool isCursorOnScreen() const noexcept;
        static bool isReady() noexcept;
        bool isFullscreen() const noexcept;
        bool isHidden() const noexcept;
        bool isMinimized() const noexcept;
        bool isMaximized() const noexcept;
        bool isFocused() const noexcept;
        bool isResized() const noexcept;
        bool isState(unsigned int const flag) const noexcept;
        Window &setState(unsigned int const flag) noexcept;
        Window &clearState(unsigned int const flag) noexcept;
        Window &clearBackground(::Color const &color = BLACK) noexcept;
        Window &toggleFullscreen() noexcept;
        Window &setFullscreen(bool const fullscreen) noexcept;
        Window &maximize() noexcept;
        Window &minimize() noexcept;
        Window &restore() noexcept;
        Window &setIcon(::Image const &image) noexcept;
        Window &setTitle(std::string const &title) noexcept;
        Window &setPosition(int const x, int const y) noexcept;
        Window &setPosition(::Vector2 const &position) noexcept;
        Window &setMonitor(int const monitor) noexcept;
        Window &setMinSize(int const width, int const height) noexcept;
        Window &setSize(int const width, int const height) noexcept;
        Window &setSize(::Vector2 const &size) noexcept;
        ::Vector2 getSize() noexcept;
        void *getHandle() const noexcept;
        Window &beginDrawing() noexcept;
        Window &endDrawing() noexcept;
        int getWidth() const noexcept;
        int getHeight() const noexcept;
        ::Vector2 getPosition() const noexcept;
        ::Vector2 getScaleDPI() const noexcept;
        Window &setTargetFPS(int const fps) noexcept;
        int getFPS() const noexcept;
        float getFrameTime() const noexcept;
        double getTime() const noexcept;
    };
}

#endif /* __WINDOW__ */
