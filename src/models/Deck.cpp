
#include "Deck.hpp"

#include <algorithm>
#include <cassert>
#include "Card.hpp"
#include "Suit.hpp"
#include "ClosedInterval.hpp"

namespace Models
{

Deck::Deck()
   : totalNumCardsM(0), numCardsPerSuitM(0)
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

void Deck::buildDeck(std::uint8_t numColours)
{
   for (std::uint8_t i = 0; i < getTotalNumCards(); ++i)
      appendCard(Card(i % getNumCardsPerSuit(), Suit(i / getNumCardsPerSuit(),
         (i / getNumCardsPerSuit()) % numColours)));
   shuffle();
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
