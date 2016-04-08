
#include "Deck.hpp"

#include <algorithm>
#include <cassert>
#include <cstdint>
#include "Card.hpp"
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

Deck::Deck(const Deck& otherDeck) : TOTAL_NUM_CARDS(otherDeck.TOTAL_NUM_CARDS),
   NUM_CARDS_PER_SUIT(otherDeck.NUM_CARDS_PER_SUIT)
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

std::uint8_t Deck::getNumSuits() const
{
   return TOTAL_NUM_CARDS / NUM_CARDS_PER_SUIT;
}

}
