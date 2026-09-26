#include "arm2r.hpp"
#include <cassert>
#include <cmath>
#include <cstdio>

using arm2r::kPi;
using arm2r::wrapToPi;

bool approxEq(double a, double b, double eps = 1e-9) {
  return std::fabs(a - b) < eps;
}

int main() {
  assert(approxEq(wrapToPi(0.0), 0.0));
  assert(approxEq(wrapToPi(kPi / 2), (kPi / 2)));
  assert(approxEq(wrapToPi(kPi), (kPi)));
  assert(approxEq(wrapToPi(-kPi), (kPi)));
  assert(approxEq(wrapToPi(3 * kPi), (kPi)));
  assert(approxEq(wrapToPi(-3 * kPi / 2), (kPi / 2)));
  assert(approxEq(wrapToPi(7.0), (7.0 - 2 * kPi)));
  std::puts("all tests passed");
  return 0;
}
