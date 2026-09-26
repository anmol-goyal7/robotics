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
} // namespace arm2r
