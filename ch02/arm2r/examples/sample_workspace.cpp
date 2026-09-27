#include "arm2r.hpp"

#include <cstdio>

int main() {
  const auto pts = arm2r::sampleWorkspace(2.0, 1.0, 100);
  std::printf("x,y\n");
  for (const auto &p : pts) {
    std::printf("%.17g,%.17g\n", p.x, p.y);
  }
  return 0;
}
