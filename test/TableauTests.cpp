
#include "gtest/gtest.h"

#include "Suit.hpp"
#include "Card.hpp"
#include "Deck.hpp"
#include "SpanishDeck.hpp"
#include "Tableau.hpp"

TEST(TableauTests, validDestination)
{
   Models::Card card1(9, Models::Suit(1, 1));
   Models::Card card2(7, Models::Suit(2, 2));
   Models::Card card3(8, Models::Suit(1, 1));
   Models::Card card4(8, Models::Suit(2, 2));
   Models::SpanishDeck deck;
   Models::Tableau tableau(deck);
   tableau.addCard(card1);
   EXPECT_FALSE(tableau.validDestination(card2));
   EXPECT_FALSE(tableau.validDestination(card3));
   EXPECT_TRUE(tableau.validDestination(card4));
}

TEST(TableauTests, validDestinationEmptyTableau)
{
   Models::Card card1(9, Models::Suit(1, 1));
   Models::Card card2(8, Models::Suit(1, 1));
   Models::SpanishDeck deck;
   Models::Tableau tableau(deck);
   EXPECT_TRUE(tableau.validDestination(card1));
   EXPECT_FALSE(tableau.validDestination(card2));
}

int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
