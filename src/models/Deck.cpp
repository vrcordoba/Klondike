
#include "Deck.hpp"

#include "Card.hpp"
#include <cstdint>
#include <algorithm>
#include <cassert>
#include "ClosedInterval.hpp"

namespace Models
{

Deck::Deck(std::uint8_t numCards, std::uint8_t numCardsPerSuit)
   : TOTAL_NUM_CARDS(numCards), NUM_CARDS_PER_SUIT(numCardsPerSuit)
{
}

Deck::~Deck()
{
}

void Deck::shuffle()
{
	std::random_device rd;
	std::mt19937 g(rd());
	std::deque<Card> cards = getCards();
	std::shuffle(cards.begin(), cards.end(), g);
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
   return NUM_CARDS_PER_SUIT;
}

std::uint8_t Deck::getTotalNumCards() const
{
   return TOTAL_NUM_CARDS;
}

}
