#ifndef __MATRIX__
#define __MATRIX__

#include <raylib.h>
#include <raymath.h>
#include <cmath>

namespace raylib {
    /**
     * Matrix type (OpenGL style 4x4 - right handed, column major)
     */
    class Matrix : public ::Matrix {
    public:
        Matrix(::Matrix const &mat) noexcept;
        explicit Matrix(float const M0 = 0, float const M1 = 0, float const M2 = 0, float const M3 = 0, float const M4 = 0, float const M5 = 0,
                        float const M6 = 0, float const M7 = 0, float const M8 = 0, float const M9 = 0, float const M10 = 0, float const M11 = 0,
                        float const M12 = 0, float const M13 = 0, float const M14 = 0, float const M15 = 0) noexcept;
        Matrix &operator=(::Matrix const &matrix) noexcept;
        Matrix &operator=(const Matrix &matrix) noexcept;
        bool operator==(::Matrix const &other) noexcept;

        /**
         * Returns the trace of the matrix (sum of the values along the diagonal)
         */
        float Trace() const noexcept;

        /**
         * Transposes provided matrix
         */
        Matrix Transpose() const noexcept;
        Matrix Invert() const noexcept;
        Matrix Normalize() const noexcept;
        static Matrix Identity() noexcept;
        Matrix Add(::Matrix const &right) noexcept;
        Matrix operator+(::Matrix const &matrix) noexcept;
        Matrix Subtract(::Matrix const &right) noexcept;
        Matrix operator-(::Matrix const &matrix) noexcept;
        static Matrix Translate(float const x, float const y, float const z) noexcept;
        static Matrix Rotate(Vector3 const &axis, float const angle) noexcept;
        static Matrix RotateXYZ(Vector3 const &angle) noexcept;
        static Matrix RotateX(float const angle) noexcept;
        static Matrix RotateY(float const angle) noexcept;
        static Matrix RotateZ(float const angle) noexcept;
        static Matrix Scale(float const x, float const y, float const z) noexcept;
        Matrix Multiply(::Matrix const &right) const noexcept;
        Matrix operator*(::Matrix const &matrix) noexcept;
        static Matrix Frustum(double const left, double const right, double const bottom, double const top,
        double const near, double const far) noexcept;
        static Matrix Perspective(double const fovy, double const aspect, double const near, double const far) noexcept;
        static Matrix Ortho(double const left, double const right, double const bottom, double const top,
        double const near, double const far) noexcept;
        static Matrix LookAt(Vector3 const &eye, Vector3 const &target, Vector3 const &up) noexcept;
        float16 ToFloatV() const noexcept;
        operator float16() noexcept;
        Matrix &SetShaderValue(::Shader const &shader, int const uniformLoc) noexcept;
    };
} 

#endif  /* __MATRIX__ */
