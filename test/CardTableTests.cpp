
#include "gtest/gtest.h"

#include <cstdint>
#include <vector>
#include "Suit.hpp"
#include "Card.hpp"
#include "Pile.hpp"
#include "Deck.hpp"
#include "SpanishDeck.hpp"
#include "Foundation.hpp"
#include "CardTable.hpp"

TEST(CardTableTests, transferCard)
{
   Models::SpanishDeck deck;
   Models::CardTable cardTable(deck, 0);
   Models::Pile pile1, pile2;
   pile1.addCard(Models::Card(0, Models::Suit(0, 0)));
   pile1.addCard(Models::Card(1, Models::Suit(0, 0)));
   pile1.addCard(Models::Card(2, Models::Suit(0, 0)));
   pile1.addCard(Models::Card(3, Models::Suit(0, 0)));
   EXPECT_TRUE(4 == pile1.getNumCards());
   EXPECT_TRUE(0 == pile2.getNumCards());
   cardTable.transferCard(pile1, pile2);
   cardTable.transferCard(pile1, pile2);
   EXPECT_TRUE(2 == pile1.getNumCards());
   EXPECT_TRUE(2 == pile2.getNumCards());
   cardTable.transferCard(pile1, pile2);
   cardTable.transferCard(pile1, pile2);
   EXPECT_TRUE(0 == pile1.getNumCards());
   EXPECT_TRUE(4 == pile2.getNumCards());
}

TEST(CardTableTests, isGameWon)
{
   Models::SpanishDeck deck;
   deck.buildDeck();
   Models::CardTable cardTable(deck, 7);
   EXPECT_FALSE(cardTable.isGameWon());
   std::vector<Models::Pile> piles;
   for (std::uint8_t i = 0; i < 4; ++i)
   {
      Models::Pile pile;
      for (std::int8_t j = 9; j >= 0; --j)
      {
         pile.addCard(Models::Card(j, Models::Suit(i, i)));
      }
      piles.push_back(pile);
   }
   for (std::uint8_t i = 0; i < piles.size(); ++i)
   {
      Models::Foundation& foundation = cardTable.getFoundation(i);
      while (0 != piles[i].getNumCards())
      {
         cardTable.transferCard(piles[i], foundation);
      }
      if (3 != i)
      {
         EXPECT_FALSE(cardTable.isGameWon());
      }
      else
      {
         EXPECT_TRUE(cardTable.isGameWon());
      }
   }
}

int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}