#ifndef __MOUSE__
#define __MOUSE__

#include <raylib.h>
#include "../vector/Vector.hpp"

namespace raylib {
    class Mouse {
    public:
        static bool IsButtonPressed(int const button) noexcept;
        static bool IsButtonDown(int const button) noexcept;
        static bool IsButtonReleased(int const button) noexcept;
        static bool IsButtonUp(int const button) noexcept;
        static int getX() noexcept;
        static int getY() noexcept;
        static void SetX(int const x) noexcept;
        static void SetY(int const y) noexcept;
        static Vector2 getPosition() noexcept;
        static void setPosition(int const x, int const y) noexcept;
        static void setOffset(int const offsetX, int const offsetY) noexcept;
        static void setScale(float const scaleX, float const scaleY) noexcept;
        static float getWheelMove() noexcept;
        static void setCursor(int const cursor) noexcept;
        static int getTouchX() noexcept;
        static int getTouchY() noexcept;
        static Vector2 getTouchPosition(int const index) noexcept;
    };
}

#endif  /* __MOUSE__ */
