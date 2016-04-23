
#include "Pile.hpp"

#include <cassert>

namespace Models
{

Pile::Pile() : cardsM()
{
}

Pile::~Pile()
{
}

Pile::Pile(const Pile& otherPile) : cardsM(otherPile.cardsM)
{
}

Pile& Pile::operator=(const Pile& otherPile)
{
   cardsM = otherPile.cardsM;
   return *this;
}

void Pile::addCard(const Card& card)
{
   cardsM.push_back(card);
}

Card Pile::takeCard()
{
   assert(!cardsM.empty());
   const Card card = getTopCard();
   cardsM.pop_back();
   return card;
}

Card Pile::getTopCard() const
{
   assert(!cardsM.empty());
   return cardsM.back();
}

std::size_t Pile::getNumCards() const
{
   return cardsM.size();
}

std::deque<Card> Pile::getCards() const
{
   return cardsM;
}

void Pile::setCards(std::deque<Card>& cards)
{
   cardsM = cards;
}

Card Pile::getCardAt(std::uint8_t index) const
{
   assert(index < cardsM.size());
   return cardsM[index];
}

bool Pile::isValidDestination(const Card& card) const
{
   return false;
}

void Pile::setUpturnCards(std::uint8_t numCards, bool upturn)
{
   assert(numCards <= cardsM.size());
   std::deque<Card> cards;
   for (std::uint8_t i = 0; i < numCards; ++i)
   {
      Card card = takeCard();
      card.setUpturned(upturn);
      cards.push_back(card);
   }
   for (Card card : cards)
   {
      addCard(card);
   }
}

bool Pile::isTopCardUnturned() const
{
   return getTopCard().isUpturned();
}

}
