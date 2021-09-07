#include <iostream>

#include "tuple.h"

struct Projectile {
    Tuple position;
    Tuple velocity;
};

struct Environment {
    Tuple gravity;
    Tuple wind;
};

Projectile tick(Environment env, Projectile projectile) {
    Tuple position = projectile.position + projectile.velocity;
    Tuple velocity = projectile.velocity + env.gravity + env.wind;
    return Projectile{position, velocity};
};

int main(int, char**) {
    auto p = Projectile{Tuple::point(0.f, 1.f, 0.f),
                        Tuple::vector(1.f, 1.f, 0.f).normalise()};
    auto e = Environment{Tuple::vector(0.f, -.1f, 0.f),
                         Tuple::vector(-0.1f, 0.f, 0.f)};
    while (p.position.y > 0.) {
        p = tick(e, p);
        std::cout << "Position is " << p.position.y << "\n";
    }
};
