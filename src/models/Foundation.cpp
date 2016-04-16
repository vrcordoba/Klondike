
#include "Foundation.hpp"

#include "Card.hpp"
#include "Deck.hpp"

namespace Models
{

Foundation::Foundation(Deck& deck) : deckM(deck)
{
}

Foundation::~Foundation()
{
}

Foundation::Foundation(const Foundation& otherFoundation) : Pile(otherFoundation),
   deckM(otherFoundation.deckM)
{
}

Foundation& Foundation::operator=(const Foundation& otherFoundation)
{
   deckM = otherFoundation.deckM;
   return *this;
}

bool Foundation::isValidDestination(const Card& card) const
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
