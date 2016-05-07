
#include "gtest/gtest.h"

#include "Suit.hpp"

TEST(SuitTests, sameSuit)
{
   Models::Suit suit1(0, 1);
   Models::Suit suit2(0, 0);
   EXPECT_TRUE(suit1.sameSuit(suit2));
}

TEST(SuitTests, differentSuit)
{
   Models::Suit suit1(0, 1);
   Models::Suit suit2(1, 1);
   EXPECT_FALSE(suit1.sameSuit(suit2));
}

TEST(SuitTests, sameColor)
{
   Models::Suit suit1(0, 1);
   Models::Suit suit2(1, 1);
   EXPECT_TRUE(suit1.sameColor(suit2));
}

TEST(SuitTests, differentColor)
{
   Models::Suit suit1(1, 0);
   Models::Suit suit2(1, 1);
   EXPECT_FALSE(suit1.sameColor(suit2));
}

TEST(SuitTests, equality)
{
   Models::Suit suit1(0, 1);
   Models::Suit suit2(0, 1);
   EXPECT_TRUE(suit1 == suit2);
}

TEST(SuitTests, inequality)
{
   Models::Suit suit1(0, 1);
   Models::Suit suit2(0, 0);
   Models::Suit suit3(1, 1);
   EXPECT_FALSE(suit1 == suit2);
   EXPECT_FALSE(suit1 == suit3);
}
