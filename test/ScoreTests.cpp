
#include "gtest/gtest.h"

#include "Score.hpp"
#include "PileType.hpp"

TEST(ScoreTests, initialValue)
{
   Models::Score score;
   EXPECT_TRUE(0 == score.getScore());
}

int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
