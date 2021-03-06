
#include "gtest/gtest.h"

#include <vector>
#include <cstdint>
#include "Suit.hpp"
#include "Card.hpp"
#include "Pile.hpp"
#include "Deck.hpp"
#include "FrenchDeck.hpp"
#include "SpanishDeck.hpp"

TEST(DeckTests, addCard)
{
   Models::Deck* deck = new Models::FrenchDeck();
   deck->appendCard(Models::Card(0, Models::Suit(0, 1), true));
   EXPECT_EQ(1, deck->getNumCards());
   delete deck;
}

TEST(DeckTests, addSeveralCards)
{
   Models::Deck* deck = new Models::FrenchDeck();
   deck->appendCard(Models::Card(0, Models::Suit(0, 1), true));
   deck->appendCard(Models::Card(1, Models::Suit(1, 0), true));
   deck->appendCard(Models::Card(2, Models::Suit(2, 1), true));
   deck->appendCard(Models::Card(3, Models::Suit(3, 0), true));
   EXPECT_EQ(4, deck->getNumCards());
   delete deck;
}

TEST(DeckTests, addAndTakeCard)
{
   Models::Deck* deck = new Models::FrenchDeck();
   Models::Card card(0, Models::Suit(0, 1), true);
   deck->appendCard(card);
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
   deck->appendCard(card1);
   deck->appendCard(card2);
   deck->appendCard(card3);
   deck->appendCard(card4);
   EXPECT_EQ(card4, deck->takeCard());
   EXPECT_EQ(3, deck->getNumCards());
   deck->appendCard(card5);
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
   deck->appendCard(card1);
   deck->appendCard(card2);
   deck->appendCard(card3);
   deck->appendCard(card4);
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

TEST(DeckTests, SpanishDeck)
{
   Models::Deck* deck = new Models::SpanishDeck();
   deck->buildDeck();
   std::uint8_t totalNumCards = deck->getTotalNumCards();
   EXPECT_TRUE(40 == totalNumCards);
   std::uint8_t numCardsPerSuit = deck->getNumCardsPerSuit();
   EXPECT_TRUE(10 == numCardsPerSuit);
   std::uint8_t numSuits = deck->getNumSuits();
   EXPECT_TRUE(4 == numSuits);
   delete deck;
}

TEST(DeckTests, FrenchDeck)
{
   Models::Deck* deck = new Models::FrenchDeck();
   deck->buildDeck();
   std::uint8_t totalNumCards = deck->getTotalNumCards();
   EXPECT_TRUE(52 == totalNumCards);
   std::uint8_t numCardsPerSuit = deck->getNumCardsPerSuit();
   EXPECT_TRUE(13 == numCardsPerSuit);
   std::uint8_t numSuits = deck->getNumSuits();
   EXPECT_TRUE(4 == numSuits);
   delete deck;
}

TEST(DeckTests, isTheLowestCardInTheSuit)
{
   Models::Deck* deck = new Models::FrenchDeck();
   Models::Card card1(0, Models::Suit(0, 0));
   Models::Card card2(1, Models::Suit(0, 0));
   EXPECT_TRUE(deck->isTheLowestCardInTheSuit(card1));
   EXPECT_FALSE(deck->isTheLowestCardInTheSuit(card2));
   delete deck;
}

TEST(DeckTests, isTheHighestCardInTheSuit)
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
