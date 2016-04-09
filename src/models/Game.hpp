#ifndef MODELS_GAME_HPP_
#define MODELS_GAME_HPP_

#include <cstdint>
#include "State.hpp"
#include "CardTable.hpp"

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

   State getState() const;
   void setState(State newState);

   void setCardTable(CardTable* cardTable);

   void transferCard(Pile& originPile, Pile& destinationPile);
   bool isGameWon() const;

   Deck& getDeck();
   Pile& getWaste();
   Tableau& getTableau(std::uint8_t tableauIndex);
   Foundation& getFoundation(std::uint8_t foundationIndex);

private:
   State stateM;
   const std::uint8_t NUM_TABLEAUS = 7;
   CardTable* cardTableM;
};

}

#endif
