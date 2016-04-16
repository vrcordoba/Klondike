#ifndef MODELS_GAME_HPP_
#define MODELS_GAME_HPP_

#include <cstdint>
#include "State.hpp"
#include "CardTable.hpp"
#include "DeckType.hpp"
#include "MovementHistory.hpp"

namespace Models
{

class Deck;
class Pile;
class Tableau;
class Foundation;

class Game final
{
public:
   Game();
   ~Game();

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

   DeckType::Name getDeckType() const;
   void setDeckType(DeckType::Name name);

   std::uint8_t getNumCardsToDraw() const;

private:
   const std::uint8_t NUM_TABLEAUS = 7;
   const std::uint8_t NUM_PLAYERS = 1;
   const std::uint8_t NUM_CARDS_TO_DRAW = 3;
   State stateM;
   CardTable* cardTableM;
   DeckType::Name deckTypeNameM;
};

}

#endif
