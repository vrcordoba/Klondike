
#include "gtest/gtest.h"

#include "Suit.hpp"
#include "Card.hpp"
#include "Pile.hpp"
#include "Deck.hpp"
#include "FrenchDeck.hpp"
#include "SpanishDeck.hpp"
#include <vector>

TEST(DeckTests, addCard)
{
   Models::Deck* deck = new Models::FrenchDeck();
   deck->addCard(Models::Card(0, Models::Suit(0, 1), true));
   EXPECT_EQ(1, deck->getNumCards());
   delete deck;
}

TEST(DeckTests, addSeveralCards)
{
   Models::Deck* deck = new Models::FrenchDeck();
   deck->addCard(Models::Card(0, Models::Suit(0, 1), true));
   deck->addCard(Models::Card(1, Models::Suit(1, 0), true));
   deck->addCard(Models::Card(2, Models::Suit(2, 1), true));
   deck->addCard(Models::Card(3, Models::Suit(3, 0), true));
   EXPECT_EQ(4, deck->getNumCards());
   delete deck;
}

TEST(DeckTests, addAndTakeCard)
{
   Models::Deck* deck = new Models::FrenchDeck();
   Models::Card card(0, Models::Suit(0, 1), true);
   deck->addCard(card);
   EXPECT_EQ(card, deck->takeCard());
   EXPECT_EQ(0, deck->getNumCards());
   delete deck;
}

TEST(DeckTests, addAndTakeSeveralCards)
{
   Models::Deck* deck = new Models::FrenchDeck();
   Models::Card card1(0, Models::Suit(0, 1), true);
   Models::Card card2(1, Models::Suit(0, 0), true);
   Models::Card card3(2, Models::Suit(0, 1), true);
   Models::Card card4(3, Models::Suit(0, 0), true);
   Models::Card card5(4, Models::Suit(0, 1), true);
   deck->addCard(card1);
   deck->addCard(card2);
   deck->addCard(card3);
   deck->addCard(card4);
   EXPECT_EQ(card4, deck->takeCard());
   EXPECT_EQ(3, deck->getNumCards());
   deck->addCard(card5);
   EXPECT_EQ(4, deck->getNumCards());
   EXPECT_EQ(card5, deck->takeCard());
   EXPECT_EQ(3, deck->getNumCards());
   EXPECT_EQ(card3, deck->takeCard());
   EXPECT_EQ(2, deck->getNumCards());
   EXPECT_EQ(card2, deck->takeCard());
   EXPECT_EQ(1, deck->getNumCards());
   EXPECT_EQ(card1, deck->takeCard());
   EXPECT_EQ(0, deck->getNumCards());
   delete deck;
}

TEST(DeckTests, shuffle)
{
   Models::Deck* deck = new Models::FrenchDeck();
   std::vector<Models::Card> cards;
   Models::Card card1(0, Models::Suit(0, 1), true);
   Models::Card card2(1, Models::Suit(1, 0), true);
   Models::Card card3(2, Models::Suit(2, 1), true);
   Models::Card card4(3, Models::Suit(3, 0), true);
   deck->addCard(card1);
   deck->addCard(card2);
   deck->addCard(card3);
   deck->addCard(card4);
   cards.push_back(card1);
   cards.push_back(card2);
   cards.push_back(card3);
   cards.push_back(card4);
   deck->shuffle();
   EXPECT_EQ(4, deck->getNumCards());
   size_t initialSize = cards.size();
   for (unsigned i = 0; i < initialSize; ++i)
   {
	   Models::Card card = deck->takeCard();
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
   delete deck;
}

TEST(DeckTest, SpanishDeck)
{
   Models::Deck* deck = new Models::SpanishDeck();
   deck->buildDeck();
   std::uint8_t totalNumCards = deck->getTotalNumCards();
   EXPECT_TRUE(40 == totalNumCards);
   std::uint8_t numCardsPerSuit = deck->getNumCardsPerSuit();
   EXPECT_TRUE(10 == numCardsPerSuit);
   for (std::int8_t i = 3; i >= 0; --i)
   {
      for (std::int8_t j = 9; j >= 0; --j)
      {
         Models::Card card(j, Models::Suit(i, i));
         EXPECT_TRUE(card == deck->takeCard());
      }
   }
   delete deck;
}

TEST(DeckTest, FrenchDeck)
{
   Models::Deck* deck = new Models::FrenchDeck();
   deck->buildDeck();
   std::uint8_t totalNumCards = deck->getTotalNumCards();
   EXPECT_TRUE(52 == totalNumCards);
   std::uint8_t numCardsPerSuit = deck->getNumCardsPerSuit();
   EXPECT_TRUE(13 == numCardsPerSuit);
   for (std::int8_t i = 3; i >= 0; --i)
   {
      for (std::int8_t j = 12; j >= 0; --j)
      {
         Models::Card card(j, Models::Suit(i, i % 2));
         EXPECT_TRUE(card == deck->takeCard());
      }
   }
   delete deck;
}

TEST(DeckTest, isTheLowestCardInTheSuit)
{
   Models::Deck* deck = new Models::FrenchDeck();
   Models::Card card1(0, Models::Suit(0, 0));
   Models::Card card2(1, Models::Suit(0, 0));
   EXPECT_TRUE(deck->isTheLowestCardInTheSuit(card1));
   EXPECT_FALSE(deck->isTheLowestCardInTheSuit(card2));
   delete deck;
}

TEST(DeckTest, isTheHighestCardInTheSuit)
{
   Models::Deck* spanishDeck = new Models::SpanishDeck();
   Models::Deck* frenchDeck = new Models::FrenchDeck();
   Models::Card card1(9, Models::Suit(0, 0));
   Models::Card card2(12, Models::Suit(0, 0));
   EXPECT_TRUE(spanishDeck->isTheHighestCardInTheSuit(card1));
   EXPECT_FALSE(frenchDeck->isTheHighestCardInTheSuit(card1));
   EXPECT_TRUE(frenchDeck->isTheHighestCardInTheSuit(card2));
   delete frenchDeck;
   delete spanishDeck;
}

int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
