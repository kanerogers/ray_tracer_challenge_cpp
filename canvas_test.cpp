#include "canvas.h"

#include <gtest/gtest.h>

#include <iostream>

#include "colour.h"

TEST(CanvasTest, BasicAssertions) {
    Canvas c(10, 20);
    ASSERT_EQ(c.width, 10);
    ASSERT_EQ(c.height, 20);
    for (int i = 0; i < 10 * 20; i++) {
        auto p = c.pixels[i];
        std::cout << i << "\n";
        ASSERT_EQ(p, BLACK);
    }
}

TEST(CanvasWritePixel, BasicAssertions) {
    Canvas c(10, 20);
    Colour red(1., 0., 0.);
    c.write_pixel(2, 3, red);
    ASSERT_EQ(*(c.pixel_at(2, 3)), red);
}

TEST(CanvasToPPM, BasicAssertions) {
    Canvas c(5, 3);
    auto ppm = c.toPpm();
    std::string line;
    std::istringstream ppmStream(ppm);

    std::getline(ppmStream, line);
    ASSERT_EQ(line, "P3");

    std::getline(ppmStream, line);
    ASSERT_EQ(line, "5 3");

    std::getline(ppmStream, line);
    ASSERT_EQ(line, "255");
}
