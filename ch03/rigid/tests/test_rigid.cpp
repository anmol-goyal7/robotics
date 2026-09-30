#include <gtest/gtest.h>

#include <Eigen/Dense>

#include "rigid.hpp"

TEST(Scaffold, EigenIdentityTrace) {
  EXPECT_DOUBLE_EQ(Eigen::Matrix3d::Identity().trace(), 3.0);
}
