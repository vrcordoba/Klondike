
#include "Deck.hpp"

#include "Card.hpp"
#include <algorithm>

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
	std::deque<Card> cards = getCards();
	std::shuffle(cards.begin(), cards.end(), g);
}

}
