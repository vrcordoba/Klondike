
#include "gtest/gtest.h"

#include "Deck.hpp"
#include "Card.hpp"
#include "SpanishCard.hpp"
#include <set>

TEST(DeckTests, addCard)
{
   Models::Deck deck;
   const Models::Card* card = new Models::SpanishCard(1, 1);
   deck.addCard(card);
   EXPECT_EQ(1, deck.getNumCards());
   delete card;
}

TEST(DeckTests, addSeveralCards)
{
   Models::Deck deck;
   const Models::Card* card1 = new Models::SpanishCard(1, 4);
   const Models::Card* card2 = new Models::SpanishCard(2, 3);
   const Models::Card* card3 = new Models::SpanishCard(3, 2);
   const Models::Card* card4 = new Models::SpanishCard(4, 1);
   deck.addCard(card1);
   deck.addCard(card2);
   deck.addCard(card3);
   deck.addCard(card4);
   EXPECT_EQ(4, deck.getNumCards());
   delete card1;
   delete card2;
   delete card3;
   delete card4;
}

TEST(DeckTests, addAndTakeCard)
{
   Models::Deck deck;
   const Models::Card* card = new Models::SpanishCard(1, 4);
   deck.addCard(card);
   EXPECT_EQ(card, deck.takeCard());
   EXPECT_EQ(0, deck.getNumCards());
   delete card;
}

TEST(DeckTests, addAndTakeSeveralCards)
{
   Models::Deck deck;
   const Models::Card* card1 = new Models::SpanishCard(1, 4);
   const Models::Card* card2 = new Models::SpanishCard(2, 3);
   const Models::Card* card3 = new Models::SpanishCard(3, 2);
   const Models::Card* card4 = new Models::SpanishCard(4, 1);
   const Models::Card* card5 = new Models::SpanishCard(5, 5);
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
   delete card1;
   delete card2;
   delete card3;
   delete card4;
   delete card5;
}

TEST(DeckTests, shuffle)
{
   Models::Deck deck;
   std::set<const Models::Card*> cards;
   const Models::Card* card1 = new Models::SpanishCard(1, 4);
   const Models::Card* card2 = new Models::SpanishCard(2, 3);
   const Models::Card* card3 = new Models::SpanishCard(3, 2);
   const Models::Card* card4 = new Models::SpanishCard(4, 1);
   deck.addCard(card1);
   deck.addCard(card2);
   deck.addCard(card3);
   deck.addCard(card4);
   cards.insert(card1);
   cards.insert(card2);
   cards.insert(card3);
   cards.insert(card4);
   deck.shuffle();
   EXPECT_EQ(4, deck.getNumCards());
   size_t initialSize = cards.size();
   for (unsigned i = 0; i < initialSize; ++i)
   {
	   const Models::Card* card = deck.takeCard();
	   std::set<const Models::Card*>::iterator cardsIt = cards.find(card);
	   EXPECT_TRUE(cardsIt != cards.end());
	   delete *cardsIt;
	   cards.erase(cardsIt);
	   deck.shuffle();
   }
}

int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
