#include "arm2r.hpp"
#include <cmath>

namespace arm2r {
double wrapToPi(double a) {
  double r = std::fmod(a, 2 * kPi);
  if (r < 0) {
    r += 2 * kPi;
  }
  if (r > kPi) {
    r -= 2 * kPi;
  }

  return r;
}

double angDist(double a, double b) {
  double dist = a - b;

  dist = wrapToPi(dist);

  return std::fabs(dist);
}
} // namespace arm2r
