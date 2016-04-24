#ifndef MODELS_GAME_HPP_
#define MODELS_GAME_HPP_

#include <cstdint>
#include "DeckPrototyper.hpp"
#include "State.hpp"
#include "Score.hpp"

namespace Models
{

class Pile;
class CardTable;

class Game final
{
public:
   Game();
   ~Game();

   Game(const Game&) = delete;
   Game& operator=(const Game&) = delete;

   void initializeGame(Configuration::DeckType::Type typeDeck);

   std::uint8_t getNumTableaus() const;
   std::uint8_t getNumFoundations() const;

   State getState() const;
   void setState(State newState);

   CardTable* getCardTable() const;
   void setCardTable(CardTable* cardTable);

   void transferCard(Pile& originPile, Pile& destinationPile);
   bool isGameWon() const;

   Pile& getDeck() const;
   Pile& getWaste() const;
   Pile& getTableau(std::uint8_t tableauIndex) const;
   Pile& getFoundation(std::uint8_t foundationIndex) const;

   std::uint8_t getNumPlayers() const;

   std::uint8_t getNumCardsToDraw() const;

   Score& getScore();

private:
   const std::uint8_t NUM_TABLEAUS = 7;
   const std::uint8_t NUM_PLAYERS = 1;
   const std::uint8_t NUM_CARDS_TO_DRAW = 3;
   State stateM;
   DeckPrototyper deckPrototyperM;
   CardTable* cardTableM;
   Score scoreM;
};

}

#endif
