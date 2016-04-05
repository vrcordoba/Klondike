
#include "CardTable.hpp"

#include <cstdint>

namespace Models
{

CardTable::CardTable(const Deck& deck, std::uint8_t numTableaus)
   : deckM(deck), wasteM(), tableausM(), foundationsM()
{
   buildTableaus(numTableaus);
}

CardTable::~CardTable()
{
}

void CardTable::buildTableaus(std::uint8_t numTableaus)
{
   for (std::uint8_t i = 0; i < numTableaus; ++i)
   {
   }
}

}
