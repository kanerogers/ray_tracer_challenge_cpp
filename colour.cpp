#include "colour.h"

#include "utils.h"
Colour::Colour() : red(0.f), green(0.f), blue(0.f) {}
Colour::Colour(float red, float green, float blue)
    : red(red), green(green), blue(blue) {}

bool Colour::operator==(const Colour& other) const {
    return float_eq(other.red, red) && float_eq(other.green, green) &&
           float_eq(other.blue, blue);
}

Colour Colour::operator+(const Colour& other) const {
    return Colour(red + other.red, green + other.green, blue + other.blue);
}

Colour Colour::operator-(const Colour& other) const {
    return Colour(red - other.red, green - other.green, blue - other.blue);
}

Colour Colour::operator-() const { return Colour(-red, -green, -blue); }

Colour Colour::operator*(const float scalar) const {
    return Colour(red * scalar, green * scalar, blue * scalar);
}

Colour Colour::operator*(const Colour& other) const {
    return Colour(red * other.red, green * other.green, blue * other.blue);
}

Colour Colour::operator/(const float scalar) const {
    return Colour(red / scalar, green / scalar, blue / scalar);
}