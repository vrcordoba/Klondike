
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

void Deck::addCard(const Utils::Card& card)
{
   cardsM.push_back(card);
}

Utils::Card Deck::takeCard()
{
   assert(!cardsM.empty());
   Utils::Card card = cardsM.back();
   cardsM.pop_back();
   return card;
}

std::size_t Deck::getNumCards() const
{
   return cardsM.size();
}

}
