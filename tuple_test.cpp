#include "tuple.h"

#include <gtest/gtest.h>

#include "utils.h"

// Demonstrate some basic assertions.
TEST(TupleTest, BasicAssertions) {
    Tuple a(4.3f, -4.2f, 3.1f, 1.0f);
    EXPECT_EQ(a.x, 4.3f);
    EXPECT_EQ(a.y, -4.2f);
    EXPECT_EQ(a.z, 3.1f);
    EXPECT_EQ(a.w, 1.0f);
    EXPECT_TRUE(a.is_point());
    EXPECT_FALSE(a.is_vector());

    Tuple b(4.3f, -4.2f, 3.1f, 0.0f);
    EXPECT_EQ(b.x, 4.3f);
    EXPECT_EQ(b.y, -4.2f);
    EXPECT_EQ(b.z, 3.1f);
    EXPECT_EQ(b.w, 0.0f);
    EXPECT_TRUE(b.is_vector());
    EXPECT_FALSE(b.is_point());

    Tuple p = Tuple::point(4.f, -4.f, 3.f);
    EXPECT_EQ(p, Tuple(4.f, -4.f, 3.f, 1.f));

    Tuple v = Tuple::vector(4.f, -4.f, 3.f);
    EXPECT_EQ(v, Tuple(4.f, -4.f, 3.f, 0.f));
}

TEST(TupleAddingTest, BasicAssertions) {
    Tuple a = Tuple::point(3.f, -2.f, 5.f);
    Tuple b = Tuple::vector(-2.f, 3.f, 1.f);
    EXPECT_EQ(a + b, Tuple::point(1.f, 1.f, 6.f));
}

TEST(TupleSubtractionTest, BasicAssertions) {
    Tuple a = Tuple::point(3.f, 2.f, 1.f);
    Tuple b = Tuple::point(5.f, 6.f, 7.f);
    EXPECT_EQ(a - b, Tuple::vector(-2.f, -4.f, -6.f));

    Tuple x = Tuple::point(3.f, 2.f, 1.f);
    Tuple y = Tuple::vector(5.f, 6.f, 7.f);
    EXPECT_EQ(x - y, Tuple::point(-2.f, -4.f, -6.f));

    Tuple i = Tuple::vector(3.f, 2.f, 1.f);
    Tuple j = Tuple::vector(5.f, 6.f, 7.f);
    EXPECT_EQ(i - j, Tuple::vector(-2.f, -4.f, -6.f));
}

TEST(TupleNegationTest, BasicAssertions) {
    Tuple zero = Tuple::vector(0.f, 0.f, 0.f);
    Tuple v = Tuple::vector(1.f, -2.f, 3.f);
    EXPECT_EQ(zero - v, Tuple::vector(-1.f, 2.f, -3.f));

    Tuple a(1.f, -2.f, 3.f, -4.f);
    EXPECT_EQ(-a, Tuple(-1.f, 2.f, -3.f, 4.f));
}

TEST(TupleMultiplyByScalar, BasicAssertions) {
    Tuple a(1.f, -2.f, 3.f, -4.f);
    EXPECT_EQ(a * 3.5, Tuple(3.5f, -7.f, 10.5f, -14.f));

    Tuple b(1.f, -2.f, 3.f, -4.f);
    EXPECT_EQ(b * 0.5, Tuple(0.5f, -1.f, 1.5f, -2.f));
}

TEST(TupleDiwideByScalar, BasicAssertions) {
    Tuple a(1.f, -2.f, 3.f, -4.f);
    EXPECT_EQ(a / 2, Tuple(0.5f, -1.f, 1.5f, -2.f));
}

TEST(TupleMagnitude, BasicAssertions) {
    Tuple a = Tuple::vector(1.f, 0.f, 0.f);
    EXPECT_EQ(a.magnitude(), 1.f);

    Tuple b = Tuple::vector(0.f, 1.f, 0.f);
    EXPECT_EQ(b.magnitude(), 1.f);

    Tuple c = Tuple::vector(0.f, 0.f, 1.f);
    EXPECT_EQ(c.magnitude(), 1.f);

    Tuple d = Tuple::vector(-1.f, -2.f, -3.f);
    EXPECT_EQ(d.magnitude(), sqrtf(14.f));
}

TEST(TupleNormalization, BasicAssertions) {
    Tuple a = Tuple::vector(4.f, 0.f, 0.f);
    EXPECT_EQ(a.normalise(), Tuple::vector(1.f, 0.f, 0.f));

    Tuple b = Tuple::vector(1.f, 2.f, 3.f);
    EXPECT_EQ(b.normalise(), Tuple::vector(1.f / sqrtf(14.f), 2.f / sqrtf(14.f),
                                           3.f / sqrt(14.f)));

    Tuple c = Tuple::vector(1.f, 2.f, 3.f);
    EXPECT_TRUE(float_eq(c.normalise().magnitude(), 1.f));
}

TEST(TupleDotProdut, BasicAssertions) {
    Tuple a = Tuple::vector(1.f, 2.f, 3.f);
    Tuple b = Tuple::vector(2.f, 3.f, 4.f);

    EXPECT_TRUE(float_eq(a.dot(b), 20.f));
}

TEST(TupleCrossProduct, BasicAssertions) {
    Tuple a = Tuple::vector(1.f, 2.f, 3.f);
    Tuple b = Tuple::vector(2.f, 3.f, 4.f);

    EXPECT_EQ(a.cross(b), Tuple::vector(-1.f, 2.f, -1.f));
}