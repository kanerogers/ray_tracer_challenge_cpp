#include "utils.h"
bool float_eq(float x, float y) { return fabsf(x - y) < EPSILON; };