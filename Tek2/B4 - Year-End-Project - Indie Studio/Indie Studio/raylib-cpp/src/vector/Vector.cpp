#include "Vector.hpp"

raylib::Vector3::Vector3(float const x, float const y, float const z) noexcept : ::Vector3{x, y, z} {}
raylib::Vector3::Vector3(::Vector3 const &v) noexcept { *this = v; }
raylib::Vector3 &raylib::Vector3::operator=(::Vector3 const &v) noexcept { x = v.x; y = v.y; z = v.z; return *this; }
bool raylib::Vector3::operator==(::Vector3 const &other) const noexcept { return x == other.x && y == other.y && z == other.z; }
raylib::Vector3 raylib::Vector3::operator+(::Vector3 const &v) const noexcept { return Vector3Add(*this, v); }
raylib::Vector3 raylib::Vector3::operator+(float const v) const noexcept { return Vector3(x + v, y + v, z + v); }
raylib::Vector3 raylib::Vector3::operator-(float const v) const noexcept { return Vector3(x - v, y - v, z - v); }
raylib::Vector3 raylib::Vector3::operator*(::Vector3 const &v) const noexcept { return Vector3Multiply(*this, v); }
raylib::Vector3 raylib::Vector3::operator*(float const scale) const noexcept { return Vector3Scale(*this, scale); }
raylib::Vector3 raylib::Vector3::operator/(::Vector3 const &v) const noexcept { return Vector3Divide(*this, v); }
raylib::Vector3 raylib::Vector3::operator/(float const div) const noexcept { return Vector3(x / div, y / div, z / div); }
raylib::Vector3 &raylib::Vector3::operator+=(::Vector3 const &v) noexcept { x += v.x; y += v.y; z += v.z; return *this; }
raylib::Vector3 &raylib::Vector3::operator+=(float const v) noexcept { x += v; y += v; z += v; return *this; }
raylib::Vector3 &raylib::Vector3::operator-=(::Vector3 const &v) noexcept { x -= v.x; y -= v.y; z -= v.z; return *this; }
raylib::Vector3 &raylib::Vector3::operator-=(float const v) noexcept { x -= v; y -= v; z -= v; return *this; }
raylib::Vector3 &raylib::Vector3::operator*=(::Vector3 const &v) noexcept { x *= v.x; y *= v.y; z *= v.z; return *this; }
raylib::Vector3 &raylib::Vector3::operator*=(float const &v) noexcept { x *= v; y *= v; z *= v; return *this; }
raylib::Vector3 &raylib::Vector3::operator/=(::Vector3 const &v) noexcept { x /= v.x; y /= v.y; z /= v.z; return *this; }
raylib::Vector3 &raylib::Vector3::operator/=(float const &v) noexcept { x /= v; y /= v; z /= v; return *this; }
float raylib::Vector3::length() const noexcept { return Vector3Length(*this); }
raylib::Vector3 raylib::Vector3::normalize() const noexcept { return Vector3Normalize(*this); }
float raylib::Vector3::distance(::Vector3 const &v) const noexcept { return Vector3Distance(*this, v); }
raylib::Vector3 raylib::Vector3::lerp(::Vector3 const &v, float const amount) const noexcept { return Vector3Lerp(*this, v, amount); }
raylib::Vector3 raylib::Vector3::crossProduct(::Vector3 const &v) const noexcept { return Vector3CrossProduct(*this, v); }
raylib::Vector3 raylib::Vector3::perpendicular() const noexcept { return Vector3Perpendicular(*this); }
void raylib::Vector3::orthoNormalize(::Vector3 *v) noexcept { Vector3OrthoNormalize(this, v); }
raylib::Vector3 raylib::Vector3::transform(const ::Matrix& matrix) const noexcept { return Vector3Transform(*this, matrix); }
raylib::Vector3 raylib::Vector3::rotateByQuaternion(const ::Quaternion& quaternion) const noexcept { return Vector3RotateByQuaternion(*this, quaternion); }
raylib::Vector3 raylib::Vector3::reflect(::Vector3 const &normal) const noexcept { return Vector3Reflect(*this, normal); }
raylib::Vector3 raylib::Vector3::min(::Vector3 const &v) const noexcept { return Vector3Min(*this, v); }
raylib::Vector3 raylib::Vector3::max(::Vector3 const &v) const noexcept { return Vector3Max(*this, v); }
raylib::Vector3 raylib::Vector3::barycenter(::Vector3 const &a, ::Vector3 const &b, ::Vector3 const &c) const noexcept { return Vector3Barycenter(*this, a, b, c); }
raylib::Vector3 raylib::Vector3::zero() noexcept { return Vector3Zero(); }
raylib::Vector3 raylib::Vector3::one() noexcept { return Vector3One(); }
raylib::Vector3 &raylib::Vector3::drawLine3D(::Vector3 const &endPos, ::Color const &color) noexcept { return (::DrawLine3D(*this, endPos, color), *this);}
raylib::Vector3 &raylib::Vector3::drawPoint3D(::Color const &color) noexcept { return (::DrawPoint3D(*this, color), *this);}
raylib::Vector3 &raylib::Vector3::drawCircle3D(float const radius, ::Vector3 const &rotationAxis, float const rotationAngle, Color const &color) noexcept { return (::DrawCircle3D(*this, radius, rotationAxis, rotationAngle, color), *this);}
raylib::Vector3 &raylib::Vector3::drawCube(float const width, float const height, float const length, ::Color const &color) noexcept { return (::DrawCube(*this, width, height, length, color), *this);}
raylib::Vector3 &raylib::Vector3::drawCube(::Vector3 const &size, ::Color const &color) noexcept { return (::DrawCubeV(*this, size, color), *this); }
raylib::Vector3 &raylib::Vector3::drawCubeWires(float const width, float const height, float const length, ::Color const &color) noexcept { return (::DrawCubeWires(*this, width, height, length, color), *this); }
raylib::Vector3 &raylib::Vector3::drawCubeWires(::Vector3 const &size, ::Color const color) noexcept { return (::DrawCubeWiresV(*this, size, color), *this); }
raylib::Vector3 &raylib::Vector3::drawCubeTexture(const ::Texture2D& texture, float const width, float const height, float const length, ::Color const &color) noexcept { return (::DrawCubeTexture(texture, *this, width, height, length, color), *this); }
raylib::Vector3 &raylib::Vector3::drawSphere(float const radius, ::Color const &color) noexcept { return (::DrawSphere(*this, radius, color), *this); }
raylib::Vector3 &raylib::Vector3::drawSphere(float const radius, int const rings, int const slices, ::Color const &color) noexcept { return (::DrawSphereEx(*this, radius, rings, slices, color), *this); }
raylib::Vector3 &raylib::Vector3::drawSphereWires(float const radius, int const rings, int const slices, ::Color const &color) noexcept { return (::DrawSphereWires(*this, radius, rings, slices, color), *this); }
raylib::Vector3 &raylib::Vector3::drawCylinder(float const radiusTop, float const radiusBottom, float const height, int const slices, Color const &color) noexcept { return (::DrawCylinder(*this, radiusTop, radiusBottom, height, slices, color), *this); }
raylib::Vector3 &raylib::Vector3::drawCylinderWires(float const radiusTop, float const radiusBottom, float const height, int const slices, Color const &color) noexcept { return (::DrawCylinderWires(*this, radiusTop, radiusBottom, height, slices, color), *this); }
raylib::Vector3 &raylib::Vector3::drawPlane(::Vector2 const &size, ::Color const &color) noexcept { return (::DrawPlane(*this, size, color), *this); }
bool raylib::Vector3::checkCollision(float const radius1, ::Vector3 const &center2, float const radius2) noexcept {return CheckCollisionSpheres(*this, radius1, center2, radius2); }
raylib::Vector2::Vector2(float const x, float const y) noexcept : ::Vector2{x, y} {}
raylib::Vector2::Vector2(::Vector2 const &v) noexcept { *this = v; }
raylib::Vector2 &raylib::Vector2::operator=(::Vector2 const &v) { x = v.x; y = v.y; return *this; }
bool raylib::Vector2::operator==(::Vector2 const &other) const noexcept { return x == other.x && y == other.y; }
raylib::Vector2 raylib::Vector2::operator+(::Vector2 const &v) const noexcept { return Vector2Add(*this, v); }
raylib::Vector2 raylib::Vector2::operator+(float const v) const noexcept { return Vector2(x + v, y + v); }
raylib::Vector2 raylib::Vector2::operator-(float const v) const noexcept { return Vector2(x - v, y - v); }
raylib::Vector2 raylib::Vector2::operator*(::Vector2 const &v) const noexcept { return Vector2Multiply(*this, v); }
raylib::Vector2 raylib::Vector2::operator*(float const scale) const noexcept { return Vector2Scale(*this, scale); }
raylib::Vector2 raylib::Vector2::operator/(::Vector2 const &v) const noexcept { return Vector2Divide(*this, v); }
raylib::Vector2 raylib::Vector2::operator/(float const div) const noexcept { return Vector2(x / div, y / div); }
raylib::Vector2 &raylib::Vector2::operator+=(::Vector2 const &v) noexcept { x += v.x; y += v.y; return *this; }
raylib::Vector2 &raylib::Vector2::operator+=(float const v) noexcept { x += v; y += v; return *this; }
raylib::Vector2 &raylib::Vector2::operator-=(::Vector2 const &v) noexcept { x -= v.x; y -= v.y; return *this; }
raylib::Vector2 &raylib::Vector2::operator-=(float const v) noexcept { x -= v; y -= v; return *this; }
raylib::Vector2 &raylib::Vector2::operator*=(::Vector2 const &v) noexcept { x *= v.x; y *= v.y; return *this; }
raylib::Vector2 &raylib::Vector2::operator*=(float const &v) noexcept { x *= v; y *= v; return *this; }
raylib::Vector2 &raylib::Vector2::operator/=(::Vector2 const &v) noexcept { x /= v.x; y /= v.y; return *this; }
raylib::Vector2 &raylib::Vector2::operator/=(float const &v) noexcept { x /= v; y /= v; return *this; }
float raylib::Vector2::length() const noexcept { return Vector2Length(*this); }
float raylib::Vector2::lengthSqr() const noexcept { return Vector2LengthSqr(*this); }
raylib::Vector2 raylib::Vector2::normalize() const noexcept { return Vector2Normalize(*this); }
float raylib::Vector2::dotProduct(::Vector2 const &vector2) const noexcept { return Vector2DotProduct(*this, vector2);}
float raylib::Vector2::angle(::Vector2 const &vector2) const noexcept { return Vector2Angle(*this, vector2); }
float raylib::Vector2::distance(::Vector2 const &vector2) const noexcept { return Vector2Distance(*this, vector2); }
raylib::Vector2 raylib::Vector2::lerp(::Vector2 const &vector2, float amount) const noexcept { return Vector2Lerp(*this, vector2, amount); }
raylib::Vector2 raylib::Vector2::reflect(::Vector2 const &normal) const noexcept { return Vector2Reflect(*this, normal); }
raylib::Vector2 raylib::Vector2::rotate(float degrees) const noexcept { return Vector2Rotate(*this, degrees); }
raylib::Vector2 raylib::Vector2::moveTowards(::Vector2 const &target, float maxDistance) const noexcept { return Vector2MoveTowards(*this, target, maxDistance); }
raylib::Vector2 raylib::Vector2::zero() noexcept { return Vector2Zero(); }
raylib::Vector2 raylib::Vector2::one() noexcept { return Vector2One(); }
raylib::Vector2 &raylib::Vector2::drawPixel(::Color const &color) noexcept { return (::DrawPixelV(*this, color), *this); }
raylib::Vector2 &raylib::Vector2::drawLine(::Vector2 const &endPos, ::Color const &color) noexcept { return (::DrawLineV(*this, endPos, color), *this); }
raylib::Vector2 &raylib::Vector2::drawLine(::Vector2 const &endPos, float const thick, ::Color const &color) noexcept { return (::DrawLineEx(*this, endPos, thick, color), *this); }
raylib::Vector2 &raylib::Vector2::drawLineBezier(::Vector2 const &endPos, float const thick, ::Color const &color) noexcept { return (::DrawLineBezier(*this, endPos, thick, color), *this); }
raylib::Vector2 &raylib::Vector2::drawLineBezierQuad(::Vector2 const &endPos, ::Vector2 const &controlPos, float const thick, ::Color const &color) noexcept { return (::DrawLineBezierQuad(*this, endPos, controlPos, thick, color), *this); }
raylib::Vector2 &raylib::Vector2::drawCircle(float const radius, ::Color const &color) noexcept { return (::DrawCircleV(*this, radius, color), *this); }
raylib::Vector2 &raylib::Vector2::drawRectangle(::Vector2 const &size, ::Color const &color) noexcept { return (::DrawRectangleV(*this, size, color), *this); }
raylib::Vector2 &raylib::Vector2::drawPoly(int const sides, float const radius, float const rotation, ::Color const &color) noexcept { return (::DrawPoly(*this, sides, radius, rotation, color), *this); }
bool raylib::Vector2::checkCollisionCircle(float const radius1, ::Vector2 const &center2, float const radius2) const noexcept { return ::CheckCollisionCircles(*this, radius1, center2, radius2);}
bool raylib::Vector2::checkCollisionCircle(float const radius, ::Rectangle const &rec) const noexcept { return ::CheckCollisionCircleRec(*this, radius, rec);}
bool raylib::Vector2::checkCollision(::Rectangle const &rec) const noexcept { return ::CheckCollisionPointRec(*this, rec);}
bool raylib::Vector2::checkCollision(::Vector2 const &center, float const radius) const noexcept { return ::CheckCollisionPointCircle(*this, center, radius);}
bool raylib::Vector2::checkCollision(::Vector2 const &p1, ::Vector2 const &p2, ::Vector2 const &p3) const noexcept { return ::CheckCollisionPointTriangle(*this, p1, p2, p3);}
bool raylib::Vector2::checkCollisionLines(::Vector2 const &endPos1, ::Vector2 const &startPos2, ::Vector2 const &endPos2, ::Vector2 *collisionPoint) const noexcept { return ::CheckCollisionLines(*this, endPos1, startPos2, endPos2, collisionPoint);}