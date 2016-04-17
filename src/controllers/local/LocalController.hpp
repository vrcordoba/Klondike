#ifndef CONTROLLERS_LOCAL_LOCALCONTROLLER_HPP_
#define CONTROLLERS_LOCAL_LOCALCONTROLLER_HPP_

#include <cstdint>
#include <limits>
#include "State.hpp"

namespace Models
{
class Game;
class CardTable;
class Pile;
}

namespace Controllers
{

class LocalController
{
public:
   explicit LocalController(Models::Game& game);
   virtual ~LocalController();

   LocalController(const LocalController&) = delete;
   LocalController& operator=(LocalController&) = delete;

   void initializeGame(
      std::uint8_t typeDeck = std::numeric_limits<std::uint8_t>::max());

   void setState(Models::State newState);

   std::uint8_t getNumPlayers() const;
   std::uint8_t getNumTableaus() const;
   std::uint8_t getNumFoundations() const;
   std::uint8_t getNumCardsToDraw() const;

   Models::CardTable* getCardTable() const;

   Models::Pile* getDeck() const;
   Models::Pile* getWaste() const;
   Models::Pile* getTableau(std::uint8_t tableauIndex) const;
   Models::Pile* getFoundation(std::uint8_t foundationIndex) const;

   void transferCard(Models::Pile& originPile, Models::Pile& destinationPile);

   bool isGameWon() const;

private:
   Models::Game& gameM;
};

}

#endif
