#ifndef CONTROLLERS_CARDTABLECONTROLLER_HPP_
#define CONTROLLERS_CARDTABLECONTROLLER_HPP_

#include <cstdint>
#include <vector>
#include "DeckType.hpp"
#include "FacadeCard.hpp"

namespace Controllers
{

class CardTableController
{
public:
   virtual ~CardTableController() {};
   virtual Models::DeckType::Name getDeckType() const = 0;
   virtual std::vector<FacadeCard> getDeck() = 0;
   virtual std::vector<FacadeCard> getWaste() = 0;
   virtual std::vector<FacadeCard> getTableau(std::uint8_t i) = 0;
   virtual std::vector<FacadeCard> getFoundation(std::uint8_t i) = 0;
   virtual std::uint8_t getNumTableaus() const = 0;
   virtual std::uint8_t getNumFoundations() const = 0;
};

}

#endif
