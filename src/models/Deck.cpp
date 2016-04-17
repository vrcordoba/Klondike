
#include "Deck.hpp"

#include <algorithm>
#include <cassert>
#include "Card.hpp"
#include "ClosedInterval.hpp"

namespace Models
{

Deck::Deck(std::uint8_t numCards, std::uint8_t numCardsPerSuit)
   : totalNumCardsM(numCards), numCardsPerSuitM(numCardsPerSuit)
{
}

Deck::~Deck()
{
}

Deck::Deck(const Deck& otherDeck) : totalNumCardsM(otherDeck.totalNumCardsM),
   numCardsPerSuitM(otherDeck.numCardsPerSuitM)
{
}

Deck& Deck::operator=(const Deck& otherDeck)
{
   totalNumCardsM = otherDeck.totalNumCardsM;
   numCardsPerSuitM = otherDeck.numCardsPerSuitM;
   return *this;
}

void Deck::shuffle()
{
	std::random_device rd;
	std::mt19937 g(rd());
	std::deque<Card> cards = getCards();
	std::shuffle(cards.begin(), cards.end(), g);
	setCards(cards);
}

bool Deck::isTheLowestCardInTheSuit(const Card& card) const
{
   assert(Utils::ClosedInterval(LOWEST_CARD_IN_THE_SUIT,
      getNumCardsPerSuit() - 1).includes(card.getNumber()));
   return LOWEST_CARD_IN_THE_SUIT == card.getNumber();
}

bool Deck::isTheHighestCardInTheSuit(const Card& card) const
{
   assert(Utils::ClosedInterval(LOWEST_CARD_IN_THE_SUIT,
      getNumCardsPerSuit() - 1).includes(card.getNumber()));
   return (getNumCardsPerSuit() - 1) == card.getNumber();
}

std::uint8_t Deck::getNumCardsPerSuit() const
{
   return numCardsPerSuitM;
}

std::uint8_t Deck::getTotalNumCards() const
{
   return totalNumCardsM;
}

std::uint8_t Deck::getNumSuits() const
{
   return totalNumCardsM / numCardsPerSuitM;
}

}
