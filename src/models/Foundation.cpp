
#include "Foundation.hpp"

#include "Card.hpp"
#include "Deck.hpp"

namespace Models
{

Foundation::Foundation(const Deck& deck) : deckM(deck)
{
}

Foundation::~Foundation()
{
}

bool Foundation::validDestination(const Card& card) const
{
   bool validDest;
   if (0 != getNumCards())
   {
      Card topCard = getTopCard();
      validDest = (topCard.isSameSuit(card) and topCard.isOneBelow(card));
   }
   else
   {
      validDest = deckM.isTheLowestCardInTheSuit(card);
   }
   return validDest;
}

bool Foundation::isFoundationComplete() const
{
   return getNumCards() == deckM.getNumCardsPerSuit();
}

}
