#ifndef MODELS_GAME_HPP_
#define MODELS_GAME_HPP_

#include <cstdint>
#include "State.hpp"
#include "CardTable.hpp"
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

   State getState() const;
   void setState(State newState);

   void setCardTable(CardTable* cardTable);

   void transferCard(Pile& originPile, Pile& destinationPile);
   bool isGameWon() const;

   Deck& getDeck() const;
   Pile& getWaste() const;
   Tableau& getTableau(std::uint8_t tableauIndex) const;
   Foundation& getFoundation(std::uint8_t foundationIndex) const;

   std::uint8_t getNumPlayers() const;

   void execute(const Movement& movement);

private:
   const std::uint8_t NUM_TABLEAUS = 7;
   const std::uint8_t NUM_PLAYERS = 1;
   State stateM;
   CardTable* cardTableM;
   MovementHistory historyM;
};

}

#endif
