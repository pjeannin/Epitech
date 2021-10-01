#include <raylib.h>
#include <raymath.h>

#ifndef __VECTORE__
#define __VECTORE__

namespace raylib {

    struct Vector3 : public ::Vector3 {
    public:
        explicit Vector3(float const x = 0, float const y = 0, float const z = 0) noexcept;
        Vector3(::Vector3 const &v) noexcept;

        Vector3 &operator=(::Vector3 const &v) noexcept;
        bool operator==(::Vector3 const &other) const noexcept;
        Vector3 operator+(::Vector3 const &v) const noexcept;
        Vector3 operator+(float const v) const noexcept;
        Vector3 operator-(float const v) const noexcept;
        Vector3 operator*(::Vector3 const &v) const noexcept;
        Vector3 operator*(float const scale) const noexcept;
        Vector3 operator/(::Vector3 const &v) const noexcept;
        Vector3 operator/(float const div) const noexcept;
        
        Vector3 &operator+=(::Vector3 const &v) noexcept;
        Vector3 &operator+=(float const v) noexcept;
        Vector3 &operator-=(::Vector3 const &v) noexcept;
        Vector3 &operator-=(float const v) noexcept;
        Vector3 &operator*=(::Vector3 const &v) noexcept;
        Vector3 &operator*=(float const &v) noexcept;
        Vector3 &operator/=(::Vector3 const &v) noexcept;
        Vector3 &operator/=(float const &v) noexcept;

        float length() const noexcept;
        Vector3 normalize() const noexcept;
        float distance(::Vector3 const &v) const noexcept;
        Vector3 lerp(::Vector3 const &v, float const amount) const noexcept;
        Vector3 crossProduct(::Vector3 const &v) const noexcept;
        Vector3 perpendicular() const noexcept;
        void orthoNormalize(::Vector3 *v) noexcept;
        Vector3 transform(const ::Matrix& matrix) const noexcept;
        Vector3 rotateByQuaternion(const ::Quaternion& quaternion) const noexcept;
        Vector3 reflect(::Vector3 const &normal) const noexcept;
        Vector3 min(::Vector3 const &v) const noexcept;
        Vector3 max(::Vector3 const &v) const noexcept;
        Vector3 barycenter(::Vector3 const &a, ::Vector3 const &b, ::Vector3 const &c) const noexcept;

        static Vector3 zero() noexcept;
        static Vector3 one() noexcept;

        Vector3 &drawLine3D(::Vector3 const &endPos, ::Color const &color) noexcept;
        Vector3 &drawPoint3D(::Color const &color) noexcept;
        Vector3 &drawCircle3D(float const radius, ::Vector3 const &rotationAxis, float const rotationAngle, Color const &color) noexcept;
        Vector3 &drawCube(float const width, float const height, float const length, ::Color const &color) noexcept;
        Vector3 &drawCube(::Vector3 const &size, ::Color const &color) noexcept;
        Vector3 &drawCubeWires(float const width, float const height, float const length, ::Color const &color) noexcept;
        Vector3 &drawCubeWires(::Vector3 const &size, ::Color const color) noexcept;
        Vector3 &drawCubeTexture(const ::Texture2D& texture, float const width, float const height, float const length, ::Color const &color) noexcept;
        Vector3 &drawSphere(float const radius, ::Color const &color) noexcept;
        Vector3 &drawSphere(float const radius, int const rings, int const slices, ::Color const &color) noexcept;
        Vector3 &drawSphereWires(float const radius, int const rings, int const slices, ::Color const &color) noexcept;
        Vector3 &drawCylinder(float const radiusTop, float const radiusBottom, float const height, int const slices, Color const &color) noexcept;
        Vector3 &drawCylinderWires(float const radiusTop, float const radiusBottom, float const height, int const slices, Color const &color) noexcept;
        Vector3 &drawPlane(::Vector2 const &size, ::Color const &color) noexcept;
        bool checkCollision(float const radius1, ::Vector3 const &center2, float const radius2) noexcept;
    };

    struct Vector2 : public ::Vector2 {
    public:
        explicit Vector2(float const x = 0, float const y = 0) noexcept;
        Vector2(::Vector2 const &v) noexcept;

        Vector2 &operator=(::Vector2 const &v);
        bool operator==(::Vector2 const &other) const noexcept;
        Vector2 operator+(::Vector2 const &v) const noexcept;
        Vector2 operator+(float const v) const noexcept;
        Vector2 operator-(float const v) const noexcept;
        Vector2 operator*(::Vector2 const &v) const noexcept;
        Vector2 operator*(float const scale) const noexcept;
        Vector2 operator/(::Vector2 const &v) const noexcept;
        Vector2 operator/(float const div) const noexcept;
        Vector2 &operator+=(::Vector2 const &v) noexcept;
        Vector2 &operator+=(float const v) noexcept;
        Vector2 &operator-=(::Vector2 const &v) noexcept;
        Vector2 &operator-=(float const v) noexcept;
        Vector2 &operator*=(::Vector2 const &v) noexcept;
        Vector2 &operator*=(float const &v) noexcept;
        Vector2 &operator/=(::Vector2 const &v) noexcept;
        Vector2 &operator/=(float const &v) noexcept;

        float length() const noexcept;
        float lengthSqr() const noexcept;
        Vector2 normalize() const noexcept;
        float dotProduct(::Vector2 const &vector2) const noexcept;
        float angle(::Vector2 const &vector2) const noexcept;
        float distance(::Vector2 const &vector2) const noexcept;
        Vector2 lerp(::Vector2 const &vector2, float amount) const noexcept;
        Vector2 reflect(::Vector2 const &normal) const noexcept;
        Vector2 rotate(float degrees) const noexcept;
        Vector2 moveTowards(::Vector2 const &target, float maxDistance) const noexcept;

        static Vector2 zero() noexcept;
        static Vector2 one() noexcept;
    
        Vector2 &drawPixel(::Color const &color) noexcept;
        Vector2 &drawLine(::Vector2 const &endPos, ::Color const &color) noexcept;
        Vector2 &drawLine(::Vector2 const &endPos, float const thick, ::Color const &color) noexcept;
        Vector2 &drawLineBezier(::Vector2 const &endPos, float const thick, ::Color const &color) noexcept;
        Vector2 &drawLineBezierQuad(::Vector2 const &endPos, ::Vector2 const &controlPos, float const thick, ::Color const &color) noexcept;
        Vector2 &drawCircle(float const radius, ::Color const &color) noexcept;
        Vector2 &drawRectangle(::Vector2 const &size, ::Color const &color) noexcept;
        Vector2 &drawPoly(int const sides, float const radius, float const rotation, ::Color const &color) noexcept;
        bool checkCollisionCircle(float const radius1, ::Vector2 const &center2, float const radius2) const noexcept;
        bool checkCollisionCircle(float const radius, ::Rectangle const &rec) const noexcept;
        bool checkCollision(::Rectangle const &rec) const noexcept;
        bool checkCollision(::Vector2 const &center, float const radius) const noexcept;
        bool checkCollision(::Vector2 const &p1, ::Vector2 const &p2, ::Vector2 const &p3) const noexcept;
        bool checkCollisionLines(::Vector2 const &endPos1, ::Vector2 const &startPos2, ::Vector2 const &endPos2, ::Vector2 *collisionPoint) const noexcept;
    };
}

#endif  /* __VECTORE__ */