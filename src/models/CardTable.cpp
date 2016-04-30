
#include "CardTable.hpp"

#include <cstdint>
#include <cassert>
#include "Deck.hpp"
#include "Card.hpp"
#include "ClosedInterval.hpp"

namespace Models
{

CardTable::CardTable(Deck& deck, std::uint8_t numTableaus)
   : deckM(deck), wasteM(), tableausM(), foundationsM()
{
   if (0 != deckM.getNumCards())
      buildTableaus(numTableaus);
   else
      buildEmptyTableaus(numTableaus);
   buildFoundations();
}

CardTable::~CardTable()
{
}

bool CardTable::isGameWon() const
{
   for (std::vector<Foundation>::const_iterator it = foundationsM.begin();
      it != foundationsM.end(); ++it)
   {
      if (not it->isFoundationComplete())
      {
         return false;
      }
   }
   return true;
}

void CardTable::buildTableaus(std::uint8_t numTableaus)
{
   for (std::uint8_t i = 0; i < numTableaus; ++i)
   {
      Tableau tableau(deckM);
      for (std::uint8_t j = 0; j < i; ++j)
      {
         transferCard(deckM, tableau);
      }
      Card firstCardInTableau = deckM.takeCard();
      firstCardInTableau.setUpturned(true);
      tableau.appendCard(firstCardInTableau);
      tableausM.push_back(tableau);
   }
}

void CardTable::transferCard(Pile& originPile, Pile& destinationPile)
{
   destinationPile.appendCard(originPile.takeCard());
}

void CardTable::buildFoundations()
{
   for (std::uint8_t i = 0; i < deckM.getNumSuits(); ++i)
   {
      foundationsM.push_back(Foundation(deckM));
   }
}

void CardTable::buildEmptyTableaus(std::uint8_t numTableaus)
{
   for (std::uint8_t i = 0; i < numTableaus; ++i)
   {
      Tableau tableau(deckM);
      tableausM.push_back(tableau);
   }
}

Pile& CardTable::getDeck()
{
   return deckM;
}

Pile& CardTable::getWaste()
{
   return wasteM;
}

Pile& CardTable::getTableau(std::uint8_t tableauIndex)
{
   assert(Utils::ClosedInterval(tableausM.size() - 1).includes(tableauIndex));
   return tableausM[tableauIndex];
}

Pile& CardTable::getFoundation(std::uint8_t foundationIndex)
{
   assert(Utils::ClosedInterval(foundationsM.size() - 1).includes(foundationIndex));
   return foundationsM[foundationIndex];
}

std::uint8_t CardTable::getNumSuits() const
{
   return deckM.getNumSuits();
}

}
