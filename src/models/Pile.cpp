
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

Card Pile::getCardAt(std::uint8_t index) const
{
   assert(index < cardsM.size());
   return cardsM[index];
}

bool Pile::isValidDestination(const Card& card) const
{
   return false;
}

}
