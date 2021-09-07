#include "colour.h"

#include <gtest/gtest.h>

#include "utils.h"

TEST(ColourTest, BasicAssertions) {
    Colour c(-.5f, 0.4f, 1.7f);
    ASSERT_EQ(c.red, -.5f);
    ASSERT_EQ(c.green, .4f);
    ASSERT_EQ(c.blue, 1.7f);
}

TEST(ColourAddition, BasicAssertions) {
    Colour c1(.9f, 0.6f, 0.75f);
    Colour c2(.7f, .1f, .25f);
    ASSERT_EQ(c1 + c2, Colour(1.6f, .7f, 1.f));
}

TEST(ColourSubtraction, BasicAssertions) {
    Colour c1(.9f, 0.6f, 0.75f);
    Colour c2(.7f, .1f, .25f);
    ASSERT_EQ(c1 - c2, Colour(0.2f, .5f, .5f));
}

TEST(ColourMultiplationByScalar, BasicAssertions) {
    Colour c1(.2f, 0.3f, 0.4f);
    ASSERT_EQ(c1 * 2.f, Colour(.4f, .6f, .8f));
}

TEST(ColourMultiplation, BasicAssertions) {
    Colour c1(1.f, 0.2f, 0.4f);
    Colour c2(.9f, 1.f, 0.1f);
    ASSERT_EQ(c1 * c2, Colour(.9f, .2f, .04f));
}
