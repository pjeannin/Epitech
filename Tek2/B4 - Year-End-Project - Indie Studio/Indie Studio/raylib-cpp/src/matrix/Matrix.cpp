#include "Matrix.hpp"

raylib::Matrix::Matrix(::Matrix const &mat) noexcept  
{
    *this = mat;
}

raylib::Matrix::Matrix(float const M0, float const M1, float const M2, float const M3, float const M4, float const M5,
                float const M6, float const M7, float const M8, float const M9, float const M10, float const M11,
                float const M12, float const M13, float const M14, float const M15) noexcept 
{
    m0 = M0;
    m1 = M1;
    m2 = M2;
    m3 = M3;
    m4 = M4;
    m5 = M5;
    m6 = M6;
    m7 = M7;
    m8 = M8;
    m9 = M9;
    m10 = M10;
    m11 = M11;
    m12 = M12;
    m13 = M13;
    m14 = M14;
    m15 = M15;
}

raylib::Matrix &raylib::Matrix::operator=(::Matrix const &matrix) noexcept 
{
    m0 = matrix.m0;
    m1 = matrix.m1;
    m2 = matrix.m2;
    m3 = matrix.m3;
    m4 = matrix.m4;
    m5 = matrix.m5;
    m6 = matrix.m6;
    m7 = matrix.m7;
    m8 = matrix.m8;
    m9 = matrix.m9;
    m10 = matrix.m10;
    m11 = matrix.m11;
    m12 = matrix.m12;
    m13 = matrix.m13;
    m14 = matrix.m14;
    m15 = matrix.m15;
    return *this;
}

raylib::Matrix &raylib::Matrix::operator=(const Matrix &matrix) noexcept 
{
    m0 = matrix.m0;
    m1 = matrix.m1;
    m2 = matrix.m2;
    m3 = matrix.m3;
    m4 = matrix.m4;
    m5 = matrix.m5;
    m6 = matrix.m6;
    m7 = matrix.m7;
    m8 = matrix.m8;
    m9 = matrix.m9;
    m10 = matrix.m10;
    m11 = matrix.m11;
    m12 = matrix.m12;
    m13 = matrix.m13;
    m14 = matrix.m14;
    m15 = matrix.m15;
    return *this;
}

bool raylib::Matrix::operator==(::Matrix const &other) noexcept 
{
    return m0 == other.m0 && m1 == other.m1 && m2 == other.m2 && m3 == other.m3
        && m4 == other.m4 && m5 == other.m5 && m6 == other.m6 && m7 == other.m7 && m8 == other.m8
        && m9 == other.m9 && m10 == other.m10 && m11 == other.m11 && m12 == other.m12 && m13 == other.m13
        && m14 == other.m14 && m15 == other.m15;
}

float raylib::Matrix::Trace() const noexcept 
{
    return ::MatrixTrace(*this);
}

raylib::Matrix raylib::Matrix::Transpose() const noexcept 
{
    return ::MatrixTranspose(*this);
}

raylib::Matrix raylib::Matrix::Invert() const noexcept 
{
    return ::MatrixInvert(*this);
}

raylib::Matrix raylib::Matrix::Normalize() const noexcept 
{
    return ::MatrixNormalize(*this);
}

raylib::Matrix raylib::Matrix::Identity() noexcept 
{
    return ::MatrixIdentity();
}

raylib::Matrix raylib::Matrix::Add(::Matrix const &right) noexcept 
{
    return ::MatrixAdd(*this, right);
}

raylib::Matrix raylib::Matrix::operator+(::Matrix const &matrix) noexcept 
{
        return ::MatrixAdd(*this, matrix);
}

raylib::Matrix raylib::Matrix::Subtract(::Matrix const &right) noexcept 
{
    return ::MatrixSubtract(*this, right);
}

raylib::Matrix raylib::Matrix::operator-(::Matrix const &matrix) noexcept 
{
    return ::MatrixSubtract(*this, matrix);
}

raylib::Matrix raylib::Matrix::Translate(float const x, float const y, float const z) noexcept 
{
    return ::MatrixTranslate(x, y, z);
}

raylib::Matrix raylib::Matrix::Rotate(Vector3 const &axis, float const angle) noexcept 
{
    return ::MatrixRotate(axis, angle);
}

raylib::Matrix raylib::Matrix::RotateXYZ(Vector3 const &angle) noexcept 
{
    return ::MatrixRotateXYZ(angle);
}

raylib::Matrix raylib::Matrix::RotateX(float const angle) noexcept 
{
    return ::MatrixRotateX(angle);
}

raylib::Matrix raylib::Matrix::RotateY(float const angle) noexcept 
{
    return ::MatrixRotateY(angle);
}

raylib::Matrix raylib::Matrix::RotateZ(float const angle) noexcept 
{
    return ::MatrixRotateZ(angle);
}

raylib::Matrix raylib::Matrix::Scale(float const x, float const y, float const z) noexcept 
{
    return ::MatrixScale(x, y, z);
}

raylib::Matrix raylib::Matrix::Multiply(::Matrix const &right) const noexcept 
{
    return ::MatrixMultiply(*this, right);
}

raylib::Matrix raylib::Matrix::operator*(::Matrix const &matrix) noexcept 
{
    return ::MatrixMultiply(*this, matrix);
}

raylib::Matrix raylib::Matrix::Frustum(double const left, double const right, double const bottom, double const top,
double const near, double const far) noexcept 
{
    return ::MatrixFrustum(left, right, bottom, top, near, far);
}

raylib::Matrix raylib::Matrix::Perspective(double const fovy, double const aspect, double const near, double const far) noexcept 
{
    return ::MatrixPerspective(fovy, aspect, near, far);
}

raylib::Matrix raylib::Matrix::Ortho(double const left, double const right, double const bottom, double const top,
double const near, double const far) noexcept 
{
    return ::MatrixOrtho(left, right, bottom, top, near, far);
}

raylib::Matrix raylib::Matrix::LookAt(Vector3 const &eye, Vector3 const &target, Vector3 const &up) noexcept 
{
    return ::MatrixLookAt(eye, target, up);
}

float16 raylib::Matrix::ToFloatV() const noexcept 
{
    return ::MatrixToFloatV(*this);
}

raylib::Matrix::operator float16() noexcept 
{
    return ToFloatV();
}

raylib::Matrix &raylib::Matrix::SetShaderValue(::Shader const &shader, int const uniformLoc) noexcept 
{
    ::SetShaderValueMatrix(shader, uniformLoc, *this);
    return *this;
}