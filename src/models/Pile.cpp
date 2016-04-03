
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
   assert(!cardsM.empty());
   return cardsM;
}

}
