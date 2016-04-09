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
   Game(Deck& deck);
   ~Game();

   State getState() const;
   void setState(State newState);

   void transferCard(Pile& originPile, Pile& destinationPile);

   bool isGameWon() const;

   Deck& getDeck();
   Pile& getWaste();
   Tableau& getTableau(std::uint8_t tableauIndex);
   Foundation& getFoundation(std::uint8_t foundationIndex);

private:
   State stateM;
   const std::uint8_t NUM_TABLEAUS = 7;
   CardTable cardTableM;
};

}

#endif
