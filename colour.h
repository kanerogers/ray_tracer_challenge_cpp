#ifndef INCL_COLOUR_H
#define INCL_COLOUR_H
class Colour {
   public:
    Colour(float red, float green, float blue);
    float red, green, blue;
    bool operator==(const Colour& other) const;
    Colour operator+(const Colour& other) const;
    Colour operator-(const Colour& other) const;
    Colour operator-() const;
    Colour operator*(const float scalar) const;
    Colour operator*(const Colour& other) const;
    Colour operator/(const float scalar) const;
};

#endif