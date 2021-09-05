#include "tuple.h"

#include <assert.h>

#include "utils.h"
Tuple::Tuple(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

Tuple Tuple::vector(float x, float y, float z) { return Tuple(x, y, z, 0.0f); }

Tuple Tuple::point(float x, float y, float z) { return Tuple(x, y, z, 1.0f); }

bool Tuple::is_point() const { return w == 1.0f; }

bool Tuple::is_vector() const { return w == 0.f; }

bool Tuple::operator==(const Tuple& other) const {
    return float_eq(other.x, x) && float_eq(other.y, y) &&
           float_eq(other.z, z) && float_eq(other.w, w);
}

Tuple Tuple::operator+(const Tuple& other) const {
    return Tuple(x + other.x, y + other.y, z + other.z, w + other.w);
}

Tuple Tuple::operator-(const Tuple& other) const {
    return Tuple(x - other.x, y - other.y, z - other.z, w - other.w);
}

Tuple Tuple::operator-() const { return Tuple(-x, -y, -z, -w); }

Tuple Tuple::operator*(const float scalar) const {
    return Tuple(x * scalar, y * scalar, z * scalar, w * scalar);
}
Tuple Tuple::operator/(const float scalar) const {
    return Tuple(x / scalar, y / scalar, z / scalar, w / scalar);
}

float Tuple::magnitude() const { return sqrtf(x * x + y * y + z * z + w * w); }
Tuple Tuple::normalise() const { return this->operator/(this->magnitude()); }
float Tuple::dot(const Tuple& other) const {
    return x * other.x + y * other.y + z * other.z;
}
Tuple Tuple::cross(const Tuple& other) const {
    return Tuple::vector(y * other.z - z * other.y, z * other.x - x * other.z,
                         x * other.y - y * other.x);
}