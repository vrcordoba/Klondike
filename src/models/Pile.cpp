
#include "Pile.hpp"

#include <cassert>

namespace Models
{

Pile::Pile()
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
   const Card card = cardsM.back();
   cardsM.pop_back();
   return card;
}

std::size_t Pile::getNumCards() const
{
   return cardsM.size();
}

std::deque<Card> Pile::getCards() const
{
   return cardsM;
}

}
