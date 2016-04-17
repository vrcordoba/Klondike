#ifndef MODELS_GAME_HPP_
#define MODELS_GAME_HPP_

#include <cstdint>
#include "State.hpp"

namespace Models
{

class Pile;
class CardTable;

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

   std::uint8_t getNumCardsToDraw() const;

private:
   const std::uint8_t NUM_TABLEAUS = 7;
   const std::uint8_t NUM_PLAYERS = 1;
   const std::uint8_t NUM_CARDS_TO_DRAW = 3;
   State stateM;
   CardTable* cardTableM;
};

}

#endif
