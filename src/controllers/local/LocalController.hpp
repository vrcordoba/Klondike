#ifndef CONTROLLERS_LOCAL_LOCALCONTROLLER_HPP_
#define CONTROLLERS_LOCAL_LOCALCONTROLLER_HPP_

#include <cstdint>
#include "State.hpp"
#include "DeckType.hpp"

namespace Models
{
   class Game;
   class CardTable;
}

namespace Controllers
{

class LocalController
{
public:
   LocalController(Models::Game& game);
   virtual ~LocalController();

   LocalController(const LocalController&) = delete;
   LocalController& operator=(LocalController&) = delete;

   void setState(Models::State newState);

   std::uint8_t getNumPlayers() const;
   std::uint8_t getNumTableaus() const;

   Models::CardTable* getCardTable() const;
   void setCardTable(Models::CardTable* cardTable);

   Models::DeckType::Name getDeckType() const;
   void setDeckType(Models::DeckType::Name name);

private:
   Models::Game& gameM;
};

}

#endif
