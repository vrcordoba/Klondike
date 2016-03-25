
#include "Deck.hpp"

#include <algorithm>
#include <cassert>

namespace Models
{

Deck::Deck()
{
}

Deck::~Deck()
{
}

void Deck::shuffle()
{
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(cardsM.begin(), cardsM.end(), g);
}

void Deck::addCard(const Card* const card)
{
   cardsM.push_back(card);
}

const Card* Deck::takeCard()
{
   assert(!cardsM.empty());
   const Card* card = cardsM.back();
   cardsM.pop_back();
   return card;
}

std::size_t Deck::getNumCards() const
{
   return cardsM.size();
}

}
