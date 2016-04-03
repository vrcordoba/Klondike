
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

bool Foundation::validTarget(const Card& card) const
{
   if (0 != getNumCards())
   {
      Card topCard = getTopCard();
      return (topCard.isSameSuit(card) and topCard.isOneBelow(card));
   }
   else
   {
      return deckM.isTheLowestCardInTheSuit(card);
   }
}

bool Foundation::isFoundationComplete() const
{
   return getNumCards() == deckM.getNumCardsPerSuit();
}

}
