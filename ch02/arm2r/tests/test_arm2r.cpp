#include "arm2r.hpp"
#include <cassert>
#include <cmath>
#include <cstdio>

using arm2r::angDist;
using arm2r::Config2R;
using arm2r::cspaceDist;
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
  assert(approxEq(angDist(0.0, 0.0), 0.0));
  assert(approxEq(angDist(kPi - 0.01, -kPi + 0.01), 0.02));
  assert(approxEq(angDist(0.0, kPi / 2), kPi / 2));
  assert(approxEq(angDist(kPi / 2, 0.0), kPi / 2));
  assert(approxEq(angDist(0.0, kPi), kPi));
  assert(approxEq(angDist(0.0, 2 * kPi), 0.0));
  assert(approxEq(angDist(-3 * kPi / 4, 3 * kPi / 4), kPi / 2));

  // cspaceDist
  assert(approxEq(cspaceDist(Config2R{0, 0}, Config2R{0, 0}), 0.0));
  assert(approxEq(cspaceDist(Config2R{0, 0}, Config2R{0.3, 0.4}), 0.5));
  assert(approxEq(cspaceDist(Config2R{0.3, 0.4}, Config2R{0, 0}), 0.5));
  assert(approxEq(cspaceDist(Config2R{kPi - 0.01, 0}, Config2R{-kPi + 0.01, 0}), 0.02));
  assert(approxEq(cspaceDist(Config2R{kPi - 0.01, kPi - 0.01}, Config2R{-kPi + 0.01, -kPi + 0.01}), 0.02 * std::sqrt(2.0)));

  std::puts("all tests passed");
  return 0;
}
