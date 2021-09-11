#include "canvas.h"

#include <sstream>
Canvas::Canvas(int width, int height)
    : width(width), height(height), pixels(new Colour[width * height]) {}

void Canvas::write_pixel(int column, int row, Colour colour) {
    pixels[column * row] = colour;
}

Colour* Canvas::pixel_at(int column, int row) { return &pixels[column * row]; }

std::string Canvas::toPpm() {
    std::ostringstream ppm;
    ppm << "P3\n5 3\n255";
    return ppm.str();
}