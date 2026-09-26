#pragma once

namespace arm2r {
constexpr double kPi = 3.14159265358979323846;
// Returns the angle equivalent to `a` (radians) in the range (-pi, pi]. Input
// must be finite.
double wrapToPi(double a);

// Shortest distance between angles a and b (radians) on the circle. Result in
// [0, pi].
double angDist(double a, double b);
} // namespace arm2r
