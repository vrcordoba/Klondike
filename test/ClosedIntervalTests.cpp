
#include "gtest/gtest.h"

#include "ClosedInterval.hpp"

TEST(ClosedIntervalTests, innerValue)
{
   Utils::ClosedInterval interval(-128, 127);
   EXPECT_TRUE(interval.includes(67));
}

TEST(ClosedIntervalTests, outerValue)
{
   Utils::ClosedInterval interval(-128, 66);
   EXPECT_FALSE(interval.includes(67));
}

TEST(ClosedIntervalTests, inTheMinEdge)
{
   Utils::ClosedInterval interval(56, 12456789);
   EXPECT_TRUE(interval.includes(56));
}

TEST(ClosedIntervalTests, inTheMaxEdge)
{
   Utils::ClosedInterval interval(-1283245, 2354435426);
   EXPECT_TRUE(interval.includes(2354435426));
}

TEST(ClosedIntervalTests, OneParameterConstructor)
{
   Utils::ClosedInterval interval(2354435426);
   EXPECT_TRUE(interval.includes(0));
   EXPECT_TRUE(interval.includes(128));
   EXPECT_TRUE(interval.includes(2354435426));
   EXPECT_FALSE(interval.includes(-1));
}

int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
