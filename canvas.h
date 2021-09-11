#ifndef INCL_CANVAS_H
#define INCL_CANVAS_H
#include <string>

#include "colour.h"

class Canvas {
   public:
    Canvas(int width, int height);
    int width, height;
    Colour* pixels;
    void write_pixel(int column, int row, Colour colour);
    Colour* pixel_at(int column, int row);
    std::string toPpm();
};

#endif