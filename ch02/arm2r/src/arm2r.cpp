#include "arm2r.hpp"
#include <cmath>

namespace arm2r {
// wrapToPi converts any angle ranging from - inf to inf in the range (- pi to
// pi]
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
} // namespace arm2r
