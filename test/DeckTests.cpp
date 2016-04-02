
#include "gtest/gtest.h"

#include "Suit.hpp"
#include "Card.hpp"
#include "Pile.hpp"
#include "Deck.hpp"
#include <vector>

TEST(DeckTests, addCard)
{
   Models::Deck deck;
   deck.addCard(Models::Card(0, Models::Suit(0, 1), true));
   EXPECT_EQ(1, deck.getNumCards());
}

TEST(DeckTests, addSeveralCards)
{
   Models::Deck deck;
   deck.addCard(Models::Card(0, Models::Suit(0, 1), true));
   deck.addCard(Models::Card(1, Models::Suit(1, 0), true));
   deck.addCard(Models::Card(2, Models::Suit(2, 1), true));
   deck.addCard(Models::Card(3, Models::Suit(3, 0), true));
   EXPECT_EQ(4, deck.getNumCards());
}

TEST(DeckTests, addAndTakeCard)
{
   Models::Deck deck;
   Models::Card card(0, Models::Suit(0, 1), true);
   deck.addCard(card);
   EXPECT_EQ(card, deck.takeCard());
   EXPECT_EQ(0, deck.getNumCards());
}

TEST(DeckTests, addAndTakeSeveralCards)
{
   Models::Deck deck;
   Models::Card card1(0, Models::Suit(0, 1), true);
   Models::Card card2(1, Models::Suit(0, 0), true);
   Models::Card card3(2, Models::Suit(0, 1), true);
   Models::Card card4(3, Models::Suit(0, 0), true);
   Models::Card card5(4, Models::Suit(0, 1), true);
   deck.addCard(card1);
   deck.addCard(card2);
   deck.addCard(card3);
   deck.addCard(card4);
   EXPECT_EQ(card4, deck.takeCard());
   EXPECT_EQ(3, deck.getNumCards());
   deck.addCard(card5);
   EXPECT_EQ(4, deck.getNumCards());
   EXPECT_EQ(card5, deck.takeCard());
   EXPECT_EQ(3, deck.getNumCards());
   EXPECT_EQ(card3, deck.takeCard());
   EXPECT_EQ(2, deck.getNumCards());
   EXPECT_EQ(card2, deck.takeCard());
   EXPECT_EQ(1, deck.getNumCards());
   EXPECT_EQ(card1, deck.takeCard());
   EXPECT_EQ(0, deck.getNumCards());
}

TEST(DeckTests, shuffle)
{
   Models::Deck deck;
   std::vector<Models::Card> cards;
   Models::Card card1(0, Models::Suit(0, 1), true);
   Models::Card card2(1, Models::Suit(1, 0), true);
   Models::Card card3(2, Models::Suit(2, 1), true);
   Models::Card card4(3, Models::Suit(3, 0), true);
   deck.addCard(card1);
   deck.addCard(card2);
   deck.addCard(card3);
   deck.addCard(card4);
   cards.push_back(card1);
   cards.push_back(card2);
   cards.push_back(card3);
   cards.push_back(card4);
   deck.shuffle();
   EXPECT_EQ(4, deck.getNumCards());
   size_t initialSize = cards.size();
   for (unsigned i = 0; i < initialSize; ++i)
   {
	   Models::Card card = deck.takeCard();
	   std::vector<Models::Card>::iterator cardsIt = cards.begin();
	   for (; cardsIt != cards.end(); ++ cardsIt)
	   {
	      if (*cardsIt == card)
	      {
	         break;
	      }
	   }
      EXPECT_TRUE(cardsIt != cards.end());
      cards.erase(cardsIt);
   }
}

int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
