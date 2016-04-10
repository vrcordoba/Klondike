#ifndef CONTROLLERS_CARDTABLECONTROLLER_HPP_
#define CONTROLLERS_CARDTABLECONTROLLER_HPP_

#include <vector>
#include "DeckType.hpp"

namespace Models
{
   class Pile;
   class Deck;
}

namespace Controllers
{

class CardTableController
{
public:
   virtual ~CardTableController() {};
   virtual Models::DeckType::Name getDeckType() const = 0;
   virtual Models::Deck& getDeck() = 0;
   virtual Models::Pile& getWaste() = 0;
   virtual std::vector<Models::Pile> getTableaus() = 0;
   virtual std::vector<Models::Pile> getFoundations() = 0;
};

}

#endif
