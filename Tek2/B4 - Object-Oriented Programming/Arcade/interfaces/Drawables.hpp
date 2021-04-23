/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace) [WSL: Ubuntu]
** File description:
** Drawables
*/

#ifndef DRAWABLES_HPP_
#define DRAWABLES_HPP_

#include <string>

template <class T>
struct Vector
{
    T y;
    T x;

    explicit Vector(T px, T py) noexcept : y(py), x (px) {};
    Vector &operator +(const Vector &other) noexcept {return Vector(x + other.x, y + other.y);};
    Vector &operator +=(const Vector &other) noexcept {x += other.x; y += other.y; return *this;};
    Vector &operator -(const Vector &other) noexcept {return Vector(x - other.x, y - other.y);};
    Vector &operator -=(const Vector &other) noexcept {x -= other.x; y -= other.y; return *this;};
};

typedef Vector<float> Vector2f;
typedef Vector<int> Vector2i;
typedef Vector<unsigned int> Vector2u;

template <class T>
struct Vector3
{
    T y;
    T x;
    T z;

    explicit Vector3(T px, T py, T pz) noexcept : x(px), y (py), z(pz) {};
    Vector3 &operator +(const Vector3 &other) noexcept {return Vector3(x + other.x, y + other.y, z + other.z);};
    Vector3 &operator +=(const Vector3 &other) noexcept {x += other.x; y += other.y; z += other.z; return *this;};
    Vector3 &operator -(const Vector3 &other) noexcept {return Vector3(x - other.x, y - other.y, z - other.z);};
    Vector3 &operator -=(const Vector3 &other) noexcept {x -= other.x; y -= other.y; z -= other.z; return *this;};
};

typedef Vector3<float> Vector3f;
typedef Vector3<int> Vector3i;
typedef Vector3<unsigned int> Vector3u;

struct Color
{
    static Color Red() { return Color(255, 0, 0, 255); }
    static Color Green() { return Color(0, 255, 0, 255); }
    static Color Blue() { return Color(0, 0, 255, 255); }
    static Color Black() { return Color(0, 0, 0, 255); }
    static Color White() { return Color(255, 255, 255, 255); }
    static Color Yellow() { return Color(255, 255, 0, 255); }
    static Color Orange() { return Color(0xFF, 0xA5, 0x00, 0xFF); }
    static Color Pink() { return Color(0xFF, 0xC0, 0xCB, 0xFF); }
    static Color Transparent() { return Color(0, 0, 0, 0); }
    unsigned char red;
    unsigned char blue;
    unsigned char green;
    unsigned char alpha;

    explicit Color(unsigned char const red, unsigned char const green, unsigned char const blue, unsigned char const alpha) noexcept : red(red), blue(blue), green(green), alpha(alpha) {}
    ~Color() noexcept = default;
    Color(Color const &) noexcept = default;
    Color(Color &&) noexcept = default;
    bool operator==(Color const &color) noexcept { return red == color.red && green == color.green && blue == color.blue && alpha == color.alpha; }
    Color& operator=(Color const &) noexcept = default;
    Color& operator=(Color &&) noexcept = default;
};

struct Position : public Vector2f {
    explicit Position(float const x, float const y) noexcept : Vector2f(x, y) {};
    Position(Position const &pos) noexcept : Vector2f(pos.x, pos.y) {};
    ~Position() = default;

    bool operator==(Position const &pos) noexcept {if (x == pos.x && y == pos.y) return true; else return false;}
    Position &operator=(Position const &pos) noexcept {x = pos.x; y = pos.y; return *this;};
};

struct Size : public Vector2f {
    explicit Size(float const x, float const y) noexcept : Vector2f(x, y) {};
    Size(Size const &size) noexcept : Vector2f(size.x, size.y) {};
    ~Size() = default;

    Size &operator=(Size const &size) noexcept {x = size.x; y = size.y; return *this;};
};

struct Rect {
public:
    explicit Rect(Position const pos = Position(0, 0), Size const size = Size(0, 0), Color const color = Color::Transparent()) noexcept : pos(pos), size(size), color(color) {}
    ~Rect() = default;

    Position pos;
    Size size;
    Color color;
};

struct Circle {
public:
    explicit Circle(Position const pos = Position(0, 0), float const radius = 0, Color const color = Color::Transparent()) noexcept : pos(pos), radius(radius), color(color) {}
    ~Circle() = default;

    Position pos;
    float radius;
    Color color;
};

struct Text {
public:
    explicit Text(std::string const &text, Position const pos = Position(0, 0), Size const size = Size(0, 0), Color const color = Color(0, 0, 0, 0)) noexcept : pos(pos), size(size), color(color), _text(text) {}
    ~Text() = default;

    const std::string &getText(void) const noexcept { return (_text); }
    void setText(const std::string &newText) noexcept { _text = newText; }

    Position pos;
    Size size;
    Color color;
private :
    std::string _text;
};

struct Sprite {
public:
    explicit Sprite(std::string const &path, Position const pos = Position(0, 0), Size const size = Size(0, 0)) noexcept : pos(pos), size(size), _texturePath(path) {}
    ~Sprite() = default;

    const std::string &getTexturePath(void) const noexcept { return (_texturePath); }
    Position pos;
    Size size;
private:
    std::string _texturePath;
};

#endif /* !DRAWABLES_HPP_ */
