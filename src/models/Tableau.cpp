
#include "Tableau.hpp"

#include "Card.hpp"
#include "Deck.hpp"

namespace Models
{

Tableau::Tableau(Deck& deck) : deckM(deck)
{
}

Tableau::~Tableau()
{
}

Tableau::Tableau(const Tableau& otherTableau) : Pile(otherTableau),
   deckM(otherTableau.deckM)
{
}

Tableau& Tableau::operator=(const Tableau& otherTableau)
{
   deckM = otherTableau.deckM;
   return *this;
}

bool Tableau::isValidDestination(const Card& card) const
{
   bool validDest;
   if (0 != getNumCards())
   {
      Card topCard = getTopCard();
      validDest = ((not topCard.isSameColor(card)) and topCard.isOneAbove(card));
   }
   else
   {
      validDest = deckM.isTheHighestCardInTheSuit(card);
   }
   return validDest;
}

}
