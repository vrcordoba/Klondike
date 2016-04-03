
#include "gtest/gtest.h"

#include "Suit.hpp"
#include "Card.hpp"

TEST(CardTests, equality)
{
   Models::Card card1(10, Models::Suit(1, 1));
   Models::Card card2(10, Models::Suit(1, 1));
   EXPECT_TRUE(card1 == card2);
}

TEST(CardTests, inequality)
{
   Models::Card card1(10, Models::Suit(1, 0));
   Models::Card card2(10, Models::Suit(1, 1));
   Models::Card card3(10, Models::Suit(0, 0));
   Models::Card card4(9, Models::Suit(1, 0));
   EXPECT_FALSE(card1 == card2);
   EXPECT_FALSE(card1 == card3);
   EXPECT_FALSE(card1 == card4);
}

TEST(CardTests, assignation)
{
   Models::Card card1(10, Models::Suit(1, 0));
   Models::Card card2(0, Models::Suit(0, 1));
   card2 = card1;
   EXPECT_TRUE(card1 == card2);
}

TEST(CardTests, upturned)
{
   Models::Card card1(10, Models::Suit(1, 0), true);
   Models::Card card2(10, Models::Suit(1, 0));
   EXPECT_TRUE(card1.isUpturned());
   EXPECT_FALSE(card2.isUpturned());
   card1.setUpturned(false);
   card2.setUpturned(true);
   EXPECT_FALSE(card1.isUpturned());
   EXPECT_TRUE(card2.isUpturned());
}

TEST(CardTests, sameColor)
{
   Models::Card card1(7, Models::Suit(1, 0));
   Models::Card card2(8, Models::Suit(2, 0));
   Models::Card card3(9, Models::Suit(3, 1));
   EXPECT_TRUE(card1.isSameColor(card2));
   EXPECT_FALSE(card1.isSameColor(card3));
}

TEST(CardTests, sameSuit)
{
   Models::Card card1(4, Models::Suit(2, 0));
   Models::Card card2(5, Models::Suit(2, 1));
   Models::Card card3(6, Models::Suit(3, 2));
   EXPECT_TRUE(card1.isSameSuit(card2));
   EXPECT_FALSE(card1.isSameSuit(card3));
}

TEST(CardTests, isOneAbove)
{
   Models::Card card1(12, Models::Suit(2, 0));
   Models::Card card2(11, Models::Suit(2, 1));
   Models::Card card3(10, Models::Suit(3, 2));
   EXPECT_TRUE(card1.isOneAbove(card2));
   EXPECT_FALSE(card1.isOneAbove(card3));
}

TEST(CardTests, isOneBelow)
{
   Models::Card card1(0, Models::Suit(2, 0));
   Models::Card card2(1, Models::Suit(2, 1));
   Models::Card card3(2, Models::Suit(3, 2));
   EXPECT_TRUE(card1.isOneBelow(card2));
   EXPECT_FALSE(card1.isOneBelow(card3));
}

int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
