#ifndef INCL_COLOUR_H
#define INCL_COLOUR_H
class Colour {
   public:
    Colour();
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

const Colour BLACK = Colour(0.f, 0.f, 0.f);

#endif