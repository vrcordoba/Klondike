
#include "gtest/gtest.h"

#include "Deck.hpp"
#include "Card.hpp"

TEST(DeckTests, addCard)
{
   Models::Deck deck;
   deck.addCard(Utils::Card(1, 1));
   EXPECT_EQ(1, deck.getNumCards());
}

TEST(DeckTests, addSeveralCards)
{
   Models::Deck deck;
   deck.addCard(Utils::Card(1, 4));
   deck.addCard(Utils::Card(2, 3));
   deck.addCard(Utils::Card(3, 2));
   deck.addCard(Utils::Card(4, 1));
   EXPECT_EQ(4, deck.getNumCards());
}

TEST(DeckTests, addAndTakeCard)
{
   Models::Deck deck;
   Utils::Card card(1, 4);
   deck.addCard(card);
   EXPECT_EQ(card, deck.takeCard());
   EXPECT_EQ(0, deck.getNumCards());
}

TEST(DeckTests, addAndTakeSeveralCards)
{
   Models::Deck deck;
   deck.addCard(Utils::Card(1, 4));
   deck.addCard(Utils::Card(2, 3));
   deck.addCard(Utils::Card(3, 2));
   deck.addCard(Utils::Card(4, 1));
   EXPECT_EQ(Utils::Card(4, 1), deck.takeCard());
   EXPECT_EQ(3, deck.getNumCards());
   deck.addCard(Utils::Card(5, 5));
   EXPECT_EQ(4, deck.getNumCards());
   EXPECT_EQ(Utils::Card(5, 5), deck.takeCard());
   EXPECT_EQ(3, deck.getNumCards());
   EXPECT_EQ(Utils::Card(3, 2), deck.takeCard());
   EXPECT_EQ(2, deck.getNumCards());
   EXPECT_EQ(Utils::Card(2, 3), deck.takeCard());
   EXPECT_EQ(1, deck.getNumCards());
   EXPECT_EQ(Utils::Card(1, 4), deck.takeCard());
   EXPECT_EQ(0, deck.getNumCards());
}

TEST(DeckTests, shuffle)
{
   Models::Deck deck;
   deck.addCard(Utils::Card(1, 4));
   deck.addCard(Utils::Card(2, 3));
   deck.addCard(Utils::Card(3, 2));
   deck.addCard(Utils::Card(4, 1));
   deck.shuffle();
   EXPECT_EQ(4, deck.getNumCards());
   Utils::Card card = deck.takeCard();
   EXPECT_TRUE(Utils::Card(1, 4) == card or
      Utils::Card(2, 3) == card or
	  Utils::Card(3, 2) == card or
	  Utils::Card(4, 1) == card);
   card = deck.takeCard();
   EXPECT_TRUE(Utils::Card(1, 4) == card or
      Utils::Card(2, 3) == card or
      Utils::Card(3, 2) == card or
      Utils::Card(4, 1) == card);
   card = deck.takeCard();
   EXPECT_TRUE(Utils::Card(1, 4) == card or
      Utils::Card(2, 3) == card or
      Utils::Card(3, 2) == card or
      Utils::Card(4, 1) == card);
   card = deck.takeCard();
   EXPECT_TRUE(Utils::Card(1, 4) == card or
      Utils::Card(2, 3) == card or
      Utils::Card(3, 2) == card or
      Utils::Card(4, 1) == card);
}

int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
