
#include "gtest/gtest.h"

#include <cstdint>
#include <vector>
#include "Suit.hpp"
#include "Card.hpp"
#include "Pile.hpp"
#include "Deck.hpp"
#include "FrenchDeck.hpp"
#include "Foundation.hpp"
#include "CardTable.hpp"
#include "Game.hpp"

TEST(GameTests, setGetState)
{
   Models::FrenchDeck deck;
   deck.buildDeck();
   Models::Game game;
   Models::CardTable* cardTable = new Models::CardTable(deck, game.getNumTableaus());
   game.setCardTable(cardTable);
   EXPECT_TRUE(Models::State::INITIAL == game.getState());
   game.setState(Models::State::GAME);
   EXPECT_TRUE(Models::State::GAME == game.getState());
   game.setState(Models::State::END);
   EXPECT_TRUE(Models::State::END == game.getState());
}

TEST(GameTests, transferCards)
{
   Models::FrenchDeck deck;
   deck.buildDeck();
   Models::Game game;
   Models::CardTable* cardTable = new Models::CardTable(deck, game.getNumTableaus());
   game.setCardTable(cardTable);
   Models::Pile& deckFromGame = game.getDeck();
   Models::Pile waste = game.getWaste();
   std::uint8_t numCardsDeck = deckFromGame.getNumCards();
   std::uint8_t numCardsWaste = waste.getNumCards();
   EXPECT_TRUE(24 == numCardsDeck);
   EXPECT_TRUE(0 == numCardsWaste);
   for (std::uint8_t i = 0; i < 10; ++i)
   {
      game.transferCard(deckFromGame, waste);
   }
   numCardsDeck = deckFromGame.getNumCards();
   numCardsWaste = waste.getNumCards();
   EXPECT_TRUE(14 == numCardsDeck);
   EXPECT_TRUE(10 == numCardsWaste);
}

TEST (GameTests, isGameWon)
{
   Models::FrenchDeck deck;
   deck.buildDeck();
   Models::Game game;
   Models::CardTable* cardTable = new Models::CardTable(deck, game.getNumTableaus());
   game.setCardTable(cardTable);
   EXPECT_FALSE(game.isGameWon());
   std::vector<Models::Pile> piles;
   for (std::uint8_t i = 0; i < 4; ++i)
   {
      Models::Pile pile;
      for (std::int8_t j = 12; j >= 0; --j)
      {
         pile.appendCard(Models::Card(j, Models::Suit(i, i % 2)));
      }
      piles.push_back(pile);
   }
   for (std::uint8_t i = 0; i < piles.size(); ++i)
   {
      Models::Pile& foundation = game.getFoundation(i);
      while (0 != piles[i].getNumCards())
      {
         game.transferCard(piles[i], foundation);
      }
      if (3 != i)
      {
         EXPECT_FALSE(game.isGameWon());
      }
      else
      {
         EXPECT_TRUE(game.isGameWon());
      }
   }
}

int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
