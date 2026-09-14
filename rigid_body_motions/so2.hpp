#include <cmath>

class SO2 {
public:
  static SO2 fromAngle(double theta);
  static SO2 indentity();

  SO2 operator*(const SO2 &rhs) const;
  Vec2 operator*(const Vec2 &v) const;
  SO2 inverse() const;

  double angle() const;

  friend double angleBetween(const SO2 &a, const SO2 &b);
  friend SO2 slerp(const SO2 &a, const SO2 &b, double t);
  friend bool approx(const SO2 &a, const SO2 &b, double eps = 1e-9);

private:
  explicit SO2(double c, double s) : c_(c), s_(s) {}
  double c_, s_;
};
