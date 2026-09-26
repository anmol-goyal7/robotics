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

double cspaceDist(const Config2R &q1, const Config2R &q2) {
  double d1 = angDist(q1.th1, q2.th1);
  double d2 = angDist(q1.th2, q2.th2);
  return std::sqrt(d1 * d1 + d2 * d2);
}
} // namespace arm2r
