#ifndef CONTROLLERS_LOCAL_LOCALCONTROLLER_HPP_
#define CONTROLLERS_LOCAL_LOCALCONTROLLER_HPP_

#include <cstdint>
#include "State.hpp"
#include "DeckType.hpp"

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

   void setState(Models::State newState);

   std::uint8_t getNumPlayers() const;
   std::uint8_t getNumTableaus() const;
   std::uint8_t getNumFoundations() const;

   Models::CardTable* getCardTable() const;
   void setCardTable(Models::CardTable* cardTable);

   Models::DeckType::Name getDeckType() const;
   void setDeckType(Models::DeckType::Name name);

   Models::Pile* getDeck() const;
   Models::Pile* getWaste() const;
   Models::Pile* getTableau(std::uint8_t tableauIndex) const;
   Models::Pile* getFoundation(std::uint8_t foundationIndex) const;

   void transferCard(Models::Pile& originPile, Models::Pile& destinationPile);

private:
   Models::Game& gameM;
};

}

#endif
