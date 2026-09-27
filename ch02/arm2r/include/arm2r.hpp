#pragma once
#include <vector>

namespace arm2r {
constexpr double kPi = 3.14159265358979323846;
// Returns the angle equivalent to `a` (radians) in the range (-pi, pi]. Input
// must be finite.
double wrapToPi(double a);

// Shortest distance between angles a and b (radians) on the circle. Result in
// [0, pi].
double angDist(double a, double b);

struct Config2R {
  double th1, th2;
};

double cspaceDist(const Config2R &q1, const Config2R &q2);

struct Vec2 {
  double x, y;
};

Vec2 fk2R(const Config2R &q, double L1, double L2);

std::vector<Vec2> sampleWorkspace(double L1, double L2, int n);
} // namespace arm2r
