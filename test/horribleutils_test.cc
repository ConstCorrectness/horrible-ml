#include "horribleutils.hpp"

#include <gtest/gtest.h>

TEST(HorribleUtilsTest, size) {
  constexpr auto first_arg = horrible::utils::integer_sequence<int, 0, 1, 2, 3, 4>::size();
  constexpr auto second_arg = 5;

  // EXPECT_EQ macro expansion makes integer_sequence<int, 0, ...> improper
  EXPECT_EQ(first_arg, second_arg);
}


TEST(HorribleUtilsTest, index_sequence) {
  constexpr auto first_arg = horrible::utils::index_sequence<0, 1, 2, 3, 4>::size();
  constexpr auto second_arg = 5;

  EXPECT_EQ(first_arg, second_arg);
}