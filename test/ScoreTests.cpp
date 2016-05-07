
#include "gtest/gtest.h"

#include "Score.hpp"
#include "PileType.hpp"

TEST(ScoreTests, initialValue)
{
   Models::Score score;
   EXPECT_TRUE(0 == score.getScore());
}

TEST(ScoreTests, movementScore)
{
   Models::Score score;
   score.movementScore(2, 3, 1, false); // Foundation -> Tableau
   EXPECT_TRUE(0 == score.getScore());
   score.movementScore(3, 2, 1, false); // Tableau -> Foundation
   EXPECT_TRUE(10 == score.getScore());
   score.movementScore(3, 2, 1, false); // Tableau -> Foundation
   EXPECT_TRUE(20 == score.getScore());
   score.movementScore(2, 3, 1, false); // Foundation -> Tableau
   EXPECT_TRUE(5 == score.getScore());
   score.movementScore(1, 2, 1, false); // Waste -> Foundation
   EXPECT_TRUE(15 == score.getScore());
   score.movementScore(1, 3, 1, false); // Waste -> Tableau
   EXPECT_TRUE(20 == score.getScore());
}

TEST(ScoreTests, recycleScore)
{
   Models::Score score;
   score.movementScore(3, 2, 1, false); // Tableau -> Foundation
   score.movementScore(3, 2, 1, false); // Tableau -> Foundation
   score.movementScore(3, 2, 1, false); // Tableau -> Foundation
   score.movementScore(3, 2, 2, false); // Tableau -> Foundation
   EXPECT_TRUE(50 == score.getScore());
   score.rebootScore();
   EXPECT_TRUE(0 == score.getScore());
}
