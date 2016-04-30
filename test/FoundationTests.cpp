
#include "gtest/gtest.h"

#include "Suit.hpp"
#include "Card.hpp"
#include "Deck.hpp"
#include "FrenchDeck.hpp"
#include "Foundation.hpp"

TEST(FoundationTests, validDestination)
{
   Models::Card card1(0, Models::Suit(1, 1));
   Models::Card card2(1, Models::Suit(2, 1));
   Models::Card card3(1, Models::Suit(1, 1));
   Models::FrenchDeck deck;
   Models::Foundation foundation(deck);
   foundation.appendCard(card1);
   EXPECT_FALSE(foundation.isValidDestination(card2));
   EXPECT_TRUE(foundation.isValidDestination(card3));
}

TEST(FoundationTests, validDestinationEmptyFoundation)
{
   Models::Card card1(0, Models::Suit(1, 1));
   Models::Card card2(1, Models::Suit(1, 1));
   Models::FrenchDeck deck;
   Models::Foundation foundation(deck);
   EXPECT_TRUE(foundation.isValidDestination(card1));
   EXPECT_FALSE(foundation.isValidDestination(card2));
}

TEST(FoundationTests, isFoundationComplete)
{
   Models::FrenchDeck deck;
   Models::Foundation foundation(deck);
   for (std::uint8_t i = 0; i < 12; ++i)
   {
      foundation.appendCard(Models::Card(i, Models::Suit(3, 1)));
   }
   EXPECT_FALSE(foundation.isFoundationComplete());
   foundation.appendCard(Models::Card(12, Models::Suit(3, 1)));
   EXPECT_TRUE(foundation.isFoundationComplete());
}

int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
