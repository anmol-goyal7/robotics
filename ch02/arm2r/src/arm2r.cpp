#include "arm2r.hpp"
#include <cmath>
#include <vector>

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

Vec2 fk2R(const Config2R &q, double L1, double L2) {
  double x = L1 * std::cos(q.th1) + L2 * std::cos(q.th1 + q.th2);
  double y = L1 * std::sin(q.th1) + L2 * std::sin(q.th1 + q.th2);
  return Vec2{x, y};
}

std::vector<Vec2> sampleWorkspace(double L1, double L2, int n) {
  std::vector<Vec2> pts;
  pts.reserve(n * n);

  double step = 2 * kPi / n;

  for (int i = 0; i < n; i++) {
    double th1 = -kPi + i * step;
    for (int j = 0; j < n; j++) {
      double th2 = -kPi + j * step;
      pts.push_back(fk2R(Config2R{th1, th2}, L1, L2));
    }
  }
  return pts;
}
} // namespace arm2r
