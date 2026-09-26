#include "arm2r.hpp"
#include <cassert>
#include <cmath>
#include <cstdio>

using arm2r::angDist;
using arm2r::kPi;
using arm2r::wrapToPi;

bool approxEq(double a, double b, double eps = 1e-9) {
  return std::fabs(a - b) < eps;
}

int main() {
  // wrapToPi
  assert(approxEq(wrapToPi(0.0), 0.0));
  assert(approxEq(wrapToPi(kPi / 2), kPi / 2));
  assert(approxEq(wrapToPi(kPi), kPi));
  assert(approxEq(wrapToPi(-kPi), kPi));
  assert(approxEq(wrapToPi(3 * kPi), kPi));
  assert(approxEq(wrapToPi(-3 * kPi / 2), kPi / 2));
  assert(approxEq(wrapToPi(7.0), 7.0 - 2 * kPi));

  // angDist
  assert(approxEq(angDist(0.0, 0.0), 0.0));                 // same angle
  assert(approxEq(angDist(kPi - 0.01, -kPi + 0.01), 0.02)); // across the seam
  assert(approxEq(angDist(0.0, kPi / 2), kPi / 2));         // quarter turn
  assert(approxEq(angDist(kPi / 2, 0.0), kPi / 2));         // symmetric
  assert(approxEq(angDist(0.0, kPi), kPi));                 // maximum distance
  assert(approxEq(angDist(0.0, 2 * kPi), 0.0)); // full turn = same angle
  assert(approxEq(angDist(-3 * kPi / 4, 3 * kPi / 4),
                  kPi / 2)); // seam, negative side

  std::puts("all tests passed");
  return 0;
}
