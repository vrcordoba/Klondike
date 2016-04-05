
#include "Tableau.hpp"

#include "Card.hpp"
#include "Deck.hpp"

namespace Models
{

Tableau::Tableau(const Deck& deck) : deckM(deck)
{
}

Tableau::~Tableau()
{
}

bool Tableau::validDestination(const Card& card) const
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
