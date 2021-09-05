#ifndef INCL_TUPLE_H
#define INCL_TUPLE_H

class Tuple {
   public:
    Tuple(float x, float y, float z, float w);
    static Tuple vector(float x, float y, float z);
    static Tuple point(float x, float y, float z);
    float x, y, z, w;
    bool is_point() const;
    bool is_vector() const;
    bool operator==(const Tuple& other) const;
    Tuple operator+(const Tuple& other) const;
    Tuple operator-(const Tuple& other) const;
    Tuple operator-() const;
    Tuple operator*(const float scalar) const;
    Tuple operator/(const float scalar) const;
    float magnitude() const;
    Tuple normalise() const;
    float dot(const Tuple& other) const;
    Tuple cross(const Tuple& other) const;
};

#endif